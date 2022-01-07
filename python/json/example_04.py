#!/usr/bin/env python3

import json
fit_params = json.load(open("D_fit.json"))
print(type(fit_params))
print(fit_params)

json.dump(fit_params, open('other.json', 'w'), indent=4)


#print fit_params.items()
#for key, value in fit_params.items():
#  print key, value.items()

