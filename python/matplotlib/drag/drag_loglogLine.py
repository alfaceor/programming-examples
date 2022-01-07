#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

class DraggableLogLogLine:
  def __init__(self, linea):
    self.linea = linea
    self.press = None

  def connect(self):
    'connect to all the events we need'
    self.cidpress = self.linea.figure.canvas.mpl_connect(
      'button_press_event', self.on_press)
    self.cidrelease = self.linea.figure.canvas.mpl_connect(
      'button_release_event', self.on_release)
    self.cidmotion = self.linea.figure.canvas.mpl_connect(
      'motion_notify_event', self.on_motion)

  def on_press(self, event):
    'on button press we will see if the mouse is over us and store some data'
    if event.inaxes != self.linea.axes: return

    contains, attrd = self.linea.contains(event)
    if not contains: return
    #print('event contains', self.linea.xy)
    #x0, y0 = self.linea.xy
    x0 = self.linea.get_xdata()
    y0 = self.linea.get_ydata()
    self.press = x0, y0, event.xdata, event.ydata

  def on_motion(self, event):
    'on motion we will move the linea if the mouse is over us'
    if self.press is None: return
    if event.inaxes != self.linea.axes: return
    x0, y0, xpress, ypress = self.press
    dx = event.xdata / xpress
    dy = event.ydata / ypress
    #print('x0=%f, xpress=%f, event.xdata=%f, dx=%f, x0+dx=%f' %
    #   (x0, xpress, event.xdata, dx, x0+dx))
    self.linea.set_xdata(x0*dx)
    self.linea.set_ydata(y0*dy)

    self.linea.figure.canvas.draw()


  def on_release(self, event):
    'on release we reset the press data'
    self.press = None
    self.linea.figure.canvas.draw()

  def disconnect(self):
    'disconnect all the stored connection ids'
    self.linea.figure.canvas.mpl_disconnect(self.cidpress)
    self.linea.figure.canvas.mpl_disconnect(self.cidrelease)
    self.linea.figure.canvas.mpl_disconnect(self.cidmotion)

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xscale("log")
ax.set_yscale("log")
XX = np.linspace(0,100)
YY = XX
#rects = ax.bar(range(10), 20*np.random.rand(10))
linea, = ax.plot(XX, YY)
dr = DraggableLogLogLine(linea)
dr.connect()
plt.show()

###  drs = []
###  for linea in lineas:
###    print "joder"
###    dr = Draggablelinea(linea)
###    dr.connect()
###    drs.append(dr)
###  


