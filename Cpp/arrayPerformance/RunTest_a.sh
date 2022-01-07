#!/bin/bash

list="10 20 30 40 50 100 200 300 400 500 600 700"
list="10 20 30 40 50"
for i in ${list}
do
  #echo $i
  ./array3Das1D_a $i
done
