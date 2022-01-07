#!/usr/bin/python

import matplotlib.pyplot as plt

fig, ax = plt.subplots(2,1, sharex=True)

SeqStart=0
SeqEnd =10
y=0
ax[0].plot([SeqStart, SeqEnd],[y,y])
ax[1].plot([SeqStart, SeqEnd],[y,y])

plt.show()

