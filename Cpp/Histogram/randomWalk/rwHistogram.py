#!/usr/bin/python

import numpy as np 
import matplotlib.pyplot as plt

strHistoTimes =  ["1", "10", "100", "1000", "10000"];
flnPrefix = "jo__ts_" #".his", histoTimes[i] );
fig, ax = plt.subplots()
ax.set_yscale("log")
for i in range(len(strHistoTimes)):
  filename = flnPrefix+strHistoTimes[i]+".his"
  data = np.loadtxt(filename)
  hisTime = float(strHistoTimes[i])
  XX = 0.5*(data[:,0]+data[:,1])/np.sqrt(hisTime)
  YY = data[:,2]*np.sqrt(hisTime)
  ax.plot(XX, YY, "o")

plt.show()

