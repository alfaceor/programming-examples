#!/usr/bin/python3

class Igor_Parms(dict):
    def __keytransform__(self, key):
        return key

    def __init__(self, *args, **kwargs):
        self.update(*args, **kwargs)

    def Event_list(self):
        print("joder")


aaa = MyDict()
aaa["hola"]="AAA"
aaa["madre"]="BBB"
print(aaa)
aaa.aver()
#  @Event_list
#GeneChoice;V_gene;Undefined_side;7;v_choice
#GeneChoice;D_gene;Undefined_side;6;d_gene
#GeneChoice;J_gene;Undefined_side;7;j_choice
#Deletion;V_gene;Three_prime;5;v_3_del
#Deletion;D_gene;Three_prime;5;d_3_del
#Deletion;D_gene;Five_prime;5;d_5_del
#Deletion;J_gene;Five_prime;5;j_5_del
#Insertion;VD_genes;Undefined_side;4;vd_ins
#Insertion;DJ_gene;Undefined_side;2;dj_ins
#DinucMarkov;VD_genes;Undefined_side;3;vd_dinucl
#DinucMarkov;DJ_gene;Undefined_side;1;dj_dinucl


#  @Edges


#  @ErrorRate
#SingleErrorRate


