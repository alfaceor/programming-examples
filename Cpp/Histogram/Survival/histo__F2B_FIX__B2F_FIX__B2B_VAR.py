#!/usr/bin/python

import numpy as np
import scipy.stats
from matplotlib import colors
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import matplotlib.ticker as ticker
###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18} 
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES

#rw3D_SurvivalSphereBorder_F2B_1.0__B2F_0.0001__B2B_1.0__Hrad_10__Brad_11.his
strF2B = "1.0"
strB2F = "1.0"
#strB2FList = ["0.0001", "0.001", "0.01", "0.1", "1.0"] 
#strB2B = "1.0" 
strB2BList = ["0.001", "0.01", "0.1", "1.0"] 
strHrad = "10"
strBrad = "11"
marcador     = ["o",   "v",   "^",   "D",    "s",    "p",   "h"  ]


#fig, ax = plt.subplots(1,2, figsize=(8,4))
fig, ax = plt.subplots(1,1, sharex=True, sharey=True, figsize=(8,7))
print fig.get_figheight(), fig.get_figwidth()
axHist = ax
axHist.set_xlabel("$ \\tau_{s}$", size=30)
#axHist.set_xlim((-2*np.sqrt(tau),2*np.sqrt(tau)))
#axHist.text(4, 0.16, "$ p_{F \\to B} = "+strF2B+"$", fontdict=font)

axHist.set_yscale("log")
axHist.set_xlim((0,60))

for i in range(len(strB2BList)):
  strB2B = strB2BList[i]
  # rw3D_SurvivalSphereBorder_F2B_1.0__B2F_0.0001__B2B_1.0__Hrad_10__Brad_11.his
  inFln = "rw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".his"
  data = np.loadtxt(inFln)
  colorcito  = plt.cm.Paired(1.0*float(i)/float(len(strB2BList)))
  bins = (data[:,0]+ data[:,1])/2.0 
  print data[1,0]-data[0,0]
  freq = data[:,2]
  print "-"*10
  axHist.plot(bins, freq, marker=marcador[i], markersize=6, linewidth=0, markeredgecolor=colorcito, color=colorcito, label="$"+strB2B+"$")

handles, labels = axHist.get_legend_handles_labels()
axHist.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.8,0.3), loc="lower left", title="$p_{B \\to B}$", prop={'size':12}, frameon=False, numpoints=1)
#axHist.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.0,0.3), loc="lower left", title="$p_{B \\to B}$", prop={'size':12}, frameon=False, numpoints=1)

#fig.tight_layout()
outFilename = "Histogram_"+"rw3D_SurvivalSphereBorder_F2B_"+"VAR"+"__B2F_"+strB2F+"__B2B_"+"VAR"+"__Hrad_"+strHrad+"__Brad_"+strBrad+".pdf"
fig.savefig(outFilename)
plt.show()



