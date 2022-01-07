#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
data=np.loadtxt("RRR.dat")

#plt.imshow(data,interpolation='nearest')
#data=np.random.random((5,5))
print data
plt.imshow(data,interpolation='nearest')

plt.show()
print len(data)




fig, ax = plt.subplots()
#grid = np.mgrid[0.2:0.8:3j, 0.2:0.8:3j].reshape(2, -1).T

patches = []


rect = mpatches.Rectangle(grid[1] - [0.025, 0.05], 0.05, 0.1, ec="none")
patches.append(rect)
#label(grid[1], "Rectangle")

collection = PatchCollection(patches, cmap=plt.cm.hsv, alpha=0.3)

ax.add_collection(collection)

plt.show()


