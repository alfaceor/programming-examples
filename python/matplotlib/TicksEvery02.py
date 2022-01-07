#!/usr/bin/python
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [  2**i for i in range(10)] # [0,5,9,10,15]
y = [ 10**i for i in range(10)] # [0,1,2,3,4]

tick_spacing = 4

fig, ax = plt.subplots(1,1)
#ax.set_xscale("log")
ax.set_yscale("log")
ax.plot(x,y)
ax.locator_params(axis='x', nbins=8)
#ax.xaxis.set_major_locator(ticker.MultipleLocator(tick_spacing))
plt.show()
