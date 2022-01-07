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

strF2B="1.0"
strB2F="0.1"
strB2BList=["0.001", "0.01", "0.1", "1.0"]
strHrad="10"
strBrad="11"

marcador     = ["o",   "v",   "^",   "D",    "s",    "p",   "h"  ]

figHist, axHist = plt.subplots()
axHist.set_yscale("log")

axHist.set_xlim((0,500))

axHist.set_xlabel("$\\tau_s$", fontsize=30)

colvals = np.abs(np.log( map(float, strB2BList)))+3.0
colvals = colvals/colvals.max()

for b2b in range(len(strB2BList)):
  strB2B = strB2BList[b2b]
  #rw3D_SurvivalSphereBorder_F2B_1.0__B2F_0.1__B2B_0.01__Hrad_10__Brad_11.his
  inFilename="rw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".his"
  data = np.loadtxt(inFilename)
  bins = 0.5*(data[:,0]+data[:,1] )
  freq = data[:,2]
  colorcito=plt.cm.Purples(colvals[b2b])
  axHist.plot(bins, freq, marker=marcador[b2b], markersize=6, linewidth=0, markeredgecolor=colorcito, color=colorcito, label="$"+strB2B+"$")

handles, labels = axHist.get_legend_handles_labels()
axHist.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.8,0.4), loc="lower left", title="$p_{B \\to B}$", prop={'size':12}, frameon=False, numpoints=1)

figHist.tight_layout()

outFilename="HistogramRw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_VAR__Hrad_"+strHrad+"__Brad_"+strBrad+".pdf"

print outFilename
figHist.savefig(outFilename)
plt.show()

