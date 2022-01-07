#!/usr/bin/python
import subprocess

p = subprocess.call("ls", shell=True)
print "hello "+p+" bitch!"
