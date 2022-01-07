#!/usr/bin/python

import numpy as np 
import matplotlib.pyplot as plt

data = np.loadtxt("IntegerHistogram.his")
XX = 0.5*(data[:,0]+data[:,1] )
YY = data[:,2]

plt.plot(XX, YY, "-o")
plt.show()

