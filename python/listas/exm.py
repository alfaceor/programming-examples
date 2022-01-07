#!/usr/bin/python

import numpy as np

#lista=[ i for i in range(5) ]

data=np.loadtxt("sample.dat")
listita = [ range(i) for i in range(5) ]
print listita[0]
