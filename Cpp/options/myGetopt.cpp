#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <getopt.h>

using namespace std;
int
main (int argc, char **argv)
{
  double pF2F = -1 ; // FREE to FREE
  double pB2F = -1 ; // BORD to FREE
  double pH2F = -1 ; // HARD to FREE
  
  double pF2B = -1 ; // FREE to BORD *
  double pB2B = -1 ; // BORD to BORD *
  double pH2B = -1 ; // HARD to BORD
  
  double pF2H = -1 ; // FREE to HARD
  double pB2H = -1 ; // BORD to HARD
  double pH2H = -1 ; // HARD to HARD


  string strF2B ="";
  string strB2B ="";

  //--- Read options ---//
  int auxC;
  while (1)
    {
      static struct option long_options[] =
        {
          {"pF2B",  required_argument, 0, 'f'},
          {"pB2B",  required_argument, 0, 'b'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      auxC = getopt_long (argc, argv, "fb",
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

        case 'f':
          printf ("option --pF2B %s \n", optarg);
          pF2B   = atof(optarg);
          strF2B = optarg;
          break;

        case 'b':
          printf ("option --pB2B %s \n", optarg);
          pB2B   = atof(optarg);
          strB2B = optarg;
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
  if ( pF2B < 0 || pF2B > 1 ){
    printf("--pF2B is missing or not between 0 and 1 \n");
  }
  if ( pB2B < 0 || pB2B > 1 ){
    printf("--pB2B is missing or not between 0 and 1 \n");
  }

  printf("pF2B = %f, pB2B = %f \n", pF2B, pB2B);
  printf("pF2B = %s, pB2B = %s \n", strF2B.c_str(), strB2B.c_str());

  return 0;
}
