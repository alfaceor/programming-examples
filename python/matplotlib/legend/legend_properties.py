#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

XX = np.arange(0,20)
YY = np.sin(XX)

fig, ax = plt.subplots()

ax.plot(XX, YY, label="100")
ax.plot(XX, 2*YY, label="20")

handles, labels = ax.get_legend_handles_labels()
legenda = ax.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.75,0.03), loc="lower left", title="$titulo$", prop={'size':10}, frameon=False, numpoints=1, handlelength=0.5)

for a in legenda.get_texts():
  a.set_ha("right")
  a.set_position((20,0))

if legenda :
  legenda.set_bbox_to_anchor((1,0.5), transform=None)
  legenda.draggable()

plt.show()
