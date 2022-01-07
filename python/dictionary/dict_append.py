#!/usr/bin/python

legendas = {}
legendas['key'] = 'value'

legendas['strHrad'] = {'lineas': [1, 2, 3], 'etiquetas' : ["fds", "vtnc", "ah?"]}

print(legendas)


print(legendas['strHrad'])
print(legendas['strHrad']['lineas'])
print(legendas['strHrad']['etiquetas'])

legendas['strHrad']['object']  = 8
print 10*"-"
print(legendas['strHrad'])
