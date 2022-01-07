#include<stdio.h>
#include<stdlib.h>

int main ( int argc , char* argv[] )
{
  
  char str[30];
  for (int i=1; i <= 3; i++ )
    printf( "%s \n" ,argv[i]);

  sprintf(str,"echo %s %s %s",argv[1],argv[2],argv[3]);
  system(str);

  sprintf(str,"echo %s %s %s",argv[3],argv[2],argv[1]);
  system(str);

  sprintf(str,"echo %s %s %s",argv[1],argv[1],argv[1]);
  system(str);
}
