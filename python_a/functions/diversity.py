#!/usr/bin/env python3

import numpy as np

def D_q_gamma(prob_mass):
    return prob_mass


pC = np.random.rand(50)

pC = pC/pC.sum()
print(pC)
print(pC.sum())

import matplotlib.pyplot as plt

fig, ax = plt.subplots()
ax.plot(pC)

plt.show()
