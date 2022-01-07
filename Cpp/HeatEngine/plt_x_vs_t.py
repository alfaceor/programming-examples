#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt
###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18} 
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES

fig, ax = plt.subplots()

ax.set_xlabel("$ t $", size=30)
ax.set_ylabel("$ x $", color='b', rotation=0, size=30)

#ax.set_ylim(-2.5, 2.5)

data = np.loadtxt("x_vs_t.dat")
time = data[:,0]
x    = data[:,1]
v    = data[:,2]

ax.plot(time, x, "-")

ax2 = ax.twinx()

ax2.set_ylabel("$ v $", color='r', rotation=0, size=30)
#ax2.set_ylim(-2.5, 2.5)

ax2.plot(time, v, "-", color="r")

fig.tight_layout()
plt.show()

