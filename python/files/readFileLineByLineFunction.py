#!/usr/bin/python

def printFile(ofile):
  print ofile.readline()

ofile = open("readFileLineByLine.csv", "r")
#print ofile.readline()
printFile(ofile)
printFile(ofile)
printFile(ofile)

ofile.close()
