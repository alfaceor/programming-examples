#!/usr/bin/python


CSI="\x1B["
TERMCOLOR_RED=CSI+"31m"
TERMCOLOR_NO =CSI+"0m"


print CSI+"31;40m"+ " Colored text " +CSI+"0m"
print "Regular text"+ TERMCOLOR_RED+ " Colored text " +TERMCOLOR_NO+ ". Again regular text."


