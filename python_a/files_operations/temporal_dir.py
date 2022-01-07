#!/usr/bin/env python3

import tempfile
import subprocess
tempdir = tempfile.TemporaryDirectory()
print(tempdir.name)
cmd = "echo mama > " + str(tempdir.name) + "/" + "ohlala"
p = subprocess.Popen(cmd, shell=True) #, stdout=subprocess.PIPE)

cmd = "cat " + str(tempdir.name)
p = subprocess.Popen(cmd, shell=True) #, stdout=subprocess.PIPE)

tempdir.cleanup()

