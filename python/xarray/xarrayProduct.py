#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 11 10:15:49 2019

@author: alfaceor
"""

import numpy as np
import xarray as xr
#import matplotlib.pyplot as plt

datanp = np.random.randn(2, 3, 4)
data = xr.DataArray(datanp, dims=('x', 'y', 'z'))
A = data


datanp = np.random.randn(3, 4)
data = xr.DataArray(datanp, dims =('y', 'z'))
B = data

datanp = np.random.randn(4)
data = xr.DataArray(datanp, dims =('z'))
C = data

print(A)
print(B)
print(B[{'y':0}])
print(B[{'z':0}])
print(C)
print("*"*10)
print(A.dot(B))
print(B.dot(A))
print("-"*10)
print(A.dot(B*C) )
print(A.dot(C*B) )
