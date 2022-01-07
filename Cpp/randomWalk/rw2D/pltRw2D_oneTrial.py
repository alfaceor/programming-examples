#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("rw2D_oneTrial.dat")

plt.plot(data[:,1], data[:,2])
plt.show()
