#!/usr/bin/python

import csv

iniHrad=10
inipBF=0.0025
HradList = [iniHrad*(2**i) for i in range(6)]
BradList = [hr+1 for hr in HradList]
B2FList  = [1./(2.*hr)**2. for hr in HradList]
  
strB2FList  = map(str, B2FList ) 
strHradList = map(str, HradList) 
strBradList = map(str, BradList) 

print strHradList, HradList
print strBradList, BradList
print strB2FList,  B2FList

#print '{:f}'.format(3.141592653589793)
