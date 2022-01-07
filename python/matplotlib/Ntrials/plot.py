#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

strNtrialsList = ["1000000" , "100000" , "10000"  ] #, "1000", "100" , "10", "1"]

fig, ax = plt.subplots()
ax.set_xscale("log")
ax.set_yscale("log")
for nn in range(len(strNtrialsList)) :
  strNtrials = strNtrialsList[nn]
  flname="rw3D_RegularPorousDepletion_F2B_1.0__B2F_0.0001__B2B_0.0001__Hrad_100__Brad_101__nt_"+strNtrials+".dat"
  data = np.loadtxt(flname)
  ax.plot(data[:,0], data[:,5], label="$"+strNtrials+"$")

ax.legend(loc="best", title="$Ntrials$", prop={'size':12}, frameon=False)
plt.show()
