#!/usr/bin/python
# REF: https://nbviewer.jupyter.org/github/lmmentel/mendeleev/blob/master/docs/source/notebooks/03_plotting.ipynb

from mendeleev import get_table
from mendeleev.plotting import periodic_plot

ptable = get_table('elements')
print ptable.keys()
print ptable.keys()
#print ptable['block']
#print type(ptable['block'])

import seaborn as sns
from matplotlib import colors
blockcmap = {b : colors.rgb2hex(c) for b, c in zip(['s', 'p', 'd', 'f'], sns.color_palette('deep'))}
ptable['block_color'] = ptable['block'].map(blockcmap)
periodic_plot(ptable, colorby='block_color')


print len(sns.color_palette('deep'))

