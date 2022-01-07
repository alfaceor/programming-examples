#!/usr/bin/python
import pandas as pd

# Create a simple dataframe
data = [{'a': 1, 'b': 2, 'c':3}, {'a':10, 'b': 20, 'c': 30}] 

#GeneChoice_J_gene_Undefined_side_prio7_size{2};"
#               "Deletion_J_gene_Five_prime_prio5_size23

data = [{'event': 'del_3_j', 'priority': 5, 'Edges':['j_choice']},\
        {'event': 'j_choice', 'priority': 7, 'Edges':['v_choice']},\
        {'event': 'v_choice', 'priority': 7, 'Edges':[]}\
        ] 
aaa = pd.DataFrame(data).set_index('event')
aaa['nEdges'] = aaa['Edges'].map(len)
aaa
aaa.sort_values(['priority', 'nEdges'], ascending=[False,True])
print(aaa)
