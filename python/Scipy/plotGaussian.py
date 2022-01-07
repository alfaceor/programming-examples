#!/usr/bin/python

import numpy as np
import matplotlib.pyplot  as plt
from scipy.stats import norm

fig, ax = plt.subplots()

XX = np.linspace(-4,4, num=50)
YY = norm.pdf(XX)
delta = XX[1] - XX[0]
print YY.sum(), XX*YY, (delta*YY).sum()
ax.plot(XX, YY, '-o')

plt.show()
