#!/usr/bin/python
"""
@author: alfaceor
"""
import pynotify
#notification=pynotify.Notification ("New Time evolution Plot","",PWD+"/"+graph_directory+"/"+"t2_"+datafilename+".png")
notification=pynotify.Notification("Title","message","/home/alfaceor")
notification.show()

