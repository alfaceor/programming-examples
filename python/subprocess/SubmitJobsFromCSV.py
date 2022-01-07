#!/usr/bin/python

import subprocess
import csv
import json

with open('Read_csv_file.csv') as csvfile:
  mpg = list(csv.DictReader(csvfile))

print mpg[0], len(mpg), mpg[0]["strB2F"]

mpg_json=json.dumps(mpg)
print mpg_json
{'strHrad': '10', 'strBrad': '11', 'strB2F': '0.1', 'strB2B': '0.000001', 'strF2B': '1.0'} 4 0.1
[{"strHrad": "10", "strBrad": "11", "strB2F": "0.1", "strB2B": "0.000001", "strF2B": "1.0"}, {"strHrad": "10", "strBrad": "11", "strB2F": "0.01", "strB2B": "0.000001", "strF2B": "1.0"}, {"strHrad": "10", "strBrad": "11", "strB2F": "0.0001", "strB2B": "0.000001", "strF2B": "1.0"}, {"strHrad": "10", "strBrad": "11", "strB2F": "0.000001", "strB2B": "0.000001", "strF2B": "1.0"}]



# TODO: GET A LINE OF DATA, then see the cells to get the corresponding values, at first use a function (def) for the future use a class or data sctructure.

##program="echo"
##Njobs=10
##Nprocess=3
##command=""
##for i in range(Njobs):
##  strI=str(i)
##  job2run = program + " " + strI +" > temporal"+strI+".txt "
##  command = command + job2run + ";"
##  if (i % Nprocess == 0):
##    #print i % Nprocess, i / Nprocess
##    print command
##    #subprocess.Popen(command,shell=True)
##    command="sleep 10s;"
##print command
##print "submited"
##
