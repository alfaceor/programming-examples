#include <stdio.h>
#include <stdlib.h>
//#include <string>


int main(){
  const int numFiles = 9; // 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9
  FILE *files[numFiles];
  char flnName[20];
  for (int i=0; i< numFiles; i++){
    //printf("i = %d \n", i);
    sprintf(flnName, "file__1e%d.his", i+1);
    files[i] = fopen(flnName, "w");
  }

  // Write in the files
  int base10 = 10;
  int ifile  = 0;
  for (int stps=0; stps< 10000001; stps++){
    if (stps == base10){
      fprintf(files[ifile], "hi! how are u? %i\n", stps);
      base10 = 10*base10;
      ifile++;
    }
  }
  
  // Close all the files  
  for (int i=0; i< numFiles; i++){
    fclose(files[i]);
  }
  return 0;
}
