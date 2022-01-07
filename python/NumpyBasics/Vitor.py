#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 21:25:38 2018

@author: alfaceor
"""

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.array([[1,2,3], [1,4,9], [7,7,7]])
print data[:,2]

#data = np.loadtxt("matriz.dat")
X = data[:,0]
Y = data[:,1]
Z = data[:,2]


u = np.linspace(0, 2 * np.pi, 100)
v = np.linspace(0, np.pi, 100)
x = 10 * np.outer(np.cos(u), np.sin(v))
y = 10 * np.outer(np.sin(u), np.sin(v))
z = 10 * np.outer(np.ones(np.size(u)), np.cos(v))

#fig, ax = plt.subplots()
fig = plt.figure()
ax = fig.gca(projection='3d')

ax.plot_surface(X,Y,Z)

plt.show()


