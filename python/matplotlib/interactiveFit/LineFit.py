#!/usr/bin/python

from matplotlib import pyplot as plt

class LineFit:
  def __init__(self, linea):
    self.linea = linea
    self.xs = list(linea.get_xdata())
    self.ys = list(linea.get_ydata())
    self.cid = linea.figure.canvas.mpl_connect('button_press_event', self)

  def __call__(self, event):
    print 'click', event
    if event.inaxes!=self.linea.axes: return
    self.xs.append(event.xdata)
    self.ys.append(event.ydata)
    self.linea.set_data(self.xs, self.ys)
    self.linea.figure.canvas.draw()

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_title('click to build linea segments')
linea, = ax.plot([0], [0])  # empty line
linebuilder = LineFit(linea)

# First fitline

# change the range of the fit

plt.show()

