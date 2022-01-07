#!/usr/bin/python
import matplotlib.pyplot as plt
import numpy as np

plt.ion()
fig, ax = plt.subplots()
ax.set_xlim(0, 2.*np.pi)
XX = np.linspace(0,2.*np.pi, 100)

for i in range(4):
  ax.plot(XX, np.sin(XX+i*np.pi/8.))
  plt.pause(3)
  plt.draw()

  
