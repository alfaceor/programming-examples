#!/usr/bin/python

from mendeleev import get_table
from mendeleev.plotting import periodic_plot

ptable = get_table('elements')
print ptable.keys()


periodic_plot(ptable)

