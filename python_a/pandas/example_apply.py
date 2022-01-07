#!/usr/bin/env python3
import pandas as pd

def custom_sum(row):
    return row.sum()

def multiply_by_2(val):
    return val * 2


df = pd.DataFrame({ 'A': [1,2,3,4], 
                   'B': [10,20,30,40],
                   'C': [20,40,60,80]
                  }, 
                  index=['Row 1', 'Row 2', 'Row 3', 'Row 4'])

print(df)
df['D'] = df.apply(custom_sum, axis=1)
print("custom sum: axis=1: ", df)
df.loc['Row 5'] = df.apply(custom_sum, axis=0)
print("custom sum axis=0: ", df)
df['D'] = df['D'].apply(multiply_by_2)
#df['C'].apply(multiply_by_2, inplace=True)
print("apply_multiply: ", df)
