#!/usr/bin/python

import numpy as np 
import matplotlib.pyplot as plt

strF2B="1.0"
strB2F="0.1"
strB2B="0.01"
strHrad="10"
strBrad="11"
#rw3D_SurvivalSphereBorder_F2B_1.0__B2F_0.1__B2B_0.01__Hrad_10__Brad_11.his
inFilename="rw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".his"
data = np.loadtxt(inFilename)
XX = 0.5*(data[:,0]+data[:,1] )
YY = data[:,2]

fig, ax = plt.subplots()
ax.set_yscale("log")
ax.plot(XX, YY, "-o")
plt.show()

