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

fig, ax = plt.subplots()

ax.set_xlabel("$ v $", size=30)
ax.set_ylabel("$ P(v) $", rotation=0, size=30)

ax.set_xlim(-5, 5)
#ax.set_ylim(-2.5, 2.5)

strTimeList = map(str, [2**i for i in range(11)])
print strTimeList
for i in range(len(strTimeList)):
  strTime = strTimeList[i]
  data = np.loadtxt("Histo_v__ts_"+strTime+".his")
  bins = np.mean(data[:,0:2], axis=1)
  v    = data[:,2]
  print strTime, (data[0,1] - data[0,0])*v.sum()
  colorcito = plt.cm.Reds(float(i)/float(len(strTimeList)))
  ax.plot(bins, v, "-", color=colorcito)

KT = 2.0
XX = np.linspace(-5, 5, 50)
def Gauss(XX, KT):
  return ( (2.0*np.pi*KT)**(-0.5) )*np.exp( (-XX**2.0) / (2.0*KT) )

print (XX[1] - XX[0]) *Gauss(XX, KT).sum()
ax.plot(XX, Gauss(XX, KT) , linestyle="--", color="k" )
#ax.plot(XX, ( (2.0*np.pi*KT)**(-0.5) )*np.exp( (-XX**2.0) / (2.0*KT) ), linestyle="--", color="k" )

###  ax2 = ax.twinx()
###  
###  ax2.set_ylabel("$ v $", color='r', rotation=0, size=30)
###  ax2.set_ylim(-2.5, 2.5)
###  
###  ax2.plot(time, v, "-", color="r")

fig.tight_layout()
plt.show()

