# -*- coding: utf-8 -*-
"""
Created on Sat Jan 13 17:29:54 2018

@author: alfaceor
"""
import numpy as np
import matplotlib.pyplot as plt
import os

class SimulData:
  def __init__(self):
    self.strF2B     = "" #strF2B
    self.strB2F     = "" #strB2F
    self.strB2B     = "" #strB2B
    self.strHrad    = "" #strHrad
    self.strBrad    = "" #strBrad
    self.strNtrials = "" #strNtrials
    self.flnPrefix  = "" #"rw3D_RegularPorousDepletion"
    self.arguments  = "" #" --pF2B "+self.strF2B+" --pB2F "+self.strB2F+" --pB2B "+self.strB2B+" --Hradius "+self.strHrad+" --Bradius "+self.strBrad
    self.qsubArgs   = ""
    self.netFile    = "" #self.flnPrefix+"_F2B_"+self.strF2B+"__B2F_"+self.strB2F+"__B2B_"+self.strB2B+"__Hrad_"+self.strHrad+"__Brad_"+self.strBrad+".net"
    self.dataFile   = "" #flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHrad+"__Brad_"+strBrad+"__nt_"+strNtrials+".dat"
    self.path       = ""
    
    # Converted values
    self.pF2B       = -1 #float(strF2B)
    self.pB2F       = -1 #float(strB2F)
    self.pB2B       = -1 #float(strB2B)
    self.Hrad       = -1 #float(strHrad)
    self.Brad       = -1 #float(strBrad)
    self.Ntrials    = -1 #int  (strNtrials)
    
    
    #calculated values
    #data             = [] #np.loadtxt(self.dataFile)
    self.ttime       = [] #data[:,0]
    self.DelR2       = [] #data[:,7]
    self.ttimeLambda = []
    self.EffecDiff   = []
    
    # FIT DATA
    self.tmin      = -1 #0
    self.tmax      = -1 #len(self.ttime)
    self.DiffCoeff = -1 #0.0
    self.D_err_mim = -1
    self.D_err_max = -1
    self.popt      = []
    self.pcov      = []

    # Fabio Method
    self.lambFlag  = False
    self.strLamb1  = ""
    self.strLamb2  = ""
    self.strLamb3  = ""
    self.lamb1     = -1
    self.lamb2     = -1
    self.lamb3     = -1
    self.DiffLamb1 = -1
    self.DiffLamb2 = -1
    self.DiffLamb3 = -1
    
  def metadata(self, flnPrefix, strF2B, strB2F, strB2B, strHrad, strBrad, strNtrials, loadData=True):
    self.strF2B     = strF2B
    self.strB2F     = strB2F
    self.strB2B     = strB2B
    self.strHrad    = strHrad
    self.strBrad    = strBrad
    self.strNtrials = strNtrials
    
    self.convertStrParams()
    self.defineFiles()
    
    
  def metadataFromCSVentry(self, flnPrefix, csv_entry):
    self.flnPrefix  = flnPrefix
    self.strF2B     = csv_entry["strF2B"    ]
    self.strB2F     = csv_entry["strB2F"    ]
    self.strB2B     = csv_entry["strB2B"    ]
    self.strHrad    = csv_entry["strHrad"   ]
    self.strBrad    = csv_entry["strBrad"   ]
    self.strNtrials = csv_entry["strNtrials"]
    
    self.convertStrParams()
    self.defineFiles()

  def convertStrParams(self):
    self.pF2B       = float(self.strF2B)
    self.pB2F       = float(self.strB2F)
    self.pB2B       = float(self.strB2B)
    self.Hrad       = float(self.strHrad)
    self.Brad       = float(self.strBrad)
    self.Ntrials    = int  (self.strNtrials)
    
  def defineFiles(self):
    self.arguments  = " --pF2B "+self.strF2B+" --pB2F "+self.strB2F+" --pB2B "+self.strB2B+" --Hradius "+self.strHrad+" --Bradius "+self.strBrad
    self.netFile    = self.flnPrefix+"_F2B_"+self.strF2B+"__B2F_"+self.strB2F+"__B2B_"+self.strB2B+"__Hrad_"+self.strHrad+"__Brad_"+self.strBrad+".net"
    self.dataFile   = self.flnPrefix+"_F2B_"+self.strF2B+"__B2F_"+self.strB2F+"__B2B_"+self.strB2B+"__Hrad_"+self.strHrad+"__Brad_"+self.strBrad+"__nt_"+self.strNtrials+".dat"
    self.qsubArgs  =" -v F2B="+self.strF2B+",B2F="+self.strB2F+",B2B="+self.strB2B+",Hrad="+self.strHrad+",Brad="+self.strBrad

  
  def getData(self):
    self.defineFiles()
    #calculated values
    data       = np.loadtxt(self.dataFile)
    self.ttime = data[:,0]
    self.DelR2 = data[:,7]
    
    # FIT DATA
    self.tmin  = 0
    self.tmax  = len(self.ttime)
    self.DiffCoeff  = 0.0
    self.popt  = []
    self.pcov  = []
    
  def isDone(self):
    self.defineFiles()
    if os.path.isfile(self.netFile) :
      if os.path.isfile(self.dataFile) :
        return  True # "echo JOB is DONE"
      else:
        return True #"echo JOB is RUNNING OR IMCOMPLETE!!"
    else:
      return False #program+" "+self.arguments # "JOB TO 
    
  def getCMD(self, program):
    self.defineFiles()
    if os.path.isfile(self.netFile) :
      if os.path.isfile(self.dataFile) :
        return  "echo JOB is DONE"
      else:
        return "echo JOB is probabibly RUNNING OR IMCOMPLETE!!"
    else:
      return program+" "+self.arguments # "echo JOB TO SUBMIT!!!"

  def calcDwithLamb(self):
    EffecDiff   = self.DelR2[imin:imax]/(6.*self.ttime[imin:imax])
    # lambda 1
    ttimeLambda = 1./self.ttime[imin:imax]**lamb1
    #axDiffEff1.plot(ttimeLambda, EffecDiff, linewidth=2, color=plt.cm.Dark2(float(strB2B)))
    popt, pcov = fitLine(ttimeLambda,EffecDiff)
    Diff = popt[1]
    fig, ax = plt.subplots(2,2, figsize=(8,6))
    XX = np.linspace(0,ttimeLambda.max() )
    ax.plot(XX, line(XX, popt[0], Diff1), '--', color='k' )
    ax.axhline(y=self.DiffCoeff, color='k')
    return Diff


  def calcDiffCoeff(self, tmin, tmax):
    #tmin, tmax = fit_range[strParameter]
    self.imin, self.imax = getLimits(self.ttime, tmin, tmax)
    self.popt, self.pcov = curve_fit(line, self.ttime[self.imin:self.imax], self.DelR2[self.imin:self.imax])
    self.DiffCoeff = self.popt[0]/6.0
    if self.lmbFlag == True :
      print "Method "
      # lambda 1
      ttimeLambda = 1./ttime[imin:imax]**lamb1
      axDiffEff1.set_xlim(0,ttime[imin]**(-lamb1))
      axDiffEff1.plot(ttimeLambda, EffecDiff, linewidth=2, color=plt.cm.Dark2(float(strB2B)))
      popt, pcov = fitLine(ttimeLambda,EffecDiff)
      Diff1 = popt[1]
      XX = np.linspace(0,ttimeLambda.max() )
      axDiffEff1.plot(XX, line(XX, popt[0], Diff1), '--', color='k' )
      #print lamb1, popt[1]
      strResult=strResult+" "+str(lamb1)+" "+str(Diff1)

    
  def getCMD(self, program):
    #print netFile
    if os.path.isfile(self.netFile) :
      #print dataFile
      if os.path.isfile(self.dataFile) :
        return  "echo JOB is DONE"
      else:
        #print dataFile+" no such a file"
        return "echo JOB is probabibly RUNNING OR IMCOMPLETE!!"
    else:
      #print netFile+" no such a file"
      return program+" "+self.arguments # "echo JOB TO SUBMIT!!!"

  def getCSVstrLine(self):
    return  \
    "\"" +self.strF2B    +"\","+ \
    "\"" +self.strB2F    +"\","+ \
    "\"" +self.strB2B    +"\","+ \
    "\"" +self.strHrad   +"\","+ \
    "\"" +self.strBrad   +"\","+ \
    "\"" +self.strNtrials+"\""  


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

