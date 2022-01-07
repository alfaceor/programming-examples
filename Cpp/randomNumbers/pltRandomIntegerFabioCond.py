#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()
ax.set_title("Gaussian Histogram")
ax.set_xlabel("Value")
ax.set_ylim((0,0.1))
ax.set_ylabel("Frequency")

inFile  = "randomIntegerFabioCond.dat"
data    = np.loadtxt(inFile)
data    = map(int, data)
lendata = float(len(data) )

npoints=len(data)

while npoints > 10 :
  print npoints
  u = np.unique(data[:npoints])
  print u, len(u), type(u)
  x = u
  lendata = float(len(data[:npoints]) )
  y = np.bincount(data[:npoints]).astype(float)/lendata
  ax.plot(x, y, '-o', label="$"+str(lendata)+"$")
  npoints = npoints/10

ax.axhline(1./12.0, color='k')
ax.legend(loc='best', prop={'size':10}, numpoints=1, frameon=False)
plt.show()


