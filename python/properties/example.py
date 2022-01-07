#!/usr/bin/python3

class P:
    def __init__(self,x):
        self.x = x

    @property
    def x(self):
        return self.__x

    @x.setter
    def x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 1000:
            self.__x = 1000
        else:
            self.__x = x

p1 = P(52)
p2 = P(-4)
p3 = P(5000)
print(p1.x)
print(p2.x)
print(p3.x)

p1.x = 23
print(p1.x)



class G:
    def __init__(self,x):
        self.x = x

    @property
    def x(self):
        return self.__x

    @x.setter
    def x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 1000:
            self.__x = 1000
        else:
            self.__x = x

print('*'*20)

g1 = G(52)
g2 = G(-4)
g3 = G(5000)
print('-'*20)
print(g1.x)
print(g2.x)
print(g3.x)

g1.x = 23
print(g1.x)


### Parrot
class Parrot(object):
    def __init__(self):
        self._voltage = 100000

    @property
    def voltage(self):
        """Get the current voltage."""
        return self._voltage

print("="*20)
aaa = Parrot()
print(aaa.voltage)



class C(object):
    def __init__(self):
        self._x = None

    @property
    def x(self):
        """I'm the 'x' property."""
        return self._x

    @x.setter
    def x(self, value):
        self._x = value

    @x.deleter
    def x(self):
        del self._x



