#!/usr/bin/gnuplot 


set style line  1 lt 0 lw 2 pt 64 ps 1.5 lc rgb '#0072bd' # blue
set style line  2 lt 0 lw 2 pt  5 ps 1.5 lc rgb '#d95319' # orange
set style line  3 lt 0 lw 2 pt 65 ps 1.5 lc rgb '#7e2f8e' # purple
set style line  4 lt 0 lw 2 pt  7 ps 1.5 lc rgb '#edb120' #ed1000' # yellow
set style line  5 lt 0 lw 2 pt 66 ps 2   lc rgb '#77ac30' # green
set style line  6 lt 0 lw 2 pt  9 ps 2   lc rgb '#4dbeee' # light-blue
set style line  7 lt 0 lw 2 pt 67 ps 2   lc rgb '#a2142f' # red
set style line  8 lt 0 lw 2 pt 11 ps 2   lc rgb '#b15928' # light-purple
set style line  9 lt 0 lw 2 pt 68 ps 2   lc rgb '#6a3d9a' # red
set style line 10 lt 0 lw 2 pt 13 ps 2   lc rgb '#ff7f00' # red

set xlabel "x"

pl \
sin(x)   w l ls  1 , \
cos(x)   w l ls  2 , \
cos(2*x) w l ls  3 #, \


