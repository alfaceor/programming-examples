/* 
 * File:   Chain.h
 * Author: alfaceor
 *
 * Created on November 5, 2015, 10:12 AM
 */

#include <iostream>

#include <sstream>

#include <string>



#ifndef RING_H
#define	RING_H

using namespace std;

class Ring {
public:
    int N;
    double alpha;
    double k;
    Ring(int const N);
    ~Ring();
    string getParams();
};

#endif	/* RING_H */


