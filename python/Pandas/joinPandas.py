#!/usr/bin/python
import pandas as pd

caller = pd.DataFrame({'key': ['K0', 'K1', 'K2', 'K3', 'K4', 'K5'],\
    'A': ['A0', 'A1', 'A2', 'A3', 'A4', 'A5']})


other = pd.DataFrame({'key': ['K0', 'K1', 'K2'],\
    'B': ['B0', 'B1', 'B2']})

print caller
print other

print caller.join(other, lsuffix='_caller', rsuffix='_other')
print caller.set_index('key').join(other.set_index('key'))
print caller.join(other.set_index('key'), on='key')



