#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

XX = np.arange(0,20)
YY = np.sin(XX)

fig, ax = plt.subplots()

ax.plot(XX, YY, label="100")
ax.plot(XX, 2*YY, label="20")

legenda = ax.legend()

for a in legenda.get_texts():
  a.set_ha("right")
  a.set_position((20,0))


plt.show()
