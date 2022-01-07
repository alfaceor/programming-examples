#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def Gauss(x, A, beta):
  return A*np.exp(-beta*x**2)


def fitGauss(xdata,ydata):
  popt, pcov = curve_fit(Gauss, xdata, ydata)
  return popt, pcov


A=0.4
beta=1.
XX = np.arange(-10,10,0.02)
YY = Gauss(XX, A, beta)
YY = YY+ 0.1*(0.5-np.random.random(len(YY))) 

fig, ax = plt.subplots()
ax.plot(XX,YY, 'o')

popt, pcov = fitGauss(XX,YY)
ax.plot(XX, Gauss(XX, popt[0], popt[1]), 'r', linewidth=2)
print popt[0], popt[1]
fig.tight_layout()
plt.show()


