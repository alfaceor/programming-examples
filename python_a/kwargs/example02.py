#!/usr/bin/env python3

def funcion(**kwargs):
    igor_exec_path = kwargs.get('igor_exec_path')
    igor_datadir = kwargs.get('igor_datadir')
    print("igor_exec_path", igor_exec_path)
    print("igor_datadir", igor_datadir)

funcion(igor_exec_path='hola', igor_datadir='como', ccc='estas')
funcion(aaa='hola', bbb='como', ccc='estas' )

"""
igor_exec_path=None, igor_datadir=None,
                 igor_models_root_path=None, igor_species=None, igor_chain=None,
                 igor_model_dir_path=None,
                 igor_path_ref_genome=None, fln_genomicVs=None, fln_genomicDs=None, fln_genomicJs=None,
                 fln_V_gene_CDR3_anchors=None, fln_J_gene_CDR3_anchors=None,
                 igor_wd=None, igor_batchname=None,
                 igor_model_parms_file=None, igor_model_marginals_file=None,
                 igor_read_seqs=None
"""
