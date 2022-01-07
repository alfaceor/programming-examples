#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

DiffCoeff = 1.0
DiffLamb1 = 0.8
DiffLamb2 = 0.9
DiffLamb3 = 1.2
D_aux = np.array([DiffCoeff, DiffLamb1, DiffLamb2, DiffLamb3])
D_err_min = D_aux.mean() - D_aux.min()
D_err_max = D_aux.max()  - D_aux.mean()

fig, ax = plt.subplots()

Npoints=10
XX = np.linspace(0,1, num=Npoints)
YY = DiffCoeff  *np.ones(Npoints)
Y1 = D_aux.min()*np.ones(Npoints)
Y2 = D_aux.max()*np.ones(Npoints)
print D_aux
###   ax.axhline(y=D_aux.max(), color='k')
###   ax.axhline(y=D_aux.min(), color='k')
#ax.fill_between(XX, Y1, Y2, where=Y2 >= Y1, facecolor='red', interpolate=True)
#ax.axhline(y=DiffCoeff, color='k')
ax.fill_between(XX, Y1, Y2, facecolor="white", alpha=0.5, hatch="x", edgecolor='g', linestyle='dashed') #, facecolor='green', alpha=0.5, transform=trans)
######## ax.fill_between(XX, Y1, Y2, color="none", alpha=0.5, linestyle='dashed', hatch="x", edgecolor='g') #, facecolor='green', alpha=0.5, transform=trans)
#ax.fill_between(XX, 0, 1 ) #, where=y < -theta, facecolor='red', alpha=0.5, transform=trans)
fig.savefig("fill_between.png")
plt.show()

