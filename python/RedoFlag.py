#!/usr/bin/python

q1Flag = True
while (q1Flag):
  print "HI!"
  q1 = raw_input("This job is finish, yes or no?")
  print "-"*15
  q1 = q1.title()
  print q1
  if q1 in ["No", "N", "no", "n", ""]:
    q1Flag = True
  else:
    q1Flag = False

