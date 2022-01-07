#!/home/alfaceor/.local/bin/ipython3 -i
# !/usr/bin/ipython3 -i
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 11 10:15:49 2019

@author: alfaceor
"""

import numpy as np
import xarray as xr
import matplotlib.pyplot as plt
import seaborn

np.random.seed(0)
datanp = np.random.randn(3, 4, 5)
datanp
data = xr.DataArray(datanp, dims=('x', 'y', 'z'))

print(data)
print(data.sortby('z'))
#print data[0]
#print data[{'x':0}]
fig, ax = plt.subplots()
data[{'y':0, 'z' :0}].plot(ax = ax)
plt.show()

