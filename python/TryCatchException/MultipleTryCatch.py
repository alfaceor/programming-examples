#!/usr/bin/python
import numpy as np

flnList=["NoSuchAFile.txt", "NoExite.dat", "data.txt", "tampoco.txt", "data2.txt"]
ifln = 0
while ifln < len(flnList):
  try:
    filename = flnList[ifln]
    data = np.loadtxt(filename)
    break;
  except IOError as e:
    print e
    pass
  ifln = ifln + 1

print data
print "Fuck U!!!"
