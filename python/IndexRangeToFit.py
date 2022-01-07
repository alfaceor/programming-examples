# -*- coding: utf-8 -*-
"""
Created on Thu Aug 10 14:07:31 2017

@author: alfaceor
"""
import numpy as np

dados=np.arange(12,23)

def getLimits(arr, amin, amax):
  # Array must be sorted from min to max
  i_min=0
  i_max=len(arr)-1
  #if arr[i_min] > amin or arr[i_max] < amax:
  #  print "Out of bounds!!"
  #  exit()
  ii    = i_min
  while (arr[ii] <= amin ):
    ii = ii+1
    i_min = ii

  ii    = i_max
  while (arr[ii] >= amax ):
    ii = ii-1
    i_max = ii

  return i_min, i_max


dmin, dmax = getLimits(dados, 14.8,18.2)
print dmin, dmax
print dados[dmin],dados[dmax]

dados