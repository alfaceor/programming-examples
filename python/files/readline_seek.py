#!/usr/bin/python



with open('bah.txt', 'w') as f:
  f.writelines('Hello %s\n' % i for i in range(5))

with open('bah.txt') as f:
  f.readline()
  x = f.tell()
  print type(x)
  f.readline()
  f.seek(x)
  f.readline()

