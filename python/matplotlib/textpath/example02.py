#!/usr/bin/python
from matplotlib.textpath import TextPath
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from matplotlib.path import Path

DNASeq='CARLOS'

#def Seq2polygon(Sequence):
#    x=0
#    letters = []
#    for char in Sequence:
#        tp = TextPath(x,y, char, size=1)
#        poly = tp.to_polygons()
#        x = x+1
#

fig=plt.figure()
ax1=fig.add_subplot(111)
ax1.set_ylim(-1 , 3)
ax1.set_xlim(-3, 15)
tp1=TextPath((0.0,0.5), DNASeq, size=2)
#tp1=TextPath((0.0,0.5), r'How do you turn this on?', size=2)
polygon=tp1.to_polygons()
print len(polygon)

for a in polygon:
    p1=patches.Polygon(a, fill=False)
    ax1.add_patch(p1)

plt.show()
