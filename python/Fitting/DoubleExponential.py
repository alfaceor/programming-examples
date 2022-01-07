#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18}

plt.rc('font', **font)
plt.rc('text', usetex=True)

from scipy.optimize import curve_fit

def doubleExp(X, A1, b1, A2, b2):
  return A1*np.exp(-b1*X)+A2*np.exp(-b2*X)

def line(X, m, b):
  return m*X+b

X=np.arange(-7,10,0.01)
aa=0.1
Y=3*X+4.25218 +aa*np.random.random(len(X))
A1=1.;A2=1.;
b1=0.1;b2=0.01;

Y=doubleExp(X, A1, b1, A2, b2)+aa*np.random.random(len(X))

popt=curve_fit(doubleExp, X, Y)
print popt
plt.plot(X,Y)
plt.plot(X,doubleExp(X, popt[0][0], popt[0][1], popt[0][2], popt[0][3]))



