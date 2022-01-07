#!/usr/bin/python3

conjunto = {'hola', 'como', 'estas'}
vj_dict_default = {
    'v_choice' : {},
    'j_choice' : {'v_choice'},
    'd_gene' : {'v_choice', 'j_choice'},
    'v_3_del' : {'v_choice'},
    'vd_ins' : conjunto,
    'vd_dinucl' : {},
    'dj_ins' : {},
    'dj_dinucl' : {}
}

print(vj_dict_default)
conjunto = {'XXXXXXXXXXXX' }
print(vj_dict_default)

# Use a dictionary as input for a function

def print_dict_values(**kargs):
    print( locals())

print_dict_values(**vj_dict_default)

