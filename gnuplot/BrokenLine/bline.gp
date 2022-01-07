tiny=0.05
set multiplot
unset key
unset xlabel
set border 1+2+4
set lmargin at screen 0.10
set rmargin at screen 0.6
set bmargin at screen 0.15
set tmargin at screen 0.95
set ytics -1,0.5,1 nomirror
set xrange [0:2.5*pi]
set xtics ("0" 0, "{/Symbol p}" pi, "2{/Symbol p}" 2*pi)
set arrow 1 from 2.5*pi-tiny, -1-tiny to 2.5*pi+tiny, -1+tiny nohead
set arrow 2 from 2.5*pi-tiny, 1-tiny to 2.5*pi+tiny, 1+tiny nohead

plot cos(x)

unset ytics
set border 1+4+8
set key right
set lmargin at screen 0.63
set rmargin at screen 0.93
set bmargin at screen 0.15
set tmargin at screen 0.95
set label 1 'cos(x)' at screen 0.5, 0.05 centre
set xrange [4.5*pi:6*pi]
set xtics ("5{/Symbol p}" 5*pi, "6{/Symbol p}" 6*pi)
set arrow 1 from 4.5*pi-tiny, -1-tiny to 4.5*pi+tiny, -1+tiny nohead
set arrow 2 from 4.5*pi-tiny, 1-tiny to 4.5*pi+tiny, 1+tiny nohead

plot cos(x)

unset multiplot

