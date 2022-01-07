# -*- coding: utf-8 -*-
"""
Created on Sat Jan 13 17:29:54 2018

@author: alfaceor
"""
import numpy as np
class SimulResult:
  def __init__(self, flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials):
    self.strF2B     = strF2B
    self.strB2F     = strB2F
    self.strB2B     = strB2B
    self.strHrad    = strHrad
    self.strBrad    = strBrad
    self.strNtrials = strNtrials
    self.dataFile   = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+"__nt_"+strNtrials+".dat"
    self.pF2B       = float(strF2B)
    self.pB2F       = float(strB2F)
    self.pB2B       = float(strB2B)
    self.Hrad       = float(strHrad)
    self.Brad       = float(strBrad)
    self.Ntrials    = int  (strNtrials)
    
    #calculated values
    data       = np.loadtxt(self.dataFile)
    self.ttime = data[:,0]
    self.DelR2 = data[:,5]
    
    # FIT DATA
    self.tmin  = 0
    self.tmax  = len(self.ttime)
    self.DiffCoeff  = 0.0
    self.popt  = []
    self.pcov  = []
  
  def calcDiffCoeff(self, tmin, tmax):
    #tmin, tmax = fit_range[strParameter]
    self.imin, self.imax = getLimits(self.ttime, tmin, tmax)
    self.popt, self.pcov = curve_fit(line, self.ttime[self.imin:self.imax], self.DelR2[self.imin:self.imax])
    self.DiffCoeff = self.popt[0]/6.0

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



#def plotB2F(strF2B, strB2F, strB2B ):
  

#dataDiffCoeff=[]
#for b2f in range(len(strB2FList)):
#  #strB2F = strB2FList[nparam]
#  strB2F = strB2FList[b2f]
#  dataFile = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius+"__nt_"+strNtrials+".dat"
#  print dataFile 
#  data = np.loadtxt(dataFile)
#  ttime = data[:,0]
#  DelX2 = data[:,5]
#  #popt, pcov = fit.fitLineFitRange(ttime, DelX2, strB2F, fit_range)
#  tmin, tmax = fit_range[strB2F]
#  imin, imax = fit.getLimits(ttime, tmin, tmax)
#  popt, pcov = fit.fitLine(ttime[imin:imax], DelX2[imin:imax])
#  print popt[0], popt[1]
#  fiterror_INF=0 # FIXME
#  fiterror_SUP=0 # FIXME
#  dataDiffCoeff.append([float(strB2F), popt[0]/6.0, fiterror_INF, fiterror_SUP])
#
#  axR2. plot(ttime, DelX2, linewidth=2, color=plt.cm.Blues(colvals[b2f]), label="$ "+strB2F+" $")
#  axR2. plot (ttime[imin:imax], fit.line(ttime[imin:imax], popt[0], popt[1]), '--', color='k')
#
#axR2. plot(data[:,0], 1.*data[:,0]+1, linewidth=2, color='k' )
##axIns.plot(data[:,0], 1.*data[:,0]+1 )
#
#handles, labels = axR2.get_legend_handles_labels()
#axR2.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.02,0.35), loc="lower left", title="$p_{B \\to F}$", prop={'size':12}, frameon=False)
#fig.tight_layout()
#outFilename = flnPrefix+"_F2B_"+strF2B+"__B2F_"+"VAR"+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius+".pdf" 
#print outFilename
#plt.savefig(outFilename)