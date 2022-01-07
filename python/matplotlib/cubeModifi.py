#!/usr/bin/python
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

def cuboid_data(pos):
    # code taken from
    # https://stackoverflow.com/a/35978146/4124317
    # suppose axis direction: x: to left; y: to inside; z: to upper
    # get the (left, outside, bottom) point
    size = (1.,1.,1.)
    o = [a - b / 2 for a, b in zip(pos, size)]
    #print o
    # get the length, width, and height
    l, w, h = size
    x = [[o[0], o[0] + l, o[0] + l, o[0], o[0]],  
         [o[0], o[0] + l, o[0] + l, o[0], o[0]],  
         [o[0], o[0] + l, o[0] + l, o[0], o[0]],  
         [o[0], o[0] + l, o[0] + l, o[0], o[0]]]  
    y = [[o[1], o[1], o[1] + w, o[1] + w, o[1]],  
         [o[1], o[1], o[1] + w, o[1] + w, o[1]],  
         [o[1], o[1], o[1], o[1], o[1]],          
         [o[1] + w, o[1] + w, o[1] + w, o[1] + w, o[1] + w]]   
    z = [[o[2], o[2], o[2], o[2], o[2]],                       
         [o[2] + h, o[2] + h, o[2] + h, o[2] + h, o[2] + h],   
         [o[2], o[2], o[2] + h, o[2] + h, o[2]],               
         [o[2], o[2], o[2] + h, o[2] + h, o[2]]]               
    return x, y, z

def plotCubeAt(pos=(0,0,0),ax=None):
  # Plotting a cube element at position pos
  if ax !=None:
    X, Y, Z = cuboid_data( pos )
    print X
    print Y
    print Z
    ax.plot_surface(X, Y, Z, color='b', rstride=1, cstride=1, alpha=0.25)

def plotMatrix(ax, matrix):
  # plot a Matrix 
  for i in range(matrix.shape[0]):
    for j in range(matrix.shape[1]):
      for k in range(matrix.shape[2]):
        if matrix[i,j,k] == 1:
          # to have the 
          plotCubeAt(pos=(i-0.5,j-0.5,k-0.5), ax=ax)            

N1 = 10
N2 = 10
N3 = 10
ma = np.random.choice([0,1], size=(N1,N2,N3), p=[0.99, 0.01])
#print ma

x=1
y=1
z=1

fig = plt.figure()
ax = fig.gca(projection='3d')
ax.set_aspect('equal')

plotCubeAt(pos=(x,y,z), ax=ax)

X  = [x, x+1, x+2]
Y  = [y, y-1, y+1]
Z  = [z, z+1, z]
ax.plot(X,Y,Z)
plt.show()




###   fig = plt.figure()
###   ax = fig.gca(projection='3d')
###   ax.set_aspect('equal')
###   
###   plotMatrix(ax, ma)
###   
###   plt.show()


