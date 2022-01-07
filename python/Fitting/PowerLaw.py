#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def powLaw(x, m, b):
  return np.exp(b)*x**m

def line(x, m, b):
  return m*x+b

def fitPowLaw(xdata,ydata):
  popt, pcov = curve_fit(line, np.log(xdata), np.log(ydata))
  return popt, pcov
