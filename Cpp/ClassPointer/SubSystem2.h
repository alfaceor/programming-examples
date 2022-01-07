/* 
 * File:   SubSystem.h
 * Author: alfaceor
 *
 * Created on October 19, 2016, 1:47 AM
 */

#include "Ring.h"
#ifndef SUBSYSTEM2_H
#define	SUBSYSTEM2_H

class SubSystem2 {
public:
    Ring* r;
    int N;
    int fromI;
    int toJ;
    double U;
    double T;
    double Ep;
    double Ek;
    double Mx;
    double My;
    double M2;
    SubSystem2(int const Ntotal, Ring* s, int N, int i, int j);
    SubSystem2(const SubSystem2& orig);
    virtual ~SubSystem2();
    
    void scaleP(double scaleFactor);
    //void calcU(Ring* r);
    void calcEk();
    void calcEp();
    void calcM();
private:

};

#endif	/* SUBSYSTEM2_H */

