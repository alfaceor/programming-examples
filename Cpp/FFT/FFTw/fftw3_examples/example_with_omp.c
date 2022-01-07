// calculating Hm2h explicitly

#include <string.h>
#include <stdio.h>
#include<math.h>
#include<omp.h>
#include <fftw3.h>

#define pi  4*atan(1.0)
int main(){

int N=500;
static double h[500][500];
static double hfr[500][500];
static double hfi[500][500];
static double hdt[500][500];
static double hdti[500][500];
static double hdtfr[500][500];
static double hdtfi[500][500];
static double coeffr[500][500];

static double hc[500][500]; // h^3
static double hcfr[500][500];
static double hcfi[500][500];

static double grad[500][500];
static double grad2[500][500];

static double gradfr[500][500];
static double grad2fr[500][500];

static double gradfi[500][500];
static double grad2fi[500][500];

static double gradfrcoef[500][500];
static double grad2frcoef[500][500];

static double areaar[500][500];
static double Aarr[500][500];
static double Barr[500][500];
static double Carr[500][500];


static double sigmanumar[500][500];
static double sigmadenomar[500][500];


double A;
double B;
double C;


double ffr[N];
double qfr[N];
double L=200; // data for x is 0 to L
double dx=L/N;
double z;
double deca;
double Hm2=0.49;
int i;
int j;

double sigma;
double sigmanum;
double sigmadenom;
double area;
double havrg;
int NUM_THREADS;
int id;

int loop;
double dt=0.1; // note: stable upto dt=0.6
double time;
double tmin=16;
double tmax=1000;
int loops=(tmax-tmin)/dt;

FILE *fileinit;
FILE *filenonconserve2dh;
FILE *fileareadat;
FILE *filesigmadat;
FILE *filehavrgdat;

char filename[16];

// initialize threads for fft
fftw_init_threads();

fftw_complex *in, *out;
fftw_plan pf, pb;
in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
// create plans with threads
fftw_plan_with_nthreads(omp_get_max_threads());
// plan for forward transform
pf = fftw_plan_dft_2d(N,N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
// pf = fftw_plan_dft_r2c_2d(N,N,in,out,FFTW_ESTIMATE);
// plan for backward transform
pb = fftw_plan_dft_2d(N,N,in,out,FFTW_BACKWARD,FFTW_ESTIMATE);
// pb = fftw_plan_dft_c2r_2d(N,N,in,out,FFTW_ESTIMATE);
//TUNG: end of adding variables for fft

for (i=1; i<(N/2); i++){
ffr[i]=i;
ffr[N-i]=-i;
}
ffr[0]=0;
ffr[N/2]=N/2;
for (i=0; i<N; i++){
qfr[i]=ffr[i]*2*pi/N;
}


/*
fileinit = fopen("donneesthesenc2d13fr0to15.dat", "r");
for (i=0; i<N+1; i++){
for (j=0; j<N+1; j++){
fscanf(fileinit, "%lf\n", &z);
if((i<N)&&(j<N)){
h[i][j]=z;
}
}
}
*/



fileinit = fopen("donneesthesenc2d13fr0to16.dat", "r");
for (i=0; i<N; i++){
for (j=0; j<N; j++){
fscanf(fileinit, "%lf\n", &z);
h[i][j]=z;
}
}



fclose(fileinit);

// coefficients for implicit scheme
for (i=0; i<N; i++){
for (j=0; j<N; j++){
grad2frcoef[i][j]=(qfr[i]*qfr[i]*qfr[i]*qfr[i]+qfr[j]*qfr[j]*qfr[j]*qfr[j]+2*qfr[i]*qfr[i]*qfr[j]*qfr[j])/(dx*dx*dx*dx);
gradfrcoef[i][j]=-(qfr[i]*qfr[i]+qfr[j]*qfr[j])/(dx*dx);
}
}

//fileareadat = fopen("fileareadat.dat", "w");
//filesigmadat = fopen("filesigmadat.dat", "w");
//filehavrgdat = fopen("filehavrgdat.dat", "w");

//------------------------------------------

for(loop=0;loop<loops;loop++) {

time = (loop+1)*dt+tmin;

// inside big loops
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0; i<N; i++) {
for(j=0; j<N; j++) {
hc[i][j] = h[i][j]*h[i][j]*h[i][j];
}
}

// h to hfr, hfi
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
in[i*N+j][0] = h[i][j];
in[i*N+j][1] = 0.0;
}
}
// backward transform
fftw_execute(pf);
// copy output vector
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
hfr[i][j] = out[i*N+j][0];
hfi[i][j] = out[i*N+j][1];
}
}

// hc to hcfr, hcfi
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
in[i*N+j][0] = hc[i][j];
in[i*N+j][1] = 0.0;
}
}
// backward transform
fftw_execute(pf);
// copy output vector
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
hcfr[i][j] = out[i*N+j][0];
hcfi[i][j] = out[i*N+j][1];
}
}

// calculating derivatives
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
gradfr[i][j]  = gradfrcoef[i][j]*hfr[i][j];
gradfi[i][j]  = gradfrcoef[i][j]*hfi[i][j];
grad2fr[i][j] = grad2frcoef[i][j]*hfr[i][j];
grad2fi[i][j] = grad2frcoef[i][j]*hfi[i][j];
}
}

// fft transform back to get grad and grad2
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
in[i*N+j][0] = gradfr[i][j];
in[i*N+j][1] = gradfi[i][j];
}
}
// backward transform
fftw_execute(pb);
// copy output vector
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
grad[i][j] = out[i*N+j][0]/(N*N);
}
}

#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
in[i*N+j][0] = grad2fr[i][j];
in[i*N+j][1] = grad2fi[i][j];
}
}
// backward transform
fftw_execute(pb);
// copy output vector
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
grad2[i][j] = out[i*N+j][0]/(N*N);
}
}


#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
Aarr[i][j] = (qfr[i]*qfr[i]+qfr[j]*qfr[j])*dt*dt*grad2frcoef[i][j]*(hfr[i][j]*hfr[i][j]+hfi[i][j]*hfi[i][j])/((1+dt*grad2frcoef[i][j])*(1+dt*grad2frcoef[i][j]));

Barr[i][j] = (qfr[i]*qfr[i]+qfr[j]*qfr[j])*dt*gradfrcoef[i][j]*2*( hfr[i][j]*(hfr[i][j]-dt*hcfr[i][j]+Hm2*dt*hfr[i][j]) + hfi[i][j]*(hfi[i][j]-dt*hcfi[i][j]+Hm2*dt*hfi[i][j]) )/((1+dt*grad2frcoef[i][j])*(1+dt*grad2frcoef[i][j]));

Carr[i][j] = (qfr[i]*qfr[i]+qfr[j]*qfr[j])*(  ((hfr[i][j]-dt*hcfr[i][j]+Hm2*dt*hfr[i][j])*(hfr[i][j]-dt*hcfr[i][j]+Hm2*dt*hfr[i][j])  +  (hfi[i][j]-dt*hcfi[i][j]+Hm2*dt*hfi[i][j])*(hfi[i][j]-dt*hcfi[i][j]+Hm2*dt*hfi[i][j]) ) /((1+dt*grad2frcoef[i][j])*(1+dt*grad2frcoef[i][j])) - (hfr[i][j]*hfr[i][j]+hfi[i][j]*hfi[i][j]));
}
}


A = 0.0;
B = 0.0;
C = 0.0;
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
A = A + Aarr[i][j];
B = B + Barr[i][j];
C = C + Carr[i][j];
}
}

//sigma = (-B-sqrt(B*B-4*A*C))/(2*A);
sigma = 0.0;

// implicit scheme
#pragma omp parallel for //seulement pour les grands systèmes
for (i=0; i<N; i++){
for (j=0; j<N; j++){
hdtfr[i][j]=(1/(1+dt*grad2frcoef[i][j]))*(hfr[i][j]*(1+dt*Hm2+dt*sigma*gradfrcoef[i][j])-dt*hcfr[i][j]);
hdtfi[i][j]=(1/(1+dt*grad2frcoef[i][j]))*(hfi[i][j]*(1+dt*Hm2+dt*sigma*gradfrcoef[i][j])-dt*hcfi[i][j]);
}
}

// initialize input vector in for backward transform
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
in[i*N+j][0] = hdtfr[i][j];
in[i*N+j][1] = hdtfi[i][j];
}
}
// backward transform
fftw_execute(pb);
// copy output vector
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
hdt[i][j] = out[i*N+j][0]/(N*N);
}
}

#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
h[i][j] = hdt[i][j];
}
}

//if(fmod(time,1500.) ==0) {
//printf("%.50f\n", time);

// area conservation
#pragma omp parallel for //seulement pour les grands systèmes
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
areaar[i][j] = (qfr[i]*qfr[i]+qfr[j]*qfr[j])*(hfr[i][j]*hfr[i][j]+hfi[i][j]*hfi[i][j]);
}
}


area=0.;
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
area = area + areaar[i][j];
}
}

area = area/(250000*dx*dx);

if(fmod(time,1.) ==0) {
//if(loop%100==0) {
printf("%.1f\n", time);
printf("%.20f\n", area);
printf("%.20f\n", sigma);
}


if(fmod(time,3000.) ==0) {
sprintf( filename, "file%.0f.dat", time );  
filenonconserve2dh = fopen(filename, "w");
//filenonconserve2dh = fopen("nonconserve2dh.dat", "w");
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
deca=hdt[i][j];
fprintf(filenonconserve2dh, "%.20f\n", deca);
}
}
fclose(filenonconserve2dh);
}


}

//------------------------------------------

fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);
// clean up threads
fftw_cleanup_threads();
return 0;
}

