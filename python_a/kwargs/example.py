#!/usr/bin/env python3

def funcion(**kwargs):
    print('modelspath' in kwargs)
    if ('modelspath' in kwargs) :
        if kwargs['modelspath'] is None:
            print("modelspath is None")
        print(kwargs)
    else:
        print("else:", kwargs)

funcion(aaa='hola', bbb='como', ccc='estas', modelspath=None)
funcion(aaa='hola', bbb='como', ccc='estas' )
