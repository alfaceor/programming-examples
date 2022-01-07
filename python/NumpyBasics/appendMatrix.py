import numpy as np

aaa = np.ones(2*3).reshape(2,3)
bbb = np.zeros(4*3).reshape(4,3)

ccc=np.append(aaa,bbb, axis=0)

print aaa,bbb,ccc
