#!/usr/bin/gnuplot

step(x)=(x>5? 1/0: 1)
pl \
'./data.dat' u ($1):($2) w l, \
'./data.dat' u (step($1)):($2) w l


#pl \
#sin(x)  w l, \
#sin(x)*step(x)  w l
