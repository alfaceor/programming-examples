// OFSTREAM IS SLOW!!

#include <fstream>
using namespace std;

const int runs = 100*100000;

int main()
{
    int a    = 5;
    double b = 9.2919e92;
    char c   = 'x';
    char * d = "blah blah blah";

    // testing ofstream()
    ofstream out( "oftestout.txt" );

    // test ofstream, run 100000 times!
    for(int i = 0; i < runs; i++)
    {
        out << "blah " << a << " " << b << " " << c << " " << d << endl;
        out.flush();  // flush to be fair
    }

    out.close();

    return 0;
}
