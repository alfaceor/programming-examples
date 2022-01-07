

#include <stdio.h>
#include <stdlib.h>
int main(){
  double x, y;
  FILE *fp;
  char *filename;
  filename = "input.dat";
  fp = fopen(filename, "r");
	for (int i=0;i<6;i++){
		// fscanf(fp,"%lf",&number);
			fscanf(fp,"%lf %lf", &x , &y);
  		printf("number = %g %g\n", x, y);
	}
  fclose(fp);
  return 0;
}
