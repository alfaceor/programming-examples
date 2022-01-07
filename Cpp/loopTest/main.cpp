
#include <cstdlib>
#include <iostream>
//#define N  1000000
//#define N2 1000
#define DIM 2

#include "Gas.h"
#define indx2(i,j,Np) ((i)*Np+j)
using namespace std;


int main(int argc, char** argv) {

  int const N=10;
  cout<<"Test for the perfomance for loops"<<endl;
  double alpha=0.00;
  dt=0.1;
  dt2=dt*dt;
  eps=1.0;
  gamma1=1.0;
  gamma2=1.0;
  mass=1.0;

  double seed01_1=1.0;
  double seed01_2=2.0;
  double seed02_1=3.0;
  double seed02_2=4.0;

  Gas g_old(N, alpha);
  Gas g_new(N, alpha);
  
  g_old.initVeloc();
  g_old.initCoord3();
  g_old.printCoord();

  HeatBath hb01(mass, gamma1, T1, dt, dt2, seed01_1, seed01_2);
  HeatBath hb02(mass, gamma2, T2, dt, dt2, seed02_1, seed02_2);

  hb01.RollTheDice();
  hb02.RollTheDice();

  g_new.updateCoord( &g_old, dt, dt2, &hb01, &hb02);
  g_new.removeCyclesCoord();
  	 
  // 3. Calculate ___force_new___
  g_new.calculateVec_m();					//--  3.1 Calculate m_new
  g_new.calculateVec_M();					//--  3.2 Calculate M_new
  g_new.calculateForceAlpha3(eps);		//--  3.3 Calculate force_new with M_new
  g_old.calculateEkin_n();
  g_old.calculateEkin();
  g_old.calculateEpotAlpha2(eps);
  
  g_old.calculateVec_flux2(eps, 0);  	
  // 4. Calculate ___omega_new___
  g_new.updateVeloc(&g_old, io.dt, &hb01, &hb02);
 
}
