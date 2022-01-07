#!/usr/bin/gnuplot
set cbrange [0.9:1]
set palette defined (1 '#ce4c7d')
set style line 1 lc rgb '#b90046' lt 1 lw 0.5
set pm3d depthorder hidden3d
set pm3d implicit
unset hidden3d
#splot 'cube.txt' u 1:2:3:(1) w l ls 1


# gnuplot function to create a cube
# 
# Usage: cube(x,y,z,c)
cube(x,y,z,c) = sprintf('<echo "\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i\n\
%f %f %f %i"',\
0+x,0+y,0+z,c,\
0+x,0+y,1+z,c,\
0+x,1+y,1+z,c,\
0+x,1+y,0+z,c,\
0+x,0+y,0+z,c,\
1+x,0+y,0+z,c,\
1+x,0+y,1+z,c,\
1+x,1+y,1+z,c,\
1+x,1+y,0+z,c,\
1+x,0+y,0+z,c,\
0+x,0+y,0+z,c,\
1+x,0+y,0+z,c,\
1+x,1+y,0+z,c,\
0+x,1+y,0+z,c,\
0+x,0+y,0+z,c,\
0+x,0+y,1+z,c,\
1+x,0+y,1+z,c,\
1+x,1+y,1+z,c,\
0+x,1+y,1+z,c,\
0+x,0+y,1+z,c\
)



add_cube(x,y,z,c) = sprintf('cube(%f,%f,%f,%i) w l ls %i,',x,y,z,c,c)
CMD = ''
stats 'cube_positions.txt' u 1:(CMD = CMD.add_cube($1,$2,$3,$4)) nooutput
CMD = 'splot '.CMD.'1/0 w l ls 2'
eval(CMD)