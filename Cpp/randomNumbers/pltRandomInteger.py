#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt
inFile  = "randomIntegerFabio.dat"
data    = np.loadtxt(inFile)
data    = map(int, data)
lendata = float(len(data) )

#unique, counts = np.unique(data, return_counts=True)
#print data
u = np.unique(data)
print u, len(u), type(u)
x = u
y = np.bincount(data).astype(float)/lendata

print x[0:2], len(x), len(y)

fig, ax = plt.subplots()
ax.set_title("Gaussian Histogram")
ax.set_xlabel("Value")
ax.set_ylim((0,0.1))
ax.set_ylabel("Frequency")

ax.plot(x, y, 'o')

plt.show()
