#!/usr/bin/python
import scipy.stats
import numpy as np

#x = scipy.linspace(-100,100,201)
x = np.linspace(-100,100,201)
print x
pmf = scipy.stats.binom.pmf(x,100,0.5, loc=-50)
import matplotlib.pyplot as plt
plt.plot(x,pmf)
print pmf
plt.show()

