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
ax.set_xlabel("$x$", size=30)
ax.set_ylabel("$y$", size=30, rotation=0)

data = np.loadtxt("rw2D_Net.dat")
ax.matshow(data)

fig.tight_layout()
outFilename = "rw2D_Net.pdf" 
plt.savefig(outFilename)

plt.show()
