#!/usr/bin/gnuplot
load 'set1.pal'

set yrange [-3:3]
set y2range [-25:25]

plot './PQ__T1_0.40_a_0.00.dat' \
   u 1:2 w l ls 1 t "p", \
'' u 1:3 w l ls 2 t "q" axes x1y2, \
'' u 1:4 w l ls 4 t "a", \
'' u 1:5 w l ls 3 t "dW"
