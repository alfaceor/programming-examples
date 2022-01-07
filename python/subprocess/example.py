#!/usr/bin/python

import subprocess

### ls_output = subprocess.check_output(['ls'])
### command="ls"
### subprocess.call(command,shell=True)
command="pluma temporal.txt"
subprocess.call(command,shell=True)

print "AJAM!!!"
