#!/usr/bin/python
#import SimulResult as sr
import json
import subprocess
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
from SimulData import *
###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18} 
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES
dirList=["longTime/longTime2/", "longTime/", "./", "short/"]

strF2B = "1.0" 
strB2F = "0.01" #["0.2", "0.4", "0.6", "0.8", "1.0"] 
#strB2BList = ["1.0", "0.1" ] #, "0.00001", "0.0001", "0.001", "0.01", "0.1", "1.0" ] 
strB2BList = ["0.000001", "1.0" ] 
#strB2BList = ["0.000001", "0.00001", "0.0001", "0.001", "0.01", "0.1", "1.0" ] 
boolShowFit = [True, True, True]

strHradius = "10"
strBradius = "11"
flnPrefix="rw3D_RegularPorousDepletion"
strNtrials = str(10**5)

# rw3D_RegularPorousDepletion_F2B_1.0__B2F_0.25__B2B_VAR__Hrad_10.fitrange
outPrefix    = "D_vs_pBB__pBF_"+strB2F #+"__Hrad_"+strHradius
fitParamsFln = outPrefix+".json"
outfln_PDF   = outPrefix+".pdf"
outfln_DAT   = outPrefix+".DAT"

#fitRangeFilename = flnPrefix+"FitRange"+"_F2B_"+strF2B+"__B2F_"+"VAR"+"__B2B_"+strB2B+".json" 
print fitParamsFln
command="pluma "+fitParamsFln
subprocess.call(command,shell=True)
flagWarning = True
try:
  fit_params = json.load(open(fitParamsFln))
  flagWarning = False
except:
  print "-"*20
  flagWarning = True
  pass

from scipy.optimize import curve_fit

def lambdaFit(ttime, deltaR2, DiffCoeffLong, m, b, fitparams, titulo, colorcito):
  tmin, tmax = fitparams["fitrange"]
  lamb1 =  fitparams["lamb1"]
  lamb2 =  fitparams["lamb2"]
  lamb3 =  fitparams["lamb3"]
  strLamb1    =  str(lamb1)
  strLamb2    =  str(lamb2)
  strLamb3    =  str(lamb3)
  
  fig, ax = plt.subplots(2,2, figsize=(8,6))
  fig.suptitle(titulo)
  #fig.suptitle("$ p_{F \\to B} = "+strF2B+" $, $ p_{B \\to F} = "+strB2F+ "  $, $ p_{B \\to B} = "+ strB2B +" $")
  axR2       = ax[0][0]
  axDiffEff1 = ax[0][1]
  axDiffEff2 = ax[1][0]
  axDiffEff3 = ax[1][1]

  axR2.set_xlabel("$t$", fontsize='30', rotation=0)
  axR2.set_ylabel("$ \\langle \\Delta r^2 \\rangle $", fontsize='30')

  axR2.set_xscale("log")
  axR2.set_yscale("log")

  #axDiffEff1.set_xscale("log")
  #axDiffEff1.set_xscale("log")
  
  axDiffEff1.set_xlabel("$1/t^{"+strLamb1+"}$", fontsize='30', rotation=0)
  axDiffEff1.set_ylabel("$ D_{\\mbox{eff}}$", fontsize='30')

  axDiffEff2.set_xlabel("$1/t^{"+strLamb2+"}$", fontsize='30', rotation=0)
  axDiffEff2.set_ylabel("$ D_{\\mbox{eff}}$", fontsize='30')

  axDiffEff3.set_xlabel("$1/t^{"+strLamb3+"}$", fontsize='30', rotation=0)
  axDiffEff3.set_ylabel("$ D_{\\mbox{eff}}$", fontsize='30')
  

  axR2. plot(ttime, DelR2, linewidth=2,  color=colorcito, label="$ "+strB2B+" $")
  axR2. plot(ttime[imin:imax], line(ttime[imin:imax], m, b), '--', color='k' )

  ### EFFECTIVE DIFFUSION
  EffecDiff   = DelR2[imin:imax]/(6.*ttime[imin:imax])
  # lambda 1
  ttimeLambda = 1./ttime[imin:imax]**lamb1
  axDiffEff1.set_xlim(0,ttime[imin]**(-lamb1))
  axDiffEff1.plot(ttimeLambda, EffecDiff, "o", linewidth=2, color=colorcito)
  popt, pcov = fitLine(ttimeLambda,EffecDiff)
  Diff1 = popt[1]
  XX = np.linspace(0,ttimeLambda.max() )
  axDiffEff1.plot(XX, line(XX, popt[0], Diff1), '--', color='k' )

  # lambda 2
  ttimeLambda = 1./ttime[imin:imax]**lamb2
  axDiffEff2.set_xlim(0,ttime[imin]**(-lamb2))
  axDiffEff2.plot(ttimeLambda, EffecDiff, "o", linewidth=2, color=colorcito)
  popt, pcov = fitLine(ttimeLambda,EffecDiff)
  Diff2 = popt[1]
  XX = np.linspace(0,ttimeLambda.max() )
  axDiffEff2.plot(XX, line(XX, popt[0], Diff2), '--', color='k' )
  
  # lambda 3  
  ttimeLambda = 1./ttime[imin:imax]**lamb3
  axDiffEff3.set_xlim(0,ttime[imin]**(-lamb3))
  axDiffEff3.plot(ttimeLambda, EffecDiff, "o", linewidth=2, color=colorcito)
  popt, pcov = fitLine(ttimeLambda,EffecDiff)
  Diff3 = popt[1]
  XX = np.linspace(0,ttimeLambda.max() )
  axDiffEff3.plot(XX, line(XX, popt[0], Diff3), '--', color='k' )
  
  axDiffEff1.axhline(y=DiffCoeffLong, color='k')
  axDiffEff2.axhline(y=DiffCoeffLong, color='k')
  axDiffEff3.axhline(y=DiffCoeffLong, color='k')

  fig.tight_layout()
  DiffsCoe = np.array([DiffCoeffLong, Diff1, Diff2, Diff3])
  return DiffsCoe.mean(), DiffsCoe.min(), DiffsCoe.max()
  
  #outFilename = flnPrefix+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+"VAR"+".pdf" 
  #plt.savefig(outFilename)
  #plt.show()

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


#fprintf(outfile, "#nt x y x_var y_var r_var\n");
#fig, ax = plt.subplots(2,2, sharex=True)
fig, ax = plt.subplots(1,1, figsize=(8,6))
axR2 = ax
left, bottom, width, height = [0.6, 0.25, 0.3, 0.25]
#axIns = fig.add_axes([left, bottom, width, height])
#axIns.set_xlim(0, 40)  
#axIns.set_ylim(0, 40)  
#axIns.tick_params(axis='x', labelsize=10)
#axIns.tick_params(axis='y', labelsize=10)  
#axIns.set_xlabel("$t$")
##axIns.set_xscale("log")

#axIns.set_ylabel("$ \\langle \\Delta r^2 \\rangle $")
##axIns.set_yscale("log")

#plt.ticklabel_format(style='sci', axis='x', scilimits=(0,0))
#axR2.xaxis.set_major_formatter(ticker.FormatStrFormatter('%0.1f'))

axR2.set_xlabel("$t$", fontsize='30', rotation=0)
axR2.set_ylabel("$ \\langle \\Delta r^2 \\rangle $", fontsize='30')

axR2.set_xscale("log")
axR2.set_yscale("log")

#axR2.set_xlim(1e2,1e6)
#axR2.set_ylim(1e1,1e6)

axR2.set_title("$ p_{FB} = "+strF2B+" $, $ p_{BF} = "+strB2F+" $")


#pB2B = map(float,strB2B)
DiffCoeffLong = -1.0*np.ones(len(strB2BList))
D_err_mim     = -1.0*np.ones(len(strB2BList))
D_err_max     = -1.0*np.ones(len(strB2BList))

colvals = np.abs(np.log( map(float, strB2BList)))+3.0
colvals = (colvals/colvals.max() )[::-1]
print colvals
#raw_input()
for b2b in range(len(strB2BList)):
  idir = 0
  while idir < len(dirList):
    try:
      strB2B     = strB2BList[b2b]
      flnPrefix2 = dirList[idir]+flnPrefix 
      dataFile   = flnPrefix2+"_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius+"__nt_"+strNtrials+".dat"
      data = np.loadtxt(dataFile)
      ttime = data[:,0]
      DelR2 = data[:,7]
      #tmin, tmax = (10000, 100000)
      tmin, tmax = fit_params[strB2B]["fitrange"]
      imin, imax = getLimits(ttime, tmin, tmax)
      colorcito=plt.cm.Purples(colvals[b2b])
      axR2. plot(ttime, DelR2, linewidth=2,  color=colorcito, label="$ "+strB2B+" $")
      #axIns.plot(ttime, DelX2, linewidth=2, color=plt.cm.Dark2(float(strB2B)))
      popt, pcov = fitLine(ttime[imin:imax], DelR2[imin:imax])
      DiffCoeffLong[b2b] = popt[0]/6.0
      D_err_mim[b2b]     = (popt[0] - pcov[0][0])/6.0
      D_err_max[b2b]     = (popt[0] + pcov[0][0])/6.0
      
    
      axR2. plot(ttime[imin:imax], line(ttime[imin:imax], popt[0], popt[1]), '--', color='k' )
      #print DiffCoeffLong[b2f] 

      if boolShowFit[b2b] == 1:
        titulo =  "$p_{FB} = "+strF2B+", p_{BF} = "+strB2F+", p_{BB} = "+strB2B+" $"
        
        DiffCoeffLong[b2b], D_err_mim[b2b], D_err_max[b2b] = lambdaFit(ttime, DelR2, DiffCoeffLong[b2b], popt[0], popt[1], fit_params[strB2B], titulo, colorcito )
      break;
    except IOError as e:
      #print e
      pass
    idir = idir + 1
  #strB2F = strB2FList[nparam]


#axR2. plot(data[:,0], 1.*data[:,0]+1, linewidth=2, color='k' )
#axIns.plot(data[:,0], 1.*data[:,0]+1 )

handles, labels = axR2.get_legend_handles_labels()
leg = axR2.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.02,0.35), loc="lower left", title="$p_{BB}$", prop={'size':12}, frameon=False)
fig.tight_layout()
outfln_PDF= outPrefix+".pdf"
print outfln_PDF
plt.savefig(outfln_PDF)
if leg:
  leg.draggable()

subprocess.Popen(command,shell=True)


#outFilename = "DiffCoeffLongTime_"+flnPrefix+"_F2B_"+strF2B+"__B2F_"+"VAR"+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius+".DAT" 
ofile = open(outfln_DAT,"w")
linea="#prob DiffCoeff D_err_min D_err_max\n"
ofile.write(linea)
for i in range(len(DiffCoeffLong)):
  linea = ""+strB2BList[i]+" "+str(DiffCoeffLong[i]) +" "+str(D_err_mim[i])+" "+str(D_err_max[i])+"\n"
  print linea  
  ofile.write(linea)
ofile.close()

data = np.loadtxt(outfln_DAT)
figDiff, axDiff = plt.subplots()

axDiff.set_title("$ p_{FB} = "+strF2B+" $ ")#+", $ p_{B \\to F} = "+strB2F+" $")

axDiff.set_xscale("log")
axDiff.set_yscale("log")
axDiff.set_xlabel("$p_{BB}$", fontsize='30')
axDiff.set_ylabel("$D$", fontsize='30', rotation=0)
#axDiff.set_ylim((0,0.2))
colorcito  = plt.cm.Reds(0.2+0.8*float(strB2F))
#axDiff.plot(data[:,0], data[:,1], marker="o", markersize=9, linewidth=2, markeredgewidth=2, markeredgecolor=colorcito, color=colorcito, label="$ "+strB2B +" $")
ylower = data[:,1] - data[:,2]
yupper = data[:,3] - data[:,1]
print ylower
axDiff.errorbar(data[:,0], data[:,1], yerr=[ylower, yupper] ) #, marker="o", markersize=1, linewidth=2, markeredgewidth=2, markeredgecolor=colorcito, color=colorcito, label="$ "+strB2B +" $")


handles, labels = axDiff.get_legend_handles_labels()
axDiff.legend(handles[::-1], labels[::-1], bbox_to_anchor=(0.2,0.03), loc="lower left", title="$p_{B \\to B}$", prop={'size':12}, frameon=False, numpoints=1)
figDiff.tight_layout()
#outFilename = "DiffCoeffLongTime_"+flnPrefix+"_F2B_"+"VAR"+"__B2F_"+strB2F+"__B2B_"+"VAR"+".pdf"
#figDiff.savefig(outFilename)



plt.show()



