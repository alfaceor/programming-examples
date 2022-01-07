// what's faster, fwrite or fprintf?

#include <stdio.h>
#include <stdlib.h>

const int runs = 100000;
char buf[255];      // create a buffer for fwrite to use

int main()
{
    int a    = 5;
    double b = 9.2919e92;
    char c   = 'x';
    char * d = "blah blah blah";


    // test start:  open a file to write to
    FILE * outfile = fopen( "testfile.txt", "w" );

    /////////////////////
    // START timing
    QueryPerformanceCounter( &time1 );

    // test fprintf(), run 100000 times!
    for(int i = 0; i < runs; i++)
    {
        //fprintf(outfile, "blah %i %f %c %s\n", a, b, c, d );

        // making fprintf() print a single string generated
        // by sprintf() to equalize the test
        sprintf( buf, "blah %i %f %c %s\n", a, b, c, d );   // its only fair!
        fprintf( outfile, "%s", buf );

        fflush(outfile);    // flush after going to the toilet
    }

    ////////////////////
    // STOP timing
    QueryPerformanceCounter( &time2 );

    // get the difference between time1 and time2,
    // and that is how long the for loop took to run.
	floatDiffTime = ((float)time2.QuadPart - time1.QuadPart)/ticksPerSecond.QuadPart;
    printf( "fprintf took %f seconds\n", floatDiffTime );

    fclose( outfile );  // close up, so we
    // can proceed to start over with
    // fwrite test.


    ////////////////
    // testing fwrite()
    outfile = fopen( "testfile.txt", "w" );

    ////////////////////
    // START timing
    QueryPerformanceCounter( &time1 );
    //
    ////////////////////

    // test fwrite(), run 100000 times!
    for(int i = 0; i < runs; i++)
    {
        // fwrite needs a single string to write from,
        // so use sprintf to copy to a buffer
        sprintf( buf, "blah %i %f %c %s\n", a, b, c, d );
        fwrite( buf, 1, strlen( buf ), outfile );
        fflush(outfile);    // flush
    }

    ////////////////////
    // STOP timing
    QueryPerformanceCounter( &time2 );
    //
    ////////////////////

    // get the difference between time1 and time2,
    // and that is how long the for loop took to run.
	floatDiffTime = ((float)time2.QuadPart - time1.QuadPart)/ticksPerSecond.QuadPart;
    printf( "fwrite() took %f seconds\n", floatDiffTime );


    fclose( outfile );
    return 0;
}
