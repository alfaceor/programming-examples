#!/usr/bin/python

def f (x) : return x**2
print f(8)
# ONE LINE ANONYMOUS FUNCTION
g = lambda x: x**2
print g(8)

f2 = lambda x, y : x+y
print f2(1,2)
print f2(7,-3)


# FILTER EXAMPLE
XX = range(9)
print XX

def isEven(x):
  if x %2 == 0:
    return True
  else:
    return False

XFIL = filter(isEven, XX)
print XFIL

# No need to define a function, lambda creates a function at the moment
XFILLAMB = filter(lambda x: x %2 == 0, XX)

print XFILLAMB

