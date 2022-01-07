#!/usr/bin/python
import numpy as np
import json

# Save
#dictionary = {'hello':'world'}
fit_rangeB2B = {
"0.0001" :  ( 100000, 1000000),
"0.00025":  ( 100000, 1000000),
"0.0005" :  ( 100000, 1000000),
"0.001"  :  ( 100000, 1000000),
"0.0025" :  ( 100000, 1000000),
"0.005"  :  ( 100000, 1000000),
"0.01"   :  ( 100000, 1000000),
"0.025"  :  (  50000, 1000000),
"0.05"   :  (  50000, 1000000),
"0.1"    :  (  50000, 1000000),
"0.25"   :  (  20000, 1000000),
"0.5"    :  (  10000, 1000000),
"1.0"    :  (  10000, 1000000)
}

print fit_rangeB2B
fit_rangeB2B_json = json.dumps(fit_rangeB2B)
print fit_rangeB2B_json

fit_rangeB2B_jsonLoad = json.loads(fit_rangeB2B_json)

ofile = open("file.json", "w")
print fit_rangeB2B_jsonLoad["0.05"]
tmin, tmax = fit_rangeB2B_jsonLoad["0.1"]
print tmin, tmax, tmin+tmax
ofile.write(fit_rangeB2B_json)

ofile.close()
#np.save('my_file.npy', fit_rangeB2B) 

# Load
#read_dictionary = np.load('my_file.npy').item()
#print(read_dictionary["0.001"]) # displays "world"
