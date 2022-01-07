#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0,0.5)
y = x*(1.0-x)

def as_si(x, ndp):
    s = '{x:0.{ndp:d}e}'.format(x=x, ndp=ndp)
    m, e = s.split('e')
    return r'{m:s}\times 10^{{{e:d}}}'.format(m=m, e=int(e))

a=1.92e-7
a=1e-7
a=1
a=0


plt.figure()
plt.plot(x, y)

plt.text(0.01, 0.23, r"$a = {0:s}$".format(as_si(a,2)), size=20)
plt.show()
