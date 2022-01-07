#!/usr/bin/env python3

from pygor3.imgt import *
from pathlib import Path
import tempfile
import time

records = get_gene_template("Mus+musculus", "TRBJ")
print(records)

tmp_dir = tempfile.TemporaryDirectory(prefix='pygor_tmp', dir=".")
print(type(tmp_dir))
fln_fasta = str(tmp_dir.name) + "/genomic.fasta"
import os
os.system("mkdir -p " + tmp_dir.name)
save_records2fasta(records, fln_fasta )
# tmp_file = tempfile.NamedTemporaryFile(prefix='genomic', dir=tmp_dir.name, delete=flag_delete)
print('-'*10)
time.sleep(8)

