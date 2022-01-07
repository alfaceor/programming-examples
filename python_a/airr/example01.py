#!/usr/bin/env python3

import airr

# data/airr/HD13M_fmt19.tsv
# data/airr/HD13M_fmt7_db-pass.tsv
# data/airr/HD13N_imgt_db-pass.tsv
fln_rearrangement="data/airr/HD13M_fmt19.tsv"
zzz = airr.read_rearrangement(fln_rearrangement)
print(zzz.fields)
aaa = airr.create_rearrangement("joder.tsv")
print(aaa.fields)
import collections

dicto = collections.OrderedDict([('sequence', 'CCCAACCTATACTGGTACCGACAGGCTGCAGGCAGGGGCCTCCAGCTGCTCTTCTACTCCATTGGTATTGACCAGATCAGCTCTGAGGTGCCCCAGAATCTCTCAGCCTCCAGACCCCAGGACCGGCAGTTCATTCTGAGTTCTAAGAAGCTCCTCCTCAGTGACTCTGGCTTCTATCTCTGTGCCTGGAGTGTACCTAGCGGGGTGGGACCAAAAACATTCAGTACTTCGGCGCCGGGACCCGGCTCTCAGTGCTGG'), ('quality', None), ('sequence_aa', None), ('rev_comp', False), ('productive', None), ('vj_in_frame', None), ('stop_codon', None), ('complete_vdj', None), ('locus', None), ('sequence_alignment', 'ACTATTCATCAATGGCCAGCGACCCTGGTGCAGCCTGTGGGCAGCCCGCTCTCTCTGGAGTGCACTGTGGAGGGAACATCAAACCCCAACCTATACTGGTACCGACAGGCTGCAGGCAGGGGCCTCCAGCTGCTCTTCTACTCCATTGGTATTGACCAGATCAGCTCTGAGGTGCCCCAGAATCTCTCAGCCTCCAGACCCCAGGACCGGCAGTTCATTCTGAGTTCTAAGAAGCTCCTCCTCAGTGACTCTGGCTTCTATCTCTGTGCCTGGAGTGTACCTAGCGGGGTGGGACCAAAAACATTCAGTACTTCGGCGCCGGGACCCGGCTCTCAGTGCTGG'), ('quality_alignment', None), ('sequence_alignment_aa', None), ('junction', None), ('junction_aa', None), ('np1', 'CT'), ('np1_aa', None), ('np2', 'TGGGA'), ('np2_aa', None), ('np3', None), ('np3_aa', None), ('v_call', 'M13554|TRBV30*04|Homo sapiens|(F)|V-REGION|1..276|276 nt|1| | | | |276+0=276| Extended by 2 | |'), ('v_score', 1390), ('v_identity', None), ('v_support', None), ('v_cigar', '278M'), ('v_sequence_start', 1), ('v_sequence_end', 278), ('v_germline_start', 84), ('v_germline_end', 276), ('v_alignment_start', None), ('v_alignment_end', None), ('d_call', ' TRBD2*01'), ('d_score', 35), ('d_identity', None), ('d_support', None), ('d_cigar', '7M'), ('d_sequence_start', 280), ('d_sequence_end', 286), ('d_germline_start', 7), ('d_germline_end', 14), ('d_alignment_start', None), ('d_alignment_end', None), ('j_call', 'X02987|TRBJ2-4*01|Homo sapiens|F|J-REGION|1432..1481|50 nt|2| | | | |50+0=50| | |'), ('j_score', 240), ('j_identity', None), ('j_support', None), ('j_cigar', '48M'), ('j_sequence_start', 10), ('j_sequence_end', 57), ('j_germline_start', 3), ('j_germline_end', 51), ('j_alignment_start', None), ('j_alignment_end', None)])


dicto = collections.OrderedDict([('sequence_id', 5), ('sequence', 'CCCAACCTATACTGGTACCGACAGGCTGCAGGCAGGGGCCTCCAGCTGCTCTTCTACTCCATTGGTATTGACCAGATCAGCTCTGAGGTGCCCCAGAATCTCTCAGCCTCCAGACCCCAGGACCGGCAGTTCATTCTGAGTTCTAAGAAGCTCCTCCTCAGTGACTCTGGCTTCTATCTCTGTGCCTGGAGTGTACCTAGCGGGGTGGGACCAAAAACATTCAGTACTTCGGCGCCGGGACCCGGCTCTCAGTGCTGG'), ('quality', None), ('sequence_aa', None), ('rev_comp', False), ('productive', None), ('vj_in_frame', None), ('stop_codon', None), ('complete_vdj', None), ('locus', None), ('sequence_alignment', 'ACTATTCATCAATGGCCAGCGACCCTGGTGCAGCCTGTGGGCAGCCCGCTCTCTCTGGAGTGCACTGTGGAGGGAACATCAAACCCCAACCTATACTGGTACCGACAGGCTGCAGGCAGGGGCCTCCAGCTGCTCTTCTACTCCATTGGTATTGACCAGATCAGCTCTGAGGTGCCCCAGAATCTCTCAGCCTCCAGACCCCAGGACCGGCAGTTCATTCTGAGTTCTAAGAAGCTCCTCCTCAGTGACTCTGGCTTCTATCTCTGTGCCTGGAGTGTACCTAGCGGGGTGGGACCAAAAACATTCAGTACTTCGGCGCCGGGACCCGGCTCTCAGTGCTGG'), ('quality_alignment', None), ('sequence_alignment_aa', None), ('junction', None), ('junction_aa', None), ('n1_length', 2), ('np1', 'CT'), ('np1_aa', None), ('np1_length', 4), ('n2_length', 5), ('np2', 'TGGGA'), ('np2_aa', None), ('np2_length', 5), ('p3v_length', 2), ('p5d_length', 0), ('p3d_length', 0), ('p5j_length', 0), ('v_call', 'M13554|TRBV30*04|Homo sapiens|(F)|V-REGION|1..276|276 nt|1| | | | |276+0=276| Extended by 2 | |'), ('v_score', 1390), ('v_identity', None), ('v_support', None), ('v_cigar', '278M'), ('v_sequence_start', 1), ('v_sequence_end', 278), ('v_germline_start', 84), ('v_germline_end', 276), ('v_alignment_start', None), ('v_alignment_end', None), ('d_call', ' TRBD2*01'), ('d_score', 35), ('d_identity', None), ('d_support', None), ('d_cigar', '7M'), ('d_sequence_start', 280), ('d_sequence_end', 286), ('d_germline_start', 7), ('d_germline_end', 14), ('d_alignment_start', None), ('d_alignment_end', None), ('j_call', 'X02987|TRBJ2-4*01|Homo sapiens|F|J-REGION|1432..1481|50 nt|2| | | | |50+0=50| | |'), ('j_score', 240), ('j_identity', None), ('j_support', None), ('j_cigar', '48M'), ('j_sequence_start', 10), ('j_sequence_end', 57), ('j_germline_start', 3), ('j_germline_end', 51), ('j_alignment_start', None), ('j_alignment_end', None)])


print("AAAAAAAAAAAAaa",dicto.keys())
aaa.write(dicto)
print(aaa.fields)
aaa.close()
