#!/bin/bash

while IFS=, read -r col1 col2
do
    #echo "I got:$col1|$col2"
    echo "I got:$col1|$col2"
done < csvfile.csv
