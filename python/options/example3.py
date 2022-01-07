#!/usr/bin/python
from  optparse import OptionParser

parser = OptionParser()
parser.add_option("-U", "--U0",    dest="strU0")
parser.add_option("-N", "--Npart", dest="strNpart")
parser.add_option("-R", "--Run", action="store_true", dest="Run", default=False, help="If -R is used then run the jobs")


(options, args) = parser.parse_args()

#default values
if options.strU0 == None:
  strU0=["0.5"]
else:
  strU0=(options.strU0).split(",")
U0 = map(float,strU0)

if options.strNpart == None:
  strNpart=["128"]
else:
  strNpart=(options.strNpart).split(",")
Npart = map(int,strNpart)


if len(args) > 0:
  filename = args
  print filename
else:
  print "no arguments!"

print "Type: ", type(options.Run)
if options.Run :
  print "-R run jobs", options.Run
else:
  print "not running jobs ", options.Run

