#!/usr/bin/python
import os

def checkSimul(flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials):
  netFile  = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+".net"
  print netFile
  if os.path.isfile(netFile) :
    dataFile = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+"__nt_"+strNtrials+".dat"
    print dataFile
    if os.path.isfile(dataFile) :
      return  "echo JOB is DONE"
    else:
      print dataFile+" no such a file"
      return "echo JOB is probabibly RUNNING OR IMCOMPLETE!!"
  else:
    print netFile+" no such a file"
    return "echo JOB TO SUBMIT!!!"

flnPrefix="rw3D_RegularPorousDepletion"
strF2B="1.0"
strB2F="0.1" # TODO: CHANGE THIS VALUE
strB2B="0.000001"
strHrad="10"
strBrad="11"
strNtrials="100000"
print checkSimul(flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials)

import csv
with open('Read_csv_file.csv') as csvfile:
  mpg = list(csv.DictReader(csvfile))

for i in range(len(mpg)):
  strF2B     = mpg[i]["strF2B"    ]
  strB2F     = mpg[i]["strB2F"    ]
  strB2B     = mpg[i]["strB2B"    ]
  strHrad    = mpg[i]["strHrad"   ]
  strBrad    = mpg[i]["strBrad"   ]
  strNtrials = mpg[i]["strNtrials"]
  print checkSimul(flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials)


