#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
x = np.linspace(0,1)

for i in range(2):
  for j in range(2):
    y = (0.4*i+5*j)*np.linspace(0,1)
    ax.plot(x,y, label='i = %.2f, j = %.2f' %(i,j))
ax.legend()
plt.show()

