#!/usr/bin/python3
import pandas as pd

# Create a simple dataframe

data = [{'event': 'del_3_j', 'priority': 5, 'Edges':['j_choice']},\
        {'event': 'j_choice', 'priority': 7, 'Edges':['v_choice']},\
        {'event': 'v_choice', 'priority': 7, 'Edges':[]}\
        ] 
aaa = pd.DataFrame(data).set_index('event')
aaa['nEdges'] = aaa['Edges'].map(len)
aaa
aaa.sort_values(['priority', 'nEdges'], ascending=[False,True])

with open('testo_to_csv.txt', "w") as ofile:
    ofile.write("vamos a ver como funciona esta vaina\n")
    #aaa.to_csv(ofile, sep=';', header=False)
    str_realizations = aaa.to_csv(sep=';', header=False)
    str_realizations_list = str_realizations.split("\n")
    #str_realizations = list( map(lambda x: "%"+x, str_realizations.split("\n") ) )
    print(str_realizations.split("\n"))
    ofile.write("FuncionO o no?\n")
