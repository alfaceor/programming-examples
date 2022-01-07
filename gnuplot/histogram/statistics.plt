#stats "data.dat" u 1
#print STATS_records
#print STATS_mean


###stats "data.dat" u ($0 > 1000 ?$1:1/0) name "S1"
###stats "data.dat" u ($0 <=1000 ?$2:1/0) name "S2"

set table 'ohshit.dat'
set xrange [0:10]
plot [0:20] "data.dat" u 0:1
unset table

stats [1:10]  "data.dat" u 1 name "S1" nooutput
stats [100:]  "data.dat" u 1 name "S2" nooutput
print S1_records
print S1_mean
print S2_records
print S2_mean
