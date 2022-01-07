#!/usr/bin/python
import numpy as np
from mayavi import mlab

t = np.linspace(0, 4 * np.pi, 50)

x = t #np.zeros(len(t)) #np.sin(2 * t)
y = np.cos(t)
z = np.zeros(len(t)) #np.cos(2 * t)
s = 2 + np.sin(t)

y[10]=y[11]
#mlab.points3d(x, y, z, s, colormap="copper", scale_factor=.25, mode='cube')

mlab.plot3d(x, y, z, tube_radius=0.025)
mlab.show()

