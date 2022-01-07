#!/usr/bin/env python3

from pathlib import Path
import time
from typing import TextIO



import tempfile
tmp_dir = tempfile.TemporaryDirectory(prefix='genomic', dir='.')
with open(tmp_dir.name + "/" + "ahorameves", "w") as tmp_file:
    tmp_file.write("joder\n")

time.sleep(30)
tmp_dir.cleanup()


