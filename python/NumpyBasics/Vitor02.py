#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 21:25:38 2018

@author: alfaceor
"""

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


data = np.loadtxt("matriz.dat")
ll=50
data = data[:ll,:ll]
lenData = len(data)
#print data[:5,:5], len(data)
X = np.linspace(0,lenData -1, lenData)
Y = np.linspace(0,lenData -1, lenData)

XX, YY = np.meshgrid(X,Y)
ZZ = data
#print XX,YY

fig = plt.figure()
ax = fig.gca(projection='3d')

ax.plot_surface(XX,YY,ZZ)

plt.show()


