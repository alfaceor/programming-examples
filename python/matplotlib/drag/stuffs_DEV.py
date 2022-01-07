#!/usr/bin/python
# 1. Create 3 figures
# 1.1. line figures.
# 1.2. fit figures
# 1.3. Result figure

"""
Enable picking on the legend to toggle the original line on and off
"""
import numpy as np
import matplotlib.pyplot as plt

XX = np.arange(0.0, 2.*np.pi, 0.1)
figLines, axLines = plt.subplots()
#axLines.set_title('Click on legend line to toggle line on/off')
Nlines = 5
Lines  = [None for i in range(Nlines)]
lined  = dict()
for i in range(Nlines):
  YY = 2*np.sin(XX+ 0.1*np.pi*i)
  lineaux, = axLines.plot(XX, YY, lw=2, label="i="+str(i))
  Lines[i] = lineaux
  print lineaux.get_label(), type(lineaux)


#line2, = axLines.plot(t, y2, lw=2, color='blue', label='2 HZ')
#leg = axLines.legend(loc='lower left', fancybox=True, shadow=True, title="leg title")
leg = axLines.legend(loc='lower left', title="leg title")
#leg.get_frame().set_alpha(0.4)

for legline, origline in zip(leg.get_lines(), Lines):
  legline.set_picker(5)  # 5 pts tolerance
  lined[legline] = origline


def onpick(event):
  # on the pick event, find the orig line corresponding to the
  # legend proxy line, and toggle the visibility
  legline = event.artist
  origline = lined[legline]
  vis = not origline.get_visible()
  origline.set_visible(vis)
  # Change the alpha on the line in the legend so we can see what lines
  # have been toggled
  if vis:
    legline.set_alpha(1.0)
  else:
    legline.set_alpha(0.2)
  print vis
  figLines.canvas.draw()

figLines.canvas.mpl_connect('pick_event', onpick)

#if leg :
#  leg.draggable()

plt.show()
