#!/usr/bin/python
import numpy as np
#import matplotlib as mpl
import matplotlib.pyplot as plt

XX = np.linspace(0,10)
YY = np.sin(XX)

#mpl.rc_context(rc={'interactive': True})

fig1, ax1 = plt.subplots()
ax1.plot(XX, YY)

for i in range(4):
  fig2, ax2 = plt.subplots()
  ax1.plot(XX, i*YY+i*np.pi/4)
  #fig1.draw()
  ax2.plot(XX, np.cos(XX+i*np.pi/4), color='r')
  fig2.show()
  #plt.show()
  #plt.close()
  #input("Press [enter] to continue.")

  #plt.gcf().show()

fig3, ax3 = plt.subplots()
ax3.plot(XX, 0.1*XX, color='k')
fig3.show()
plt.show()
###   ###   plt.show()
###   fig2.show()
###   #fig2.draw()
###   print 10*"-"
###   
###   fig1.show()
print "JODER"


