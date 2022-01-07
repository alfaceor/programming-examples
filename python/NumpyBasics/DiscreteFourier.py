#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

N=64
x=np.array(map(float, range(N)))
print x
q  = 0.1*np.sin(2*np.pi*x/N )
Q  = np.fft.ifft(q)
qI = np.fft.fft(Q)
fig, ax = plt.subplots(2,1)

print q
print Q

ax[0].plot(x, q)
ax[0].plot(x, qI)
ax[0].plot(x, Q.real, '-o')
ax[0].plot(x, Q.imag, '-+')

plt.show()



