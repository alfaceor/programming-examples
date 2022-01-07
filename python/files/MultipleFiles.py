#!/usr/bin/python
import numpy as np
import time

strHradList = ["10", "20", "40", "80", "100", "160"]
ofileList   = [ open("fileNum_"+strHradList[i], "w") for i in range(len(strHradList))]

# write on the files
for ofi in range(len(ofileList)):
  ofileList[ofi].write("foda-se**"+strHradList[ofi]+"\n") 

# close files
for ofi in range(len(ofileList)):
  ofileList[ofi].close()

##str.format("{0:.32f}",k4)
