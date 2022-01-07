#!/usr/bin/env python3

import subprocess
# from subprocess import PIPE

### ls_output = subprocess.check_output(['ls'])
### command="ls"
### subprocess.call(command,shell=True)

cmd="ls -sh"
try:
  p = subprocess.run(cmd, shell=True, capture_output=True, text=True)
  print(p.stdout)
except TypeError as e:
  print(type(e))
  print(e)
  print('='*50)
  p = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
  print(p.stdout)
except Exception as e:
    raise e

