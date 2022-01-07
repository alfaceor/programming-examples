#!/usr/bin/python
# The idea is to have a file with the experiments and the parameters to simulate (Run in the cluster) after that, use the same file to plot and analize the data I want.
import csv

with open('Read_csv_file_02.csv') as csvfile:
  mpg = list(csv.DictReader(csvfile))

print mpg
print "= "*10
print mpg[0] #["strB2F"]
print "=--="*10
print mpg[0]["strB2F"]

print len(mpg)


