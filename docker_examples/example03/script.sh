#!/bin/bash
#mkdir -p tmp
#echo "joder" > textfile.txt
#docker run -it -v "$(pwd)":/igor-data debian bash
docker build . -t digor:lasted

