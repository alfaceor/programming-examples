#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt
###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18}
plt.rc('font', **font)
plt.rc('text', usetex=True)
###### END PLOT DECORATION VARIABLES
fig, ax = plt.subplots()
ax.set_title("$P(\\eta) \\sim \\eta^{-\\mu}$")
ax.set_xscale("log")
ax.set_yscale("log")

ax.set_xlabel("$\\eta$")
ax.set_ylabel("$P(\\eta)$") #, rotation=0)


##### FITTING FUNCTIONS #####
from scipy.optimize import curve_fit
def line(x, m, b): 
  return m*x+b

def powLaw(x, m, b): 
  return np.exp(b)*x**m

def fitPowLaw(xdata, ydata):
  popt, pcov = curve_fit(line, np.log(xdata), np.log(ydata))
  return popt, pcov


strMuList = ["0.1", "0.2", "0.3", "0.4", "0.5" , "0.6", "0.7", "0.8", "0.9", "1.0", "1.1" ] #"1.5", "2.0", "3.0", "4.0"]
#strMuList = ["1.1", "4.0"]
for im in range(len(strMuList)):
  strMu = strMuList[im]
  lblMu = "$"+ strMu +"$"

  data = np.loadtxt("histoeta_mu_"+strMu+".dat")
  bins = np.mean(data[:,0:2], axis=1)
  rndfloat = data[:,2]
  print strMu, "area", np.dot( (data[:,1] - data[:,0]), rndfloat )/rndfloat.sum()
  mu = float(strMu)
  print mu,
  colorcito = plt.cm.Set1(mu/4.0)
  popt, pcov = fitPowLaw(bins[ rndfloat != 0], rndfloat[ rndfloat != 0])
  lblMuFit = ", ${0:02.2f}$".format(np.abs(popt[0]))
  ax.plot( bins, powLaw(bins, popt[0], popt[1]), "--",  color=colorcito )
  ax.plot( bins, rndfloat, marker="o", linestyle="none", color=colorcito, label=lblMu+lblMuFit)
  #print rndfloat
  #popt, pcov = fitPowLaw(bins, rndfloat)
  #print popt
  
  #ax.hist(rndfloat)

ax.legend(title="$\\mu, \\mu_{fit}$", prop={'size':12}, frameon=False)

fig.tight_layout()
plt.show()

