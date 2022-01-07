#!/usr/bin/python
from Bio import AlignIO

alignment = AlignIO.read(open("muscle_aligment_ouput.clw"),"clustal")

for record in alignment:
    print record.seq + " " +record.id

print type(alignment)
