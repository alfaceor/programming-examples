#!/usr/bin/python

import matplotlib
import matplotlib.pyplot as plt

fig = plt.figure() 

rect1 = matplotlib.patches.Rectangle(( 0.5,-0.25), 1, 0.5)
rect2 = matplotlib.patches.Rectangle((-0.5, 0.75), 4, 0.5)

#fig.add_patch(rect1)
#rect.set_xy((0, 0.75))
fig.patches.extend([rect1, rect2])

plt.show()
