#include <stdio.h>
#define DIM 1
int main(){
	const int N=10;
	double *deltaR2;
	deltaR2 = new double[N*N]();
	
	double auxdelta;
	for (int k=0; k<N; k++){
		for (int l=k; l<N; l++){
			deltaR2[k*N+l] = 0.0;
			/*
			for (int d=0;d<DIM;d++){
				auxdelta = (k - l);
				deltaR2[k*N+l] += auxdelta;
			}
			*/
			deltaR2[l*N+k] = deltaR2[k*N+l];
			
		}
		
	}

	for (int k=0; k<N; k++){
		for (int l=k; l<N; l++){
			deltaR2[k*N+l] = l+k;
			deltaR2[l*N+k] = deltaR2[k*N+l];
		}
		
	}
	

	for (int k =0; k<N; k++){
		for (int l=0; l <N ; l++){
			printf("%f\t",deltaR2[k*N+l]);
		}
		printf("\n");
	}
}
