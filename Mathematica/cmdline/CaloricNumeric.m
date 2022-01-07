#!/usr/local/bin/MathematicaScript -script
Temp=0.08;
\[Epsilon]=1.0;
x0=50.0;
rul=FindRoot[BesselI[1,x]/BesselI[0,x]-(Temp/\[Epsilon]) x,{x,x0}]
xs=rul[[1,2]];
Mag = BesselI[1,xs]/BesselI[0,xs];
U = 0.5Temp + 0.5 \[Epsilon](1-Mag^2);

Print[U]
