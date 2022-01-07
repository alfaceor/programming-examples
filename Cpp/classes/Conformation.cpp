/*
 * Conformation.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: alfaceor
 */

#include "Conformation.h"

Conformation::Conformation(int N) {
	this->N = N;
	this->chain = new int[N*DIM]();
	for(int i=0; i<N; i++){
		for (int d=0; d<DIM; d++){
			this->chain[i*DIM+d] = i*d;
		}
	}
}

Conformation::~Conformation() {
	// TODO Auto-generated destructor stub
}

void Conformation::print_r(){
	for(int i=0; i<this->N; i++){
		for(int d=0; d<DIM; d++){
			printf("%d\t",this->chain[i*DIM+d]);
		}
		printf("\n");
	}
}

