#!/usr/bin/env python

def func01(arg01):
    try:
        print("func01 ", arg01)
    except Exception as e:
        raise e

def func02(karg01=None):
    print("func02")

try:
    func03()
except NameError as e:
    try:
        print("NameError: ", e)
        func01()
    except TypeError as e:
        try:
            print("TypeError: ", e)
            func01('BBB')
        except Exception as e:
            raise e
    except Exception as e:
        raise e
except Exception as e:
    raise e

