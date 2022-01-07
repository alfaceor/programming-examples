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

fig, ax = plt.subplots(1,1, figsize=(8,6))
ax.set_title("$\\alpha \\beta \\gamma$")
#### X parameters
ax.set_xlabel("$X^{\\alpha}$", size=30)
#ax.set_xscale("log")
#ax.set_xlim(0,1)

#### Y parameters
ax.set_ylabel("$Y$", size=30, rotation=0)
ax.set_yscale("log")
#ax.set_ylim(0,1)

inFilename="dados.dat"
data=np.loadtxt(inFilename)
ax.plot(data[:,0], data[:,1])
ax.plot(data[:,0], data[:,2])

fig.tight_layout()
plt.show()



