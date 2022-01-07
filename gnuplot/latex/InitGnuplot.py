#!/usr/bin/python

filein ="template.gnu"
fileout="joder.gnu"
f = open(filein,'r')
filedata = f.read()
f.close()

newdata = filedata.replace("old data","new data")

f = open(fileout,'w')
f.write(newdata)
f.close()


