#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

Nsteps=10000
Mtrials=1000
x=np.zeros(Mtrials)

forbidden=[200, 400, 800, 1600]
for m in range(Mtrials):
  for n in range(Nsteps):
    if n in forbidden:
      if 
      stp=-1
    else:
      aleato=np.random.uniform()
      if aleato < 0.5:
        stp=1
      else:
        stp=-1
    x[m]=x[m]+stp
  #print x[m]

plt.hist(x)
plt.show()

