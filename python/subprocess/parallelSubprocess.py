#!/usr/bin/python

import subprocess

### ls_output = subprocess.check_output(['ls'])
### command="ls"
### subprocess.call(command,shell=True)
for i in range(10):
  strI=str(i)
  command="sleep 10s;"
  command=command+"echo "+strI+" > temporal"+strI+".txt &"
  print command
  #subprocess.call(command,shell=True)
  subprocess.Popen(command,shell=True)
  print "submited"

print "AJAM!!!"
