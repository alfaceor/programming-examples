#!/usr/bin/python
import matplotlib.pyplot as plt
#import plotly.plotly as py
import numpy as np
# Learn about API authentication here: https://plot.ly/python/getting-started
# Find your api_key here: https://plot.ly/settings/api

Fs = 150.0;  # sampling rate
Ts = 1.0/Fs; # sampling interval
t = np.arange(0,1,Ts) # time vector

ff1 = 10;   # frequency of the signal
ff2 = 20;
A1=2;
A2=5;
y = A1*np.sin(2*np.pi*ff1*t) + A2*np.sin(2*np.pi*ff2*t)
#y = np.random.random(len(t))

n = len(y) # length of the signal
k = np.arange(n)
T = n/Fs
frq = k/T # two sides frequency range
print n, Fs, T, frq
frq = frq[range(n/2)] # one side frequency range
print n, Fs, T, frq

Y = np.fft.fft(y)/n # fft computing and normalization
Y = Y[range(n/2)]

fig, ax = plt.subplots(2, 1)
ax[0].plot(t,y)
ax[0].set_xlabel('Time')
ax[0].set_ylabel('Amplitude')
ax[1].plot(frq,abs(Y),'r') # plotting the spectrum
ax[1].set_xlabel('Freq (Hz)')
ax[1].set_ylabel('|Y(freq)|')


plt.show()
