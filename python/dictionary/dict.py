#!/usr/bin/python

tel = {'jack': 4098, 'sape': 4139}
print tel['jack']


fit_range = {
"0.01" : (10, 1000),
"0.002": (20, 2000),
"0.003": (50, 5000)
}

strB2B="0.003"
tmin, tmax = fit_range[strB2B]
print tmin, tmax, tmin+tmax
