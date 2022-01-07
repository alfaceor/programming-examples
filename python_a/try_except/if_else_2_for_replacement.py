#!/usr/bin/env python3

lista = [ "nose", "tampoco", 100 ]
lista_nueva = list()
lista_nueva02 = list()
for element in lista:
    print('='*10)
    try:
        val = element
        lista_nueva.append(val)
        print("-- Dentro del try", val)
        val = val + 20
        lista_nueva02.append(val)
    except Exception as e:
        print("-- except", val, e)
        continue
    else:
        print("-- Else del try", val)
        break
else:
    print("-- else del for", val)

print('#'*10)
print(lista_nueva)
print(lista_nueva02)
