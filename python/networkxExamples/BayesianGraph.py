#!/usr/bin/python3
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

vdj_dict = {'d_3_del': {'d_gene', 'd_5_del' },
 'd_5_del': {'d_gene'},
 'd_gene': {'v_choice', 'j_choice'},
 'dj_dinucl': {},
 'dj_ins': {},
 'j_5_del': {'j_choice'},
 'j_choice': {'v_choice'},
 'v_3_del': {'v_choice'},
 'v_choice': {},
 'vd_dinucl': {},
 'vd_ins': {}}

G = nx.DiGraph(vdj_dict)
print(G.nodes)
Grev =  G.reverse()
# 1. print the correct joint probability of the network
def getProb(strEvent, G):
    strProb = "P("
    strProb = strProb + strEvent
    parents = list(G.predecessors(strEvent) )
    if not len(parents) == 0:
        strProb = strProb + " | "
        strProb = strProb + str(parents)
    strProb = strProb + ")"
    return strProb

#for strEvent in Grev.nodes:
#    print( getProb(strEvent,Grev) )

#getProb('v_choice',G)
#getProb('d_3_del',G)

aaa = list( nx.all_simple_paths(Grev, 'v_choice', 'd_3_del') )
print(aaa)
nx.draw(Grev, with_labels=True)

print("nx.topological_sort(G)")
ppp = nx.topological_sort(G)
for evento in ppp:
    print(evento)

plt.show()

print(G)
