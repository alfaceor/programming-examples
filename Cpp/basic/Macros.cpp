#include <stdio.h>
//#include <stdio.h>

#define   PRINTTRAJECTORY  printf( "Hello World\n" );
#define   PRINTFILE fprintf(ofile, "Hello World\n" );

int main(){
  PRINTTRAJECTORY
  FILE *ofile = fopen("Macro.dat", "w");
  PRINTFILE
  fclose(ofile);
  return 0;
}
