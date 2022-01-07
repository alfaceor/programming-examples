#!/usr/bin/gnuplot
set pm3d depthorder
splot "datafile.dat" u 1:2:3:-2 w pm3d
