#!/usr/bin/python
import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("ThermoQuanTrialsBD_FPU__N_128__U0_0.4.dat")

lenData = len(data)
XX=np.arange(len(data[0])-1)

fig, ax = plt.subplots()
axTempProf = ax
for i in range(lenData):
  strTime = str(data[i][0])
  energy  = data[i,1:]
  axTempProf.plot(XX, energy)

plt.show()
