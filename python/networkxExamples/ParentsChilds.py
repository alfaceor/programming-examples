#!/usr/bin/python
import matplotlib.pyplot as plt
import networkx as nx

vdj_dict = {'d_3_del': {'d_gene', 'd_5_del', 'd_3_del'},
 'd_5_del': {'d_gene', 'd_5_del'},
 'd_gene': {'v_choice', 'j_choice', 'd_gene'},
 'dj_dinucl': {'dj_dinucl'},
 'dj_ins': {'dj_ins'},
 'j_5_del': {'j_choice', 'j_5_del'},
 'j_choice': {'v_choice', 'j_choice'},
 'v_3_del': {'v_choice', 'v_3_del'},
 'v_choice': {'v_choice'},
 'vd_dinucl': {'vd_dinucl'},
 'vd_ins': {'vd_ins'}}

G = nx.DiGraph(vdj_dict)

G.predecessors('d_gene')


