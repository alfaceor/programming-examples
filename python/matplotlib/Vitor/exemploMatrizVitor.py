import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

data=np.loadtxt("matriz.dat")

cax = ax.imshow(data, interpolation='nearest', cmap=cm.coolwarm)
#ax.set_title('Gaussian noise with vertical colorbar')

# Add colorbar, make sure to specify tick locations to match desired ticklabels
cbar = fig.colorbar(cax, ticks=[-1, 0, 1])
#cbar.ax.set_yticklabels(['< -1', '0', '> 1'])  # vertically oriented colorbar

plt.show()

