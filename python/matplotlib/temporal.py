#!/usr/bin/python
import matplotlib.pyplot as plt 
import matplotlib.ticker as mtick
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)
xs = np.logspace(1,10,10)

ax.plot(xs,range(10))
ax.set_xscale('log')

#the next line is generally wrong, it works just as an example
#ax.xaxis.set_major_formatter(mtick.FuncFormatter(lambda value,pos: ("$10^{%d}$" % pos) ))

#this way change the ticks formats
#import math
#ax.xaxis.set_major_formatter(mtick.FuncFormatter(lambda v,_: ("$10^{%d}$" % math.log(v,10)) ))

#maybe this is what you want
ax.xaxis.set_major_formatter(mtick.ScalarFormatter(useMathText=True))

plt.show()
