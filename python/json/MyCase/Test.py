#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import json
import csv
from SimulData import *

jsonfilename = "D_fit.json"
csvfilename  = "SizeExperiment__B2B_0.01.csv"
flnPrefix    = "rw3D_RegularPorousDepletion"

fit_params = json.load(open(jsonfilename))
with open(csvfilename) as csvfile:
  mpg = list(csv.DictReader(csvfile))
print mpg[0]
#print fit_params.items()
#for key, value in fit_params.items():
#  print key, value.items()
sr = SimulData();
sr.metadataFromCSVentry(flnPrefix, mpg[0])
fit_params[sr.strF2B]["lambFlag"] = True
print fit_params[sr.strF2B]["lambFlag"] 
#if fit_params["1.0"]["lambFlag"] == False :
#  print "fit with fabio method"

