#!/usr/bin/env python3

import pandas as pd

def get_anchors_dataframe_from_csv(fln_csv, sep=';'):
    try:
        df_anchors = pd.read_csv(fln_csv, sep=sep, index_col='gene')
        return df_anchors
    except Exception as e:
        raise e

fln_csv = "olga_V_gene_CDR3_anchors.csv"
df_anchor = pd.read_csv(fln_csv, sep=';')
print(df_anchor.head())

separetors = [';', ',', '\t']
for sep in separetors:
    try:
        df_anchor = get_anchors_dataframe_from_csv(fln_csv, sep=sep)
        df_anchor['anchor_index']
        print(df_anchor.head())
        break
    except ValueError:
        print("WARNING: separator", sep, " do not work for ", fln_csv)
        pass

print("="*20)
print("df_anchor:", df_anchor)



