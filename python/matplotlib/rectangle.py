#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.patches as mpatches
from matplotlib.collections import PatchCollection
data=np.loadtxt("RRR.dat")


fig, ax = plt.subplots()
grid = np.mgrid[0.2:0.8:3j, 2:8:3j].reshape(2, -1).T


print grid
patches = []


rect = mpatches.Rectangle(grid[1] - [0.025, 0.05], 0.05, 0.1, ec="none")
patches.append(rect)
#label(grid[1], "Rectangle")

collection = PatchCollection(patches, cmap=plt.cm.hsv, alpha=0.3)

ax.add_collection(collection)

plt.show()


