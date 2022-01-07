#!/bin/bash
Hrad="100"
Brad="101"
B2FList="1.0 0.1 0.01 0.001"
B2BList="1.0 0.1 0.01 0.001"
for B2F in ${B2FList}
do
  for B2B in ${B2BList}
  do
    ./rw3D_SurvivalSphereBorder_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius --pF2B 1.0 --pB2F ${B2F} --pB2B ${B2B} --Hrad ${Hrad} --Brad ${Brad}
  done
done
