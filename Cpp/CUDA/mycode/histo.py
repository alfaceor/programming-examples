#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("random.dat")

plt.hist(data)

plt.show()
