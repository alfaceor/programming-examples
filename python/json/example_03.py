#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def FitByPlot():
  figFit, axFit = plt.subplots()
  XX = np.linspace(0, 2.*np.pi)
  axFit.plot(XX, np.sin(XX))
  figFit.show()

import json
fit_params = json.load(open("D_fit.json"))
print fit_params["1.0"]  

fig, ax = plt.subplots()

XX = np.linspace(0, 2.*np.pi)
ax.plot(XX, np.cos(XX), color='r')

FitByPlot()
if fit_params["1.0"]["lambFlag"] == False :
  print "fit with fabio method"
#print fit_params.items()
#for key, value in fit_params.items():
#  print key, value.items()

plt.show()
