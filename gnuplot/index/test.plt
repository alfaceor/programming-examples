#!/usr/bin/gnuplot

plot \
'test.dat' i 0 u 1:2 w lines title columnheader(1),\
'test.dat' i 1 u 1:2 w lines title columnheader(1)
