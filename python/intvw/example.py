#!/usr/bin/python

###   def print_directory_contents(sPath):
###     return  sPath.split("/")[-1]
###   
###   path = "/home/alfaceor/joder"
###   print path
###   print print_directory_contents(path)


def print_directory_contents(sPath):
 import os                                       
 for sChild in os.listdir(sPath):                
   sChildPath = os.path.join(sPath,sChild)
   if os.path.isdir(sChildPath):
     print_directory_contents(sChildPath)
   else:
     print(sChildPath)


path = "/home/alfaceor/Dropbox/programming-examples/python/subprocess"
print print_directory_contents(path)


