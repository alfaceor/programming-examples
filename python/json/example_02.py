#!/usr/bin/python

import json
#j = json.loads('{"one" : "1", "two" : "2", "three" : "3"}')
#j = json.loads('{"one" : { text : "1", fitrange: [8, 9] }, "two" : "2", "three" : "3"}')
j = json.loads('{"one" : { text : "1", fitrange: [8, 9] }}')
print j["one"] #, j.three
print j["one"] #, j.three
