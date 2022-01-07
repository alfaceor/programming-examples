#!/usr/bin/env python3

dictio = {'scenario_rank': 2, 'scenario_proba_cond_seq': 0.136241, 'v_choice': 77, 'j_choice': 4, 'd_gene': 0, 'v_3_del': 9, 'd_5_del': 6, 'j_5_del': 9, 'd_3_del': 8, 'vd_ins': 2, 'vd_dinucl': [2, 2], 'dj_ins': 13, 'dj_dinucl': [1, 2, 3, 1, 0, 1, 0, 2, 1, 0, 0, 0, 3], 'Mismatches': [], 'v_call': 'L36092|TRBV7-4*01|Homo sapiens|F|V-REGION|270051..270340|290 nt|1| | | | |290+0=290| | |', 'j_call': 'M14158|TRBJ1-5*01|Homo sapiens|F|J-REGION|2368..2417|50 nt|2| | | | |50+0=50| | |', 'd_call': ' TRBD1*01'}


another_dictio = dict()
for elem in dictio.keys():
    
    print(elem)
