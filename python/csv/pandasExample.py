#!/usr/bin/python
import pandas as pd

df = pd.read_csv("Read_csv_file.csv", dtype=str)
print df
print df.head()
print "- - "*5
print df.sort_values(by="strB2F", ascending=True)
print "- - "*5
print df["strB2F"]
print "++++"*10
print df.strB2F
print "++++"*10

for index, row in df.iterrows():
  print index, row.strB2F, row.strB2B, row.strHrad


