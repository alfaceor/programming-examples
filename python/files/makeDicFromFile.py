#!/usr/bin/python


def getTeoTeqhmf(strU):
  ofile=open("sameU_HMF_XY.dot", "r")
  lines=ofile.readlines()
  ofile.close()
  
  headers= lines[0]
  lines.pop(0)
  for i in range(len(lines)):
    lines[i] = lines[i].replace("\n", "")
    lines[i] = lines[i].split()
  
  listU    = [ lines[i][0]  for i in range(len(lines))]
  listThmf = [ lines[i][1]  for i in range(len(lines))]
  listTxy  = [ lines[i][2]  for i in range(len(lines))]

  return listThmf[ listU.index(strU) ]


# find element
print getTeoTeqhmf("0.69")



#['#U Thmf Txy\n', '0.2 0.1869625 0.185152\n', '0.3 0.2650505 0.270828\n', '0.4 0.330653 0.363658\n', '0.5 0.3866135 0.469181\n', '0.6 0.4356345 0.589835\n', '0.69 0.475355 0.711376\n', '0.7 0.4795556 0.725592\n', '0.8 0.6 0.874731 \n', '0.9 0.8 1.034805\n', '1.0 1.0 1.20339 \n', '2.0 3.0 3.08087\n'] 12
#


#ofile.readline()
#ofile.readline()
