#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("rw1Dv01.dat")

fig, ax = plt.subplots(3,1, sharex=True)
axX_mean = ax[0]
axX_var  = ax[1]
axX      = ax[2]

axX_mean.plot(data[:,0], data[:,1])
axX_var .plot(data[:,0], data[:,2])
axX     .plot(data[:,0], data[:,3])

plt.show()

