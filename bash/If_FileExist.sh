#!/bin/bash

flname=rw2D_RegularPorousDepletion_F2B_0.6__B2F_0.8__B2B_0.2__nt_1000000.dat
if [ -f ${flname} ]; then
  echo "Oh yeah"
else
  echo "fuck u the file do not exist"
fi
