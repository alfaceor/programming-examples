
#include <stdio.h>

const int runs =100*100000;

int main()
{
    int a    = 5;
    double b = 9.2919e92;
    char c   = 'x';
    char * d = "blah blah blah";


    // test start:  open a file to write to
    FILE * outfile = fopen( "testfile.txt", "w" );


    // test fprintf(), run 100000 times!
    for(int i = 0; i < runs; i++)
    {
        // fprintf(outfile, "blah %i %f %c %s\n", a, b, c, d );
        fprintf(outfile, "blah %i %.4e %c %s\n", a, b, c, d );
        fflush( outfile );  // flush to be fair
    }



    fclose( outfile );  // close up, so we

    return 0;
}
