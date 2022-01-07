#include <iostream>

using namespace std;

#ifndef SYSTEM_H
#define SYSTEM_H
class System{
  public:
    int N;
    double *p;
    double *q;

    System(int const Np);
    ~System();

    void initP();
    void initQ();
    void strPhaseSpace();
};

#endif /*SYSTEM_H*/
