#!/usr/bin/python

import subprocess

Njobs=10
Nprocess=3
command=""
for i in range(Njobs):
  strI=str(i)
  job2run= "echo "+strI+" > temporal"+strI+".txt "
  command=command + job2run + ";"
  if (i % Nprocess == 0):
    #print i % Nprocess, i / Nprocess
    print command
    #subprocess.Popen(command,shell=True)
    command="sleep 10s;"
print command
print "submited"

print "AJAM!!!"
