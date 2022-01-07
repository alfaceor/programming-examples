#!/usr/bin/env python3

from pygor3.imgt import *
from pathlib import Path
import tempfile
import time

records = get_gene_template("Mus+musculus", "TRBJ")
print(records)

flag_delete=False
tmp_dir = tempfile.TemporaryDirectory(prefix='pygor_tmp', dir=".")
print(tmp_dir)
tmp_file = tempfile.NamedTemporaryFile(prefix='genomic', dir=tmp_dir.name, delete=flag_delete)
print(tmp_file.name)
print('-'*10)
time.sleep(8)

