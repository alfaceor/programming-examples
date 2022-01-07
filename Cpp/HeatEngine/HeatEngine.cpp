#include <stdio.h>
#include <string>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_histogram.h>


using namespace std;

class Particle{
  public:
    double x;
    double v;
    double mass;
    double k;
    double force;
    double KT;

    double dt;
    double dt2;
    double gamma;
    double gammadt;
    double c0, c1, c2;

    // Random variables
    const gsl_rng_type *Trng1, *Trng2; 
    gsl_rng *r1, *r2;
    long unsigned int seed1;
    long unsigned int seed2;
    
    // Convinient variables.
    double *c;
    double sigma_r, sigma_r2;
    double sigma_v, sigma_v2;
    double corr_rv;
    double aux1;
    double aux2;
    
    // Ouput parameters.
    double drG; // \delta r^G
    double dvG; // \delta v^G

    double Ek;
    double Ep;
    double Et;

    Particle();
    ~Particle();

    void calcForce();
    void calcEk();
    void calcEp();
    void calcEt();
    
    void RunAdiabatic();
    void RunHeatBath();
    
    void savedata(FILE *ofile, double time);

};

Particle::Particle(){
  x       = 0.0;
  v       = 0.0;
  mass    = 1.0;
  k       = 1.0;
  KT      = 2.0;

  dt      = 0.01;
  dt2     = dt*dt;
  gamma   = 1.0;
  gammadt = gamma*dt;

  c0  = exp(-gammadt);
  c1  = (1 - c0)/(gammadt);
  c2  = (1 - c1)/(gammadt);
  printf("gammadt = %g, c0 = %g, c1 = %g, c2 = %g\n", gammadt, c0, c1, c2);

  sigma_v2  = (KT/mass)*(1.0 - c0*c1);
  sigma_r2  = dt2*(KT/mass)*( 2.0- (3.0 - 4.0*c0 + c0*c0 )/gammadt)/gammadt;

  sigma_v = sqrt(sigma_v2);
  sigma_r = sqrt(sigma_r2);
  corr_rv = dt*(KT/mass)*(1.0-c0)*(1.0-c0)/(sigma_r*sigma_v*gammadt);

  aux1 = sigma_v*corr_rv;
  aux2 = sigma_v*sqrt(1-corr_rv*corr_rv);

  Trng1 = gsl_rng_default;
  Trng2 = gsl_rng_default;
  
  r1 = gsl_rng_alloc(Trng1);
  r2 = gsl_rng_alloc(Trng2);
  //  seed = (long unsigned int) time(NULL);
  seed1 = 1234;
  seed2 = 4321;
  gsl_rng_set(r1, seed1);
  gsl_rng_set(r2, seed2);

}

Particle::~Particle(){
}

void Particle::calcForce(){
  force = -k*x;
}

void Particle::RunAdiabatic(){
  v = v + 0.5*force*dt;
  x = x + v*dt;
  calcForce();
  v = v + 0.5*force*dt;
}

void Particle::RunHeatBath(){
  double force_old = 0.0;
  double etha1=0.0, etha2=0.0;
  etha1 = gsl_ran_gaussian(r1, 1);
  etha2 = gsl_ran_gaussian(r2, 1);
  // printf("%g %g \n", etha1, etha2);
  drG   = sigma_r*etha1;
  dvG   = aux1*etha1 + aux2*etha2;

  x = x + c1*dt*v + c2*dt2*force + drG;
  force_old = force;
  calcForce();
  v = c0*v + (c1-c2)*dt*force + c2*dt*force + dvG;
}

void Particle::savedata(FILE *ofile, double time){
  fprintf(ofile, "%f %g %g\n", time, x, v);
}

int main(int argc, char* argv[]){
  printf("Heat Engine\n");
  string flnPrefix = "Histo_v";
  int Nsteps  = 1025;
  int Ntrials = 100000;
  Particle p;
  p.dt = 0.01;

  // ------------- BEGIN HISTOGRAM CONFIGURATION ------------- //
  int histo_base  = 2;
  const int Nhisto  =   11; 
  int histoTimes[Nhisto];
  for (int i=0; i<Nhisto; i++) histoTimes[i] = pow(histo_base, i); 
  FILE *ofileHisv_base[Nhisto]; 
  char auxflnName[100];
  for ( int i=0; i < Nhisto; i++){
    sprintf(auxflnName, "%s__ts_%d.his", flnPrefix.c_str(), histoTimes[i] ); ofileHisv_base[i] = fopen(auxflnName, "w");
  }

  gsl_histogram * hv_base[Nhisto]; 
  int auxMSD   = 0;
  int aux_n    = 0;
  double xmin  = 0;
  double xmax  = 0;
  //  double bin_spacing = 0.0;

  //  double lower = 0.0;
  //  double upper = 0.0;
  
  for (int i =0; i < Nhisto; i++){
    //h_base[i] = gsl_histogram_alloc (2*auxMSD+1);
    auxMSD     = 10*(int)ceil(sqrt(histoTimes[i]));
    aux_n      = 16*auxMSD+1;
    xmin       = -auxMSD-0.5;
    xmax       =  auxMSD+0.5;
    hv_base[i] = gsl_histogram_alloc (aux_n);
    gsl_histogram_set_ranges_uniform (hv_base[i], xmin, xmax);
    //  bin_spacing  =  ( xmax - xmin )/ aux_n ;
    //  gsl_histogram_get_range(hv_base[i], 0, &lower, &upper );
    //  printf("d = %g, lower = %g, upper = %g, d_0 = %g\n", bin_spacing, lower, upper, upper-lower );
  }
  int histoCount;
  // ------------- END HISTOGRAM CONFIGURATION ------------- //

  // ++++++++++ ONE TRAJECTORY ++++++++++ //
  FILE *ofile;
  ofile = fopen("x_vs_t.dat","w");
  fprintf(ofile, "#t x v\n");
  p.x  = 2.0;
  p.v  = 0.0;
  for (int ns=0; ns<Nsteps; ns++){
    p.RunHeatBath();
    p.savedata(ofile, ns*p.dt);
  }
  fclose(ofile);

  // ======== BEGIN SIMULATION ======== //
  for (int nt=0; nt<Ntrials; nt++){
    p.x  = 2.0;
    p.v  = 0.0;
    histoCount = 0;
    for (int ns=0; ns<Nsteps; ns++){
      p.RunHeatBath();
      // p.RunAdiabatic();
      // p.savedata(ofile, ns*p.dt);
      if ( ns == histoTimes[histoCount] ){
        gsl_histogram_increment (hv_base[histoCount], p.v);
        histoCount++;
      }
    }
  }
  // ======== END SIMULATION ======== //


  // ----- BEGIN WRITE HISTOGRAMS IN FILES ----- //
  double area_hv = -1.0; 
  double lower   = -1.0;
  double upper   = -1.0;
  for (int i = 0; i<Nhisto; i++){
    gsl_histogram_get_range ( hv_base[i], 0, &lower, &upper ); // get the range of the element 0 of the histogram to get the d spacing
    area_hv = (upper-lower)*gsl_histogram_sum( hv_base[i] );
    if (area_hv > 0.0)  gsl_histogram_scale(hv_base[i], 1.0 / area_hv );
    gsl_histogram_fprintf (ofileHisv_base[i], hv_base[i], "%g", "%g");
  }
  for (int i = 0; i< Nhisto; i++){
    gsl_histogram_free (hv_base[i]);
    fclose(ofileHisv_base[i]);
  }
  // ----- END WRITE HISTOGRAMS IN FILES ----- //

  return 0;
}

