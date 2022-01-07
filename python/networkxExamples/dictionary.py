#!/usr/bin/python
import matplotlib.pyplot as plt
import networkx as nx

vdj_dict = dict()
event_nickname = 'v_choice'
if not event_nickname in vdj_dict:
  vdj_dict[event_nickname]= set()
  vdj_dict[event_nickname].add(event_nickname)

#  vdj_dict.add(event_nickname)
#else:
print vdj_dict
#
#vdj_dict['d_3_del'].add('d_gene')
#vdj_dict['d_3_del'].add('d_gene')

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

#print vdj_dict
#print type(vdj_dict['d_3_del'])
G = nx.DiGraph(vdj_dict)
G1 = G.reverse(copy=True)

print G1.edges()
print "#"*20
A = nx.adjacency_matrix(G1)
print A.todense()
print G1.nodes, len(G1.nodes)

nx.draw(G1, with_labels=True)

plt.show()

