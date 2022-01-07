#!/usr/bin/env python3

import numpy as np
from scipy.integrate import odeint


a = 1 
L = 100
N = 1000
dx = L/N
x = np.arange(-L/2, L/2, dx)

# Define discrete wave numbers
kappa = 2.*np.pi*np.fft.fftfreq(N, d=dx)
kappa = np.fft.fftfreq(N, d=dx)
print(kappa)

# Initial condition

u0 = np.zeros_like(x)
u0[int((L/2 - L/10)/dx): int((L/2 + L/10)/dx) ] = 1
u0hat = np.fft.fft(u0)

u0hat_ri = np.concatenate((u0hat.real, u0hat.imag))


dt = 0.1

t = np.arange(0,10,dt)

def rhsHeat(uhat_ti, t, kappa, a):
    uhat = uhat_ri[:N] + (1j)*uhat_ri[N:]
    d_uhat = -a**2 * (np.power(kappa,2))*uhat
    d_uhat_ri = np.concatenate((d_uhat.real, d_uhat.imag)).astype('float64')
    return d_uhat_ri

uhat_ri = odeint(rhsHeat, u0hat_ri, t, args=(kappa,a))
uhat = uhat_ri[:, :N] + (1j) * uhat_ri[:, N:]

u = np.zeros_like(uhat)

for k in range(len(t)):
    u[k, :] = np.fft.ifft(uhat[k,:])

u = u.real

print(u)
