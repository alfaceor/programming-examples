#!/usr/bin/python
import numpy as np
import time

buffersize=0
ofile = open("outfilename.dat", "a", buffersize)
for i in np.arange(10):
	ofile.write(str(i)+" "+str(np.pi)+"\n")

time.sleep(10)
ofile.write("The job is finish\n")
ofile.close()

##str.format("{0:.32f}",k4)
