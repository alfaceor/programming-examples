#!/usr/bin/env python3

import xarray as xr
import numpy as np
arr = xr.DataArray(np.arange(6).reshape(2,3),
                        dims=['A', 'B'],
                        coords=dict(A=[0, 1],
                                    B=[0, 1, 2]))

arr['lbl__A'] = ['a0', 'a1']
arr['lbl__B'] = ['b0', 'b1', 'b2']

print(arr)
