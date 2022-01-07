#!/usr/bin/python

import numpy as np
import subprocess

#command="sleep 10; echo 'putz'"
#subprocess.call(command, shell=True)

command="echo 'AAAAA'"
aaa = subprocess.call(command, shell=True)
print(aaa)
