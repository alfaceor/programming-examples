#!/usr/bin/python
from  optparse import OptionParser

parser = OptionParser()
parser.add_option("-X","--xlabel", dest="xlabel")
parser.add_option("-k","--column", dest="column")
parser.add_option("-q", "--quiet", action="store_false", dest="verbose", default=True, help="don't print status messages to stdout")


(options, args) = parser.parse_args()

#default values
if options.column == None:
  column=0
else:
  column=int(options.column)
  
if len(args) > 0:
  filename = args
else:
  print "no arguments!"

print filename, column

