#!/usr/bin/python

separator=","
with open("readFileLineByLine.csv", "r") as f:
  for line in f:
     print line.split(separator) 
