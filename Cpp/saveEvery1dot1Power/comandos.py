#!/usr/bin/python
import numpy as np
Npoints = 1000
ttime = np.zeros(Npoints)
valueI = np.zeros(Npoints)

ofile = open("finalStuffs.txt", "w")
for i in range(Npoints):
    valueI[i] = i
    ttime[i]  = 1.1**i
    ofile.write(str(valueI[i])+" "+str(ttime[i])+"\n")
ofile.close()

import matplotlib.pyplot as plt
fig, ax = plt.subplots()
ax.set_yscale("log")
ax.plot(valueI, ttime, marker="o")
plt.show()
