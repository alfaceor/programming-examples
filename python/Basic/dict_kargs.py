#!/usr/bin/python3

vj_dict_default = {
    'v_choice' : {},
    'j_choice' : {'v_choice'},
    'd_gene' : {'v_choice', 'j_choice'},
    'v_3_del' : {'v_choice'},
    'vd_ins' : {},
    'vd_dinucl' : {},
    'dj_ins' : {},
    'dj_dinucl' : {}
}

# Use a dictionary as input for a function
def print_dict_values(**kargs):
    print(50*'=')
    for karg in kargs.keys():
        print(karg)

print_dict_values(**vj_dict_default)


print_dict_values(joder='ohhhh')
