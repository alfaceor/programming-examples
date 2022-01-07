#!/usr/bin/python
import scipy, scipy.stats
x = scipy.linspace(-10,10,21)
print x
pmf = scipy.stats.binom.pmf(x,10,0.1)
import matplotlib.pyplot as plt
plt.plot(x,pmf)
print pmf
plt.show()

