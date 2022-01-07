#!/usr/bin/python3
class MyClass:
    param1 = "hola"
    param2 = "madre"
    def print(self):
        print("MyClass")
        print('param1 = ', self.param1)
        print('param2 = ', self.param2)

class MyClassInit:
    def __init__(self):
        self.param1 = "hola"
        self.param2 = "como estas"
    def print(self):
        print("MyClass")
        print('param1 = ', param1)
        print('param2 = ', param1)

cl = MyClass()
cl.print()
