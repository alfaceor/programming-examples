#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()
XX = [1., 2., 3., 4., 5., 6.]
YY = [1., 1., 2., 2., 1., 3.]
YYerrMin = [1., 1., 2., 1., 1., 1.]
YYerrMax = [1., 1., 1., 2., 1., 1.]
asymmetric_error=[ YYerrMin, YYerrMax]
ax.errorbar(XX, YY, yerr=asymmetric_error)
plt.show()
