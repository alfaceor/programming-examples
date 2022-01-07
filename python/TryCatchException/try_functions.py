#!/usr/bin/env python

def func01():
    print("func01")

def func02():
    print("func02")

try:
    func03()
except Exception as e:
    func04()
except Exception as e:
    func02()

