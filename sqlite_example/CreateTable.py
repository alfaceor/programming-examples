#!/usr/bin/python
import sqlite3

sql_ct_cmd = dict()
sql_ct_cmd['indexed_sequences'] = """
-- IgorIndexedSeq table
CREATE TABLE IF NOT EXISTS IgorIndexedSeq (
    seq_index integer PRIMARY KEY,
    sequence text NOT NULL
);
"""


conn = sqlite3.connect('batchname.db')
cur = conn.cursor()
cur.executescript(sql_ct_cmd['indexed_sequences'])
conn.commit()
cur.close()


