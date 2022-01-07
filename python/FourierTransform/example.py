#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

X=np.arange(0,10*np.pi,0.05)
Y=np.sin(X-1)
plt.plot(X,Y)

sp = np.fft.fft(Y)
freq = np.fft.fftfreq(X.shape[-1])
plt.plot(freq, sp.real, freq, sp.imag)
#print W
plt.show()
