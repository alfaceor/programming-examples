#ifndef CONFORMATION_H_
#define CONFORMATION_H_

#include <stdio.h>
#include <stdlib.h>

#define DIM 3

class Conformation {

public:
	Conformation(int N);
	virtual ~Conformation();
	void print_r();
	int *chain;
private:
	int N;
};

#endif /* CONFORMATION_H_ */
