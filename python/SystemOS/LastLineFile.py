#!/usr/bin/python
import os
lastLine=os.popen('tail -n 1 fileteste.txt').read()
print lastLine
