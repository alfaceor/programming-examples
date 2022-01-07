#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_statistics.h>
#include <getopt.h>
#include <string>

using namespace std;
int main(int argc, char *argv[] ){
  //--- Read Command Line options  ---//
  int auxC;
  int Naux=-1;
  string strN;

  while (1)
    {   
      static struct option long_options[] =
        {
          {"Npoints",  required_argument, 0, 'N'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      auxC = getopt_long (argc, argv, "N",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (auxC == -1) 
        break;

      switch (auxC)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'N':
          printf ("option --Npoints %s \n", optarg);
          Naux = atoi(optarg);
          strN = optarg;
          break;
        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  if ( Naux < 0 ){
    printf("--Npoints  is missing or not between 0 and 1 \n");
    exit (1);
  }



  const int N   =  Naux ; //atoi(argv[1]);
  double *data; data = new double[N]; 
  for (int i=0; i<N; i++){
    data[i] = i+1;
    printf(" %g ", data[i]);
  }
  printf(" \n ");
  double data_mean = 0.0;
  data_mean = gsl_stats_mean(data,1,N);
  printf("%g\n", data_mean);
  return 0;
}
