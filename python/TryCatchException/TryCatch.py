#!/usr/bin/python
import numpy as np

for i in range(4):
  try:
    data = np.loadtxt("NoExiste.dat")
  except IOError as e:
    print "Oops!"
    pass

for i in range(5):
  try:
    data = np.loadtxt("NoExiste.dat")
  except IOError as e:
    print "NO PASS!"
    break

print "Fuck U!!!"
