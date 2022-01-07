#!/usr/bin/python3

class C:
    def __init__(self):
        self._x = None

    def getx(self):
        return self._x

    def setx(self, value):
        self._x = value

    def delx(self):
        del self._x

    x = property(getx, setx, delx, "I'm the 'x' property.")


class D:
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


class F:
    def __init__(self):
        self.x = None

    @property
    def x(self):
        """I'm the 'x' property."""
        return self.x

    @x.setter
    def x(self, value):
        self.x = value

    @x.deleter
    def x(self):
        del self.x

ccc = D()
ccc.x = 'initial'
print(ccc.x)

ccc.x = 'final'
print(ccc.x)

print(ccc.x)

print(ccc._x)

for _ in range(5):
    print('a')
