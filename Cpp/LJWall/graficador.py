#!/usr/bin/python -i
import numpy as np
import matplotlib.pyplot as plt


font = {'family' : 'normal',
         'weight' : 'bold',
         'size'   : 30}
plt.rc('font', **font)
plt.rc('text', usetex=True)

data = np.loadtxt("output.dat")


fig1 = plt.figure()
ax1 = fig1.add_subplot(111)
ax2 = plt.axes([.25, .25, .2, .3])

ax2.plot(data[:,0],data[:,1],'x-')
ax2.plot(data[:,0],data[:,2],'x-')
ax2.plot(data[:,0],data[:,3],'x-')
ax2.set_xlim(-10.5,-10)
ax2.set_ylim(0,20)
ax2.locator_params(axis='both',nbins=4)

ax1.plot(data[:,0],data[:,1], label="$\epsilon=0.1$")
ax1.plot(data[:,0],data[:,2], label="$\epsilon=0.5$")
ax1.plot(data[:,0],data[:,3], label="$\epsilon=1.0$")
ax1.set_xlim(-12,12)
ax1.set_ylim(0,100)
ax1.set_xlabel("$x$")
ax1.set_ylabel("$\Phi^{Wall} (x)$")
ax1.locator_params(axis='both',nbins=8)

ax1.grid()
ax1.legend()
plt.show()
