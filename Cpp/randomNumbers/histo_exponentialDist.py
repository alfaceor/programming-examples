#!/usr/bin/python
from numpy.random import normal
from numpy import loadtxt
gaussian_numbers = normal(size=1000)
# print gaussian_numbers
import matplotlib.pyplot as plt
from numpy.random import normal
gaussian_numbers = normal(size=1000)
data = loadtxt("data.txt")

plt.hist(data, normed=1)
plt.yscale("log")
plt.title("Gaussian Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")

data = loadtxt("rw_exponential.his")

bins  = 0.5*(data[:,0] + data[:,1])
freqs = data[:,2]
plt.plot(bins, freqs)


plt.show()
