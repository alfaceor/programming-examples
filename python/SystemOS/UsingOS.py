#!/usr/bin/python
import os
flname='fileteste.txt'
os.system('tail -n 1 '+flname+' > tmp')
print open('tmp', 'r').read()
