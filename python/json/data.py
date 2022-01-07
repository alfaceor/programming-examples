#!/usr/bin/python

import json
data=json.load(open("data.json"))
#data=json.loads("data.json")
print data[0]["id"]
