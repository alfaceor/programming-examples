set logscale xy
plot "data.dat" u 1:2 w lp, "" u 1:2 w lp smooth csplines
