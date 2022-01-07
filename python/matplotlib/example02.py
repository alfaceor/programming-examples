#!/usr/bin/python

import matplotlib.pyplot as plt
import itertools
import warnings


fontsizes = itertools.cycle([8, 16, 24, 32])


def example_plot(ax):
    ax.plot([1, 2, next(fontsizes)])
    ax.set_xlabel('x-label', fontsize=next(fontsizes))
    ax.set_ylabel('y-label', fontsize=next(fontsizes))
    ax.set_title('Title', fontsize=next(fontsizes))


fig = plt.figure()

ax1 = plt.subplot(221)
ax2 = plt.subplot(222)
#ax3 = plt.subplot(122)
ax3 = plt.subplot(212)

example_plot(ax1)
example_plot(ax2)
example_plot(ax3)

plt.tight_layout()


###fig = plt.figure()
###
###ax1 = plt.subplot2grid((3, 3), (0, 0))
###ax2 = plt.subplot2grid((3, 3), (0, 1), colspan=2)
###ax3 = plt.subplot2grid((3, 3), (1, 0), colspan=2, rowspan=2)
###ax4 = plt.subplot2grid((3, 3), (1, 2), rowspan=2)
###
###example_plot(ax1)
###example_plot(ax2)
###example_plot(ax3)
###example_plot(ax4)
###
###plt.tight_layout()

plt.show()



