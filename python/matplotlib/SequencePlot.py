#!/usr/bin/python

import matplotlib.pyplot as plt
import matplotlib

#DNASeq='GCTGCTCCCTCCCAGACATCTGTGTACTTCTGTGCCAGCAGTTACGGAGCCCCCGGGACAGCCTTTTACGAGCAGTACTTCGGGCCG'

DNASeq='CARLOS'

fig, ax = plt.subplots()
ax.set_ylim(-1,1)
ax.set_xlim(-len(DNASeq),2*len(DNASeq))
Yseq=0
SeqStart = 0
SeqEnd   = len(DNASeq)
for i in range(len(DNASeq)):
    ax.text(SeqStart+i, Yseq, DNASeq[i])

patches=[]
patches.append(matplotlib.patches.Rectangle((-0.5,-0.5),1,1) )
patches.append(matplotlib.patches.Rectangle((0+2,0),1,1) )
print len(patches)
rectangulos = matplotlib.collections.PatchCollection(patches)
ax.add_collection(rectangulos)
ax.set_aspect('equal')


plt.show()
