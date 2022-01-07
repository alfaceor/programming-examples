#!/usr/bin/env python3
import subprocess
from threading import Timer
kill = lambda process: process.kill()
cmd = ['ping', 'www.google.com']
ping = subprocess.Popen(
    cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print(type(ping))
my_timer = Timer(5, kill, [ping])
try:
    my_timer.start()
    stdout, stderr = ping.communicate()
    print(type(stdout))
finally:
    my_timer.cancel()
