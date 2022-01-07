#!/usr/bin/env python3

import xarray as xr
import numpy as np

cdr3_anch_v = np.random.randint(0, 10, 10)
cdr3_anch_j = np.random.randint(0, 3,  5)  

# cdr3_anch_v[4] = None
# cdr3_anch_j[2] = np.nan

print(type(cdr3_anch_v))
print(type(cdr3_anch_j))
print(cdr3_anch_j.dtype)

ds = xr.Dataset(
        {
            "anch_cdr3__v_choice" : (("v_choice"),  cdr3_anch_v),
            "anch_cdr3__j_choice" : (("j_choice"), cdr3_anch_j),
        },
        {
            "v_choice" : np.arange(10),
            "j_choice" : np.arange(5)
        }
        )

print(ds)


a = np.ma.array([1,2,3,4,5], dtype=int)
a[1] = np.ma.masked
#masked_array(data = [1 -- 3 4 5],
#             mask = [False  True False False False],
#       fill_value = 999999)
#
print(a)
print(a[4] + 100)
print(type(a[1]))
m = a[1] + 100
print(type(m))

bbb = np.array([2,3,5])
print(bbb.dtype)

str_sequence = "AGCCTGAA"
sst = str_sequence[a[1]:]
print(str_sequence)
print(sst)


