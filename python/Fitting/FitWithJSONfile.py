#!/usr/bin/python

## OBJECTIVE: Write a library to import and fit data from in a determined range saved in a json file.

#### INPUT JSON FILE ####
import json
import subprocess

def getFitRangeFromJsonFile (fitRangeFilename):
  print fitRangeFilename
  command="pluma "+fitRangeFilename
  subprocess.call(command,shell=True)
  print "foda-se"
  try:
    fit_range = json.load(open(fitRangeFilename))
    return fit_range
  except:
    print "-"*20
    print "Can not read file: "+ fitRangeFilename
    return 0

from scipy.optimize import curve_fit

def line(x, m, b): 
  return m*x+b

def fitLine(xdata, ydata):
  popt, pcov = curve_fit(line, xdata, ydata)
  return popt, pcov

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


def fitLineFitRange(xdata, ydata, strParameter, fit_range):
  #tmin, tmax = [10000, 100000]
  tmin, tmax = fit_range[strParameter]
  imin, imax = getLimits(xdata, tmin, tmax)
  popt, pcov = fitLine(xdata[imin:imax], ydata[imin:imax])
  popt, pcov = curve_fit(line, xdata, ydata)
  return popt, pcov

  