/* 
 * File:   SubSystem.h
 * Author: alfaceor
 *
 * Created on October 19, 2016, 1:47 AM
 */

#include "Ring.h"
#ifndef SUBSYSTEM_H
#define	SUBSYSTEM_H

class SubSystem {
public:
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
    SubSystem(int N, int i, int j);
    SubSystem(const SubSystem& orig);
    virtual ~SubSystem();
    
    void scaleP(Ring* r, double scaleFactor);
    //void calcU(Ring* r);
    void calcEk(Ring* r);
    void calcEp(Ring* r);
    void calcM(Ring* r);
private:

};

#endif	/* SUBSYSTEM_H */

