
#!/usr/bin/python                                                                                       
# return the files of tau vs N per energy density.
import numpy as np
from scipy.optimize import curve_fit



def line(x, m, b): 
  return m*x+b

def powLaw(x, m, b): 
  return np.exp(b)*x**m

def fitPowLaw(xdata, ydata):
  popt, pcov = curve_fit(line, np.log(xdata), np.log(ydata))
  return popt, pcov

def fitExp(xdata, ydata):
  popt, pcov = curve_fit(line, xdata, np.log(ydata))
  return popt, pcov

def getFitRanges(inFitRangeFile):
  ofile=open(inFitRangeFile, "r")
  lines=ofile.readlines()
  ofile.close()
  for i in range(len(lines)):
    lines[i] = lines[i].replace("\n", "") 
    lines[i] = lines[i].split(" ")
  
  strNpart = [ lines[i][0]         for i in range(len(lines))]
  Xmin     = [ float(lines[i][1])  for i in range(len(lines))]
  Xmax     = [ float(lines[i][2])  for i in range(len(lines))]
  
  return strNpart, Xmin, Xmax


##### TO SELECT specific values to fit
def getNparts_HMF(strU):
  ofile=open("FitValues_HMF.txt", "r")
  lines=ofile.readlines()
  ofile.close()
  for i in range(len(lines)):
    lines[i] = lines[i].replace("\n", "") 
    lines[i] = lines[i].split(" ")
  
  listU      = [ lines[i][0]  for i in range(len(lines))]
  listNparts = [ lines[i][1]  for i in range(len(lines))]

  return listNparts[ listU.index(strU) ].split(",")



###### BEGIN PLOT DECORATION VARIABLES
font = {'family' : 'normal',
        'weight' : 'bold',
        'size'   : 18}

plt.rc('font', **font)
plt.rc('text', usetex=True)

markersU0=["o", "s", "<", ">", "^", "v", "D", "p"]
markersNpart=["^","d", "8", "p", "v", "h", "x"]

###### END PLOT DECORATION VARIABLES
strU0=["0.2", "0.4", "0.6", "0.8", "1.0"]
strU0=["0.4"]
strDelta="0.0"
strDelta="1.0654849"
delta=float(strDelta)
#strNpart=["4096", "8192", "16384", "32768", "65536"]

fig, ax = plt.subplots(2,1, figsize=(8,8))
#ax[0].set_xscale("log")
ax[0].set_yscale("log")
ax[0].set_xlabel("$t/N^{\\delta}$", size=30)
ax[0].set_ylabel("$T-T_{eq}$", size=30)

ax[1].set_yscale("log")
ax[1].set_xscale("log")
ax[1].set_ylabel("$\\tau$", size=30, rotation=0)
ax[1].set_xlabel("$N$", size=30)

for nu in range(len(strU0)):
  flnOut = "U_"+strU0[nu]+".dat"
  ofile = open(flnOut, "w" )
  for nn in range(len(strNpart)):
    #ofile.write(strU0[nu]+" ")
    data = np.loadtxt("DT__U_"+strU0[nu]+"__N_"+strNpart[nn]+".dat")
    time = data[:,0]
    print strNpart[nn], len(time)
    DeltaTEQ   = data[:,1]
    popt, pcov = fitExp(time[Xmin[nn]:Xmax[nn]], np.abs(DeltaTEQ[Xmin[nn]:Xmax[nn]]))
    colValue   = float(nn)/float(len(strNpart))
    ax[0].plot(time, DeltaTEQ, color=plt.cm.Set1(colValue), label="$"+strNpart[nn]+"$" )
    ax[0].plot(time[Xmin[nn]:Xmax[nn]], np.exp(time[Xmin[nn]:Xmax[nn]]*popt[0] + popt[1]), color=plt.cm.Set1(colValue) )
    ofile.write(strNpart[nn]+" "+str(-1.0/popt[0])+"\n")
  
  ofile.close()
  data = np.loadtxt(flnOut)
  popt, pcov = fitPowLaw(data[2:,0], data[2:,1])
  delta =  popt[0]
  ax[1].plot(data[:,0], data[:,1], '-o')
  YY = powLaw(data[:,0], popt[0], np.exp(popt[1]))
  ax[1].plot(data[:,0], YY, '--')
  ax[1].text(1e4, 1e4, "$\\delta = "+str(delta)+"$", fontsize=15)
  
  ax[0].clear()
  ax[0].set_yscale("log")
  ax[0].set_xlabel("$t/N^{\\delta}$", size=30)
  ax[0].set_ylabel("$T-T_{eq}$", size=30)
 
  for nn in range(len(strNpart)):  
    data = np.loadtxt("DT__U_"+strU0[nu]+"__N_"+strNpart[nn]+".dat")
    time = data[:,0]
    DeltaTEQ   = data[:,1]
    timeScaled = time/(float(strNpart[nn])**delta)
    colValue   = float(nn)/float(len(strNpart))
    ax[0].plot(timeScaled, DeltaTEQ, color=plt.cm.Set1(colValue), label="$"+strNpart[nn]+"$" )
  

ax[0].legend(loc='best', prop={'size':10}, numpoints=1, frameon=False)
