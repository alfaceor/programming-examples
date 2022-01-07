#!/usr/bin/python

import numpy as np

listData=[1, 2., 1.5, 3., 0, 5]
data=np.array(listData)
print data
print np.cos(data)
aaa = 1-np.cos(data)
bbb = np.array(range(len(data)))
print aaa
print bbb
print aaa*bbb

