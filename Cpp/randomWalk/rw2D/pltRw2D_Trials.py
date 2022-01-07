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



#fprintf(outfile, "#nt x y x_var y_var r_var\n");
fig, ax = plt.subplots()
ax.set_xlabel("$t$")
ax.set_ylabel("$ \\langle r^2 \\rangle $")

for nt in range(1,6):
  strNtrials = str(10**nt)
  data = np.loadtxt("rw2D__Trials_"+strNtrials+".dat")
  ax.plot(data[:,0], data[:,5], label=strNtrials)

ax.legend(loc='best', prop={'size':10}, frameon=False)
fig.tight_layout()
outFilename = "rw2D_Trials.pdf" 
plt.savefig(outFilename)

plt.show()
