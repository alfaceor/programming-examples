#include <stdio.h>
#include <stdlib.h>
#include "Conformation.h"

int main(int argc, char* argv[]) {
	printf("--------------\n");
	Conformation polimero(10);
	polimero.print_r();
	
	return EXIT_SUCCESS;
}

