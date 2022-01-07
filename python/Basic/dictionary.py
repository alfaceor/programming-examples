#!/usr/bin/python3

vj_dict_default = {
    'v_choice' : {},
    'j_choice' : {'v_choice'},
    'd_gene' : {'v_choice', 'j_choice'},
    'v_3_del' : {'v_choice'},
    'd_5_del' : {'d_gene'},
    'd_3_del' : {'d_gene', 'd_5_del'},
    'j_5_del' : {'j_choice'},
    'vd_ins' : {},
    'vd_dinucl' : {},
    'dj_ins' : {},
    'dj_dinucl' : {}
}


# GeneChoice;V_gene;Undefined_side;7;v_choice
event_type = "GeneChoice"
seq_type = "V_gene"
seq_side = "Undefined_side"
priority = "7"
realizations = list()
name = ""
nickname = "v_choice"

dictIgorRec_Event = {
    "event_type": event_type, \
    "seq_type": seq_type, \
    "seq_side": seq_side, \
    "priority": priority, \
    "name": name, \
    "nickname": nickname
}


dict2 = {
    "event_type": "TESTANDO", \
    "seq_type": "Three_prime", \
    "nickname": "v_choice",
    "joder" : "mano"
}


print(dictIgorRec_Event)
if "puta" in dictIgorRec_Event:
    print(dictIgorRec_Event)
    #dictIgorRec_Event["puta"] = "quepario"

dictIgorRec_Event




