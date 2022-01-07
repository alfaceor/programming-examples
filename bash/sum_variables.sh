#!/bin/bash

one="1"
echo "1+2*1 = " $((1+2*${one}))

listHrad="10 20 40 80 160" # 320"
for Hrad in ${listHrad}
do
  Brad=$(( ${Hrad} +1 ))
  echo ${Brad}
done

