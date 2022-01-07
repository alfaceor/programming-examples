/* 
 * File:   main.cpp
 * Author: alfaceor
 *
 * Created on August 2, 2015, 3:17 AM
 */

#include <cstdlib>
#include <iostream>
#define N  1000000
#define N2 1000
#define DIM 2

#define indx2(i,j,Np) ((i)*Np+j)
using namespace std;

/*
 * 
 */

int indx(int i, int j){
  return (i*DIM+j);
};

int indx3(int i, int j, int Np){
  return (i*Np+j);
};

class Gas{
    public:
        int Npart;
        double arrayGas[N];
        double *ptrGas1; // with new
        double *ptrGas2; // malloc
		
    Gas(int const);
    ~Gas();
};


Gas::Gas(const int Npart){
  this->Npart = Npart;
  this->ptrGas1 = new double[Npart];
  this->ptrGas2 = (double*) calloc (Npart,sizeof(double));

}

Gas::~Gas(){
  delete[] ptrGas1;
  free(ptrGas2);
}

class Gas2{
    public:
        int Npart;
//        double arrayGas[N2][N2];
//        double **ptrGas2_1; // with new[][]
        double *ptrGas2_2; // with new[N*N]
//        double *ptrGas2_3; // malloc
		
    Gas2(int const);
    ~Gas2();
};

Gas2::Gas2(int const Npart){
  this->Npart = Npart;
//  (*ptrGas2_1)[Npart] = new double[Npart];
  
  this->ptrGas2_2 = new double[Npart*Npart];
//  this->ptrGas2_3 = (double*) calloc (Npart,sizeof(double)); // FIXME
  for (int i =0; i<Npart; i++){
    for (int j=0; j<Npart; j++){
//      arrayGas[i][j] = 0.00;
      ptrGas2_2[indx2(i,j,Npart)] = 0.00;
    }
  }

}

Gas2::~Gas2(){
//  delete ptrGas2_1;
  delete ptrGas2_2;
//  free(ptrGas2_3);
}


int main(int argc, char** argv) {
  
  cout<<"Test for the perfomance of array"<<endl;
  int total_time=100000;
  int ttime=0;
  int auxvar=0;
  
  if (argc>=1){
    auxvar=atoi(argv[1]);
    
    switch(auxvar){
      case 1:{
        cout<<"case 1"<<endl;
        //Array inside the main function;
        double arrayMain[N];

        for (int i=0; i<N ; i++){
          arrayMain[i]=0.00;
      //    arrayMain[i]=arrayMain[i]+i;
        }

        while(ttime<total_time){
          for (int i=0; i<N ; i++){
            arrayMain[i]=arrayMain[i]+i;
          }
          ttime++;
        }
        cout<<arrayMain[N-1]<<endl;
      }
      break;
      case 2:{
        cout<<"case 2"<<endl;
        // Using gas class.
        Gas g1(N);

        while(ttime<total_time){
          for (int i=0; i<N; i++){
            g1.ptrGas1[i]=g1.ptrGas1[i]+i;
          }
          ttime++;
        }
        cout<<g1.ptrGas1[N-1]<<endl;
      }
      break;
      case 3:{
        cout<<"case 3"<<endl;
        // Using gas class.
        Gas g1(N);
        while(ttime<total_time){
          for (int i=0; i<N; i++){
            g1.ptrGas2[i]=g1.ptrGas2[i]+i;
          }
          ttime++;
        }
        cout<<g1.ptrGas2[N-1]<<endl;
      }
      break;
      case 10:{
        cout<<"case 10"<<endl;
        double arrayMain2[N2][N2];
        for (int i=0; i<N2 ; i++){
          for (int j=0; j<N2 ; j++){
            arrayMain2[i][j]=0.00;
          }
        }
        while(ttime<total_time){
          for (int i=0; i<N2; i++){
            for (int j=0; j<N2; j++){
              arrayMain2[i][j]=arrayMain2[i][j]+i+i*j;
            }
          }
          ttime++;
        }
      }
      break;
      
//      case 11:{
//        
//        // FIXME:something is wrong
//        cout<<"case 11"<<endl;
//        Gas2 g2_1(N2);
//        while(ttime<total_time){
//          for (int i=0; i<N2; i++){
//            for (int j=0; j<N2; j++){
//              g2_1.arrayGas[i][j]=g2_1.arrayGas[i][j]+i+i*j;
//            }
//          }
//          ttime++;
//        }
//      }
//      break;
//      
//      case 12:{
//        cout<<"case 12"<<endl;
//        Gas2 g2_1(N2);
//        while(ttime<total_time){
//          for (int i=0; i<N2; i++){
//            for (int j=0; j<N2; j++){
//              g2_1.ptrGas2_2[indx2(i,j,N2)]=g2_1.ptrGas2_2[indx2(i,j,N2)]+i+i*j;
////              cout<<g2_1.ptrGas2_2[indx2(i,j,N2)]<<endl;
//            }
////            cout<<indx2(i,N2-1,N2)<<endl;
//          }
////          cout<<ttime<<endl;
//          ttime++;
//        }
//      }
//      break;
//      case 13:{
//        cout<<"case 12"<<endl;
//        Gas2 g2_1(N2);
//        while(ttime<total_time){
//          for (int i=0; i<N2; i++){
//            for (int j=0; j<N2; j++){
//              g2_1.ptrGas2_2[indx3(i,j,N2)]=g2_1.ptrGas2_2[indx3(i,j,N2)]+i+i*j;
////              cout<<g2_1.ptrGas2_2[indx2(i,j,N2)]<<endl;
//            }
////            cout<<indx2(i,N2-1,N2)<<endl;
//          }
////          cout<<ttime<<endl;
//          ttime++;
//        }
//      }
//      break;
      
      case 20:{
        cout<<"case 20"<<endl;
        Gas2 g2_1(N2);
        Gas2 g2_2(N2);
        while(ttime<total_time){
          for (int i=0; i<N2; i++){
            for (int j=0; j<N2; j++){
              g2_1.ptrGas2_2[indx2(i,j,N2)]=g2_1.ptrGas2_2[indx2(i,j,N2)]+i+i*j;
              g2_2.ptrGas2_2[indx2(i,j,N2)]=g2_2.ptrGas2_2[indx2(i,j,N2)]+j-i*j;
//              cout<<g2_1.ptrGas2_2[indx2(i,j,N2)]<<endl;
            }
//            cout<<indx2(i,N2-1,N2)<<endl;
          }
//          cout<<ttime<<endl;
          ttime++;
        }
      }
      break;
      
      case 21:{
        cout<<"case 21"<<endl;
        Gas2 g2_1(N2);
        Gas2 g2_2(N2);
        while(ttime<total_time){
          for (int i=0; i<N2; i++){
            for (int j=0; j<N2; j++){
              g2_1.ptrGas2_2[indx2(i,j,N2)]=g2_1.ptrGas2_2[indx2(i,j,N2)]+i+i*j;
//              cout<<g2_1.ptrGas2_2[indx2(i,j,N2)]<<endl;
            }
//            cout<<indx2(i,N2-1,N2)<<endl;
          }
          
          for (int i=0; i<N2; i++){
            for (int j=0; j<N2; j++){
              g2_2.ptrGas2_2[indx2(i,j,N2)]=g2_2.ptrGas2_2[indx2(i,j,N2)]+j-i*j;
//              cout<<g2_1.ptrGas2_2[indx2(i,j,N2)]<<endl;
            }
//            cout<<indx2(i,N2-1,N2)<<endl;
          }
//          cout<<ttime<<endl;
          ttime++;
        }
      }
      break;
      
      default:
        cout<<"bitch please!"<<endl;
    }
  }

  
  return 0;
}

