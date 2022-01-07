#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt
###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18}
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES

##### FITTING FUNCTIONS #####
from scipy.optimize import curve_fit
def line(x, m, b): 
  return m*x+b

def powLaw(x, m, b): 
  return np.exp(b)*x**m

def fitPowLaw(xdata, ydata):
  popt, pcov = curve_fit(line, np.log(xdata), np.log(ydata))
  return popt, pcov

#stats_mu_1.0.dat
strMu   = "1.0"
data    = np.loadtxt("stats_mu_"+strMu+".dat")
time    = data[:,0]
x_mean  = data[:,1]
x_var   = data[:,2]

fig, ax = plt.subplots()
ax.set_xscale("log")
ax.set_yscale("log")

ax.set_xlabel("$t$")
ax.set_ylabel("$\\langle \\Delta x^2 \\rangle $")

ax.plot(time, x_var, 'o-')
ax.plot(time, time, '--')

fig.tight_layout()
plt.show()

