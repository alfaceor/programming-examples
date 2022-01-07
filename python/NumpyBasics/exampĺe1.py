#!/usr/bin/python

import numpy as np

listData=[1, 2., 1.5, 3., 0, 5]
data=np.array(listData)
print data
print data[:-1]
print np.roll(data,1)
print data-np.roll(data,1)
print np.diff(data)
