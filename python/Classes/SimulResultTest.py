#!/usr/bin/python

import SimulResult as sr
import numpy as np

flnPrefix="rw3D_RegularPorousDepletion"
strNtrials = str(10**5)

strF2B  = "1.0"
strB2F  = "0.1"
strB2BList  = ["0.001", "0.01"]
strHrad = "10"
strBrad = "11"

import subprocess
import json

fitRangeFilename = flnPrefix+"SimulResultTest"+".json" 
print fitRangeFilename
command="pluma "+fitRangeFilename
subprocess.call(command,shell=True)
try:
  fit_range = json.load(open(fitRangeFilename))
  flagWarning = False
except:
  print "-"*20, "ERROR: not file to fit_range"
  pass

import matplotlib.pyplot as plt
figR2, axR2 = plt.subplots()
colvals = np.abs(np.log( map(float, strB2BList)))+3.0

for b2b in range(len(strB2BList)):
  strB2B = strB2BList[b2b]
  simres = sr.SimulResult(flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials )
  tmin, tmax = fit_range[strB2B]
  simres.calcDiffCoeff(tmin, tmax)
  axR2. plot(simres.ttime, simres.DelR2, linewidth=2, color=plt.cm.Purples(colvals[b2b]), label="$ "+strB2F+" $")


plt.show()