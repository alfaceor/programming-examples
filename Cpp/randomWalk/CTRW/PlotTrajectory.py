#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("randomWalk.dat")
time = data[:,0]
posx = data[:,1]

fig, ax = plt.subplots()

ax.set_xlabel("$t$")
ax.set_ylabel("$x$")

ax.plot(time, posx, 'o-')

plt.show()

