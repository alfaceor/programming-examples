#!/usr/bin/python
from  optparse import OptionParser

parser = OptionParser()
parser.add_option("-J", "--Jobs2Run",    dest="Jobs2Run")

(options, args) = parser.parse_args()

#default values
if options.Jobs2Run== None:
  print "Select a csv file with paramaters to run --Jobs2Run "
  exit()
else:
  JOBS2RUN=options.Jobs2Run


import os

def checkSimul(program, flnPrefix, csv_entry):
  #program    = csv_entry["program"   ]
  strF2B     = csv_entry["strF2B"    ]
  strB2F     = csv_entry["strB2F"    ]
  strB2B     = csv_entry["strB2B"    ]
  strHrad    = csv_entry["strHrad"   ]
  strBrad    = csv_entry["strBrad"   ]
  strNtrials = csv_entry["strNtrials"]
  netFile  = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".net"
  #print netFile
  if os.path.isfile(netFile) :
    dataFile = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+"__nt_"+strNtrials+".dat"
    #print dataFile
    if os.path.isfile(dataFile) :
      return  "echo JOB is DONE"
    else:
      #print dataFile+" no such a file"
      return "echo JOB is probabibly RUNNING OR IMCOMPLETE!!"
  else:
    #print netFile+" no such a file"
    arguments=" --pF2B "+strF2B+" --pB2F "+strB2F+" --pB2B "+strB2B+" --Hradius "+strHrad+" --Bradius "+strBrad
    return program+" "+arguments # "echo JOB TO SUBMIT!!!"

import csv
with open(JOBS2RUN) as csvfile:
  mpg = list(csv.DictReader(csvfile))

import subprocess
flnPrefix="rw3D_RegularPorousDepletion"
OMP="export OMP_NUM_THREADS=20"
for i in range(len(mpg)):
  cmd = checkSimul("./parallel_1e8 ", flnPrefix, mpg[i])
  subprocess.call(OMP+";"+cmd, shell=True)



