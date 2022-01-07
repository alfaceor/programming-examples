#!/usr/bin/python

# Plot point by point 

import numpy as np
import matplotlib.pyplot as plt

###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
                'size'   : 18}
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES


data = np.loadtxt("threeColData.dat")

lendata= len(data)
fig, ax = plt.subplots()
ax.set_xlabel("$\\epsilon$", size=30)
ax.set_ylabel("$\\alpha$", size=30, rotation=0)

x = data[:,0]
y = data[:,1]
z = data[:,2]

markerArea=40
for i in range(lendata):
  if z[i] > 3 :
    ax.scatter(x[i], y[i], s=markerArea, marker='o', color='r')
  elif z[i] < 2:
    ax.scatter(x[i], y[i], s=markerArea, marker='D', color='b')
  # Sino no lo plota.
    
fig.tight_layout()
plt.show()
fig.savefig("threeColData.pdf")
