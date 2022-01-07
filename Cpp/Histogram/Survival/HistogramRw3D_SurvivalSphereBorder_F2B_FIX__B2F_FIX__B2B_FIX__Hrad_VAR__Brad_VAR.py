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
strB2B="0.01"
#strB2BList  = ["1.0", "0.1", "0.01", "0.001"]
strHradList = ["10", "50"]
strBradList = ["11", "51"]

figHist, axHist = plt.subplots()
axHist.set_yscale("log")
axHist.set_xlabel("$\\tau_s$", fontsize=30)

axHist.set_xlim((0,500))

#colvals = np.abs(np.log( map(float, strB2BList)))+3.0
colvals = np.abs(np.log( map(float, strHradList)))+3.0
colvals = colvals/colvals.max()

for hr in range(len(strHradList)):
  strHrad = strHradList[hr]
  strBrad = strBradList[hr]
  #rw3D_SurvivalSphereBorder_F2B_1.0__B2F_0.1__B2B_0.01__Hrad_10__Brad_11.his
  inFilename="rw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".his"
  data = np.loadtxt(inFilename)
  bins = 0.5*(data[:,0]+data[:,1] )
  freq = data[:,2]
  colorcito=plt.cm.YlGnBu(colvals[hr])
  axHist.plot(bins, freq, marker="o", markersize=6, linewidth=0, markeredgecolor=colorcito, color=colorcito, label="$"+strHrad+"$")

handles, labels = axHist.get_legend_handles_labels()
axHist.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.8,0.4), loc="lower left", title="$R_H$", prop={'size':12}, frameon=False, numpoints=1)

figHist.tight_layout()
plt.show()

