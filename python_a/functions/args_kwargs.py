#!/usr/bin/env python3

def function01(a, b, c=None, d=True):
    params = locals()
    print(params)

def function02(*args, **kwargs):
    params = locals()
    print(params)

function01(4, 'a')
function02(4, 'a')
print('='*10)
try:
    function01(4, 'a', joder=None)
except Exception as e:
    print(e)
    pass
function02(4, 'a', joder=None)

