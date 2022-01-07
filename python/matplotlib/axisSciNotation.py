#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as mtick

###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18} 
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES



XX = np.linspace(0.0000001, 0.000001, num=20 )
YY = np.linspace(100000, 100002, 20) 

fig, ax = plt.subplots()
ax.set_xlabel("$\sqrt{x}$", size=30)

ax.tick_params(axis='x', labelsize=10)
ax.tick_params(axis='y', labelsize=10)  

ax.ticklabel_format(useOffset=True, useMathText=True, style='sci', axis='x', scilimits=(0,0) )
ax.ticklabel_format( useMathText=True, style='sci', axis='y', scilimits=(0,0) )
#ax.ticklabel_format(useOffset=False)

offset = ax.yaxis.get_offset_text()
print offset
print offset.get_position()
offset.set_x(0.2)
offset.set_y(1.0)
offset.set_fontsize(10)
print "get_text()   = ", offset.get_text()
print "get_usetex() = ", offset.get_usetex()
print offset.get_position()
offset.set_usetex("AAA")
print "get_text() = ", offset.get_text()

ax.plot(XX,YY)

#ax.xaxis.set_major_formatter(mtick.ScalarFormatter(useMathText=True))

fig.tight_layout()

plt.show()
