#!/usr/bin/python
# The idea is to have a file with the experiments and the parameters to simulate (Run in the cluster) after that, use the same file to plot and analize the data I want.

class InputData:
  def __init__(self):
    self.strF2B=""
    self.strB2F=""
    self.strB2B=""
    self.strHrad=""
    self.strBrad=""

  def setDataStringRow(self, strRow, separator=","):
      [ self.strF2B, self.strB2F, self.strB2B, self.strHrad, self.strBrad ] = strRow.split(separator)
  
  def setDataList(self, lista):
      [ self.strF2B, self.strB2F, self.strB2B, self.strHrad, self.strBrad ] = lista


import csv

###   with open('Read_csv_file.csv') as csvfile:
###     # dialect = csv.Sniffer().sniff(csvfile.read(1024))
###     # print dialect
###     #print list(csv.DictReader( csvfile))
###     reader = csv.reader( csvfile)
###     for row in reader:
###       print row

csvfile = open('Read_csv_file.csv')
reader  = csv.reader(csvfile)
header  = reader.next()
inp = InputData()
inp.setDataList(reader.next())
print inp.strHrad

#inp.setData()

###  import csv
###  
###  with open('Read_csv_file.csv') as csvfile:
###    mpg = list(csv.DictReader(csvfile))
###  
###  print mpg
###  print "= "*10
###  print mpg[0] #["strB2F"]
###  print "+="*10
###  print mpg[0]["strB2F"]



