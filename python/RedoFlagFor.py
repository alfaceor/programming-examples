#!/usr/bin/python

q1Flag = True
#while (q1Flag):
for i in range(3):
  print "HI!"
  q1 = raw_input("This job is finish, yes or no?")
  print "-"*15
  q1 = q1.title()
  print q1
  if q1 in ["No", "N", "no", "n", ""]:
    i = i-1
    print "Entendi ", i
  else:
    print "Next", i

