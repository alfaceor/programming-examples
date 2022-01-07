#!/usr/bin/python
from distutils.util import *

answers = ["yes", "no", "y", "n", "Y", "N", "on", "off", "True", "false" ] #, "", "A", "vtnc"]
#boolans = [None for i in range(len(answers))]
boolans = map( strtobool, answers)

print answers
print boolans

for i in range(len(answers)):
  print boolans[i],
  if boolans[i] : print " Its true "+"-->"+ answers[i],
  print ""
