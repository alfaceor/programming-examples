from .module1 import CP1D

import sys
print( sys.modules.keys() )

class CP2D:
    def __init__(self):
        self.q = [0, 0]
        self.v = [0, 0]
        self.a = [0, 0]
        self.cp1d = None

    def __str__(self):
        str_return = "q = " + str(self.q) + "\n"
        str_return = str_return + "v = " + str(self.v) + "\n"
        str_return = str_return + "a = " + str(self.a) + "\n"
        return str_return

    def update_q(self):
        self.q = self.q + 10

    def give_one(self):
        self.cp1d = CP1D()
        self.cp1d.q = 50
        return self.cp1d
    

