#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

from scipy.optimize import curve_fit
def func(x, a, b, c):
  return a * np.exp(-b * x) + c

def gauss(x, mu, sigma):
  return  np.exp( -0.5*((x-mu)/sigma)**2)/(sigma*np.sqrt(2*np.pi))

xdata = np.linspace(-4, 4, 50)
#y = func(xdata, 2.5, 1.3, 0.5)
y = gauss(xdata, 0, 1)
ydata = y + 0.02 * np.random.normal(size=len(xdata))


#popt, pcov = curve_fit(func, xdata, ydata)
popt, pcov = curve_fit(gauss, xdata, ydata)
print len(popt), len(xdata)
print popt
plt.plot(xdata, gauss(xdata,popt[0], popt[1]))
plt.plot(xdata, ydata)
plt.show()

