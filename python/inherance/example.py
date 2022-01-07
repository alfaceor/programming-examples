#!/usr/bin/python3

class MyDict(dict):
    def __keytransform__(self, key):
        return key

    def __init__(self, *args, **kwargs):
        self.update(*args, **kwargs)

    def aver(self):
        print("joder")


aaa = MyDict()
aaa["hola"]="AAA"
aaa["madre"]="BBB"
print(aaa)
aaa.aver()
