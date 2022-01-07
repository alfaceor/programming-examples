#!/usr/bin/env python3
import collections #.OrderedDict
from collections import OrderedDict

d = {'banana': 3, 'apple': 4, 'pear': 1, 'orange': 2}
print(d)

aaa = OrderedDict(sorted(d.items(), key=lambda t: t[0]))
print(aaa)
print(aaa['orange'])
aaa.popitem(last=False)
print(aaa)

aaa['joder'] = 7
print(aaa)

