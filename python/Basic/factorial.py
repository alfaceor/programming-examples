#!/usr/bin/python3

def factorial(n):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)



aaa = factorial(4)
print(aaa)
