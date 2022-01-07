#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 11 10:15:49 2019

@author: alfaceor
"""

import numpy as np
import xarray as xr
import matplotlib.pyplot as plt
import seaborn

datanp = np.random.randn(2, 3, 4)
datanp
data = xr.DataArray(datanp, dims=('x', 'y', 'z'))

data[0]
data[{'x':0}]

Event_list = xr.DataArray()

Event_list[{'nickname': 'v_choice', 'index': 0}]
data.sum(dim=('x'))
data.sum(dim=('x','y'))
for dim in data.dims:
    data[dim] = range(len(data[dim]))

seaborn.plot(data=data['x'])
data['y']
type(data.dims)
aaa=tuple(list(data.dims).remove('y'))
aaa.remove('y')
aaa=list(data.dims).remove('y')
aaa


data.dims

datanp = np.random.randn(4, 5)
data = xr.DataArray(datanp, dims =('x', 'y'))
print data
print data['x']
print data['y']
print data[1]
data[0].plot(marker='o')
data[:,0].plot(marker='o')

print data[1][2]
print data.loc[1,2]
print data.loc[{'x':1, 'y':2}]

print "--"*5
print data
print data[1][:2]
print data.loc[1,:2]
print data.loc[{'x':1, 'y':range(2)}]

# Now I want the element x labeled dad
print "--"*5
xcoordsName   = ['mom', 'dad', 'son', 'daugther']
xcoordsValues = [0, 20, 10, 50]
data = xr.DataArray(datanp, dims =('x', 'y'), coords={'x': xcoordsValues })
print data
print data['x']
print data['y']
print data[1,2]
#print data.loc['dad',2]
data.loc[{'y':0}]
data.loc[{'y':0}].plot(marker='o')
data.loc[{'y':1}].plot(marker='o')

data.sortby(data.loc[{'x':0}])
data
########## SORT DATAARRAY
import pandas as pd
ooo = np.random.rand(5)
ooo
da = xr.DataArray(ooo, coords=[range(5)], dims='time')
da
db = da.sortby(da)


da.plot(linestyle="None", marker='o')
db.plot(linestyle="None", marker='o')


# two dimensional array
aaa = np.random.randn(2, 3)
data = xr.DataArray(aaa, coords={'x': ['a', 'b']}, dims=('x', 'y'))

data = xr.DataArray(aaa, dims=('x', 'y'))

print data
data.loc[:,:]
data.loc[:,0]
data.loc[:,1]
data.loc[0,:]
data.mean(dim='x')

data[0][1]
len(data.y)



da = xr.DataArray([9, 0, 2, 1, 0],
                  dims=['x'],
                  coords={'x': [10, 20, 30, 40, 50]})

da.loc[{'x':[10,30,50]}]
da._coords
da._variable
