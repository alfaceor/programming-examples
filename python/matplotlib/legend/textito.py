#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

numbers=[1e-7, 1e-17, 2.4e-5, 10.04e-12]
for i in range(len(numbers)):
  print numbers[i] #, '{x:0.{ndp:d}e}'.format()


for i in range(3,13):
  print("{:3d} {:4d} {:5d}".format(i, i*i, i*i*i))

for i in range(0,8):
  #print("{} {:4d} {:5d}".format(100*0.1**i, i*i, i*i*i))
  print("{jo:7.6g} {xo:4d} {me:5d}".format(jo=100*0.1**i, xo=i*i, me=i*i*i))

"""
x = np.linspace(0,0.5)
y = x*(1.0-x)

def as_si(x, ndp):
    s = '{x:0.{ndp:d}e}'.format(x=x, ndp=ndp)
    m, e = s.split('e')
    return r'{m:s}\times 10^{{{e:d}}}'.format(m=m, e=int(e))

a=1.92e-7
a=1e-7

plt.figure()
plt.plot(x, y)

plt.text(0.01, 0.23, r"$a = {0:s}$".format(as_si(a,2)), size=20)
plt.show()
"""
