#!/usr/bin/env python

from pathlib import Path
from typing import Union
import pandas as pd
import numpy as np
from pygor3 import (IgorModel, IgorModel_Parms)

def infer(input_sequences:Union[None, str, Path, pd.DataFrame, np.array, list]=None,
          model:Union[None,str,Path,IgorModel,IgorModel_Parms]=None):
    """Run igor infer with new data and model"""
    
    print(input_sequences, type(input_sequences))
    print(mdl, type(mdl))
    try:
        if type(model) == type(None):
            print("-- None", model)
        elif type(model) == type(str):
            print("-- str", model)
        elif type(model) == type(Path):
            print("-- Path", model)
        elif type(model) == type(pd.DataFrame):
            print("-- pd.DataFrame", model)
        elif type(model) == type(np.array):
            print("-- np.array", model)
        elif type(model) == type(IgorModel()):
            print("-- IgmorModel", model)
        else:
            print("-- waht??")
    except Exception as e:
        raise e


nt_list = ['A', 'C', 'G', 'T']
mdl = IgorModel()
input_seqs="/path/"

def random_seq(n_nt):
    return "".join( np.random.choice(nt_list, n_nt) )

input_seqs = [random_seq(12) for i in range(10)]

infer(input_seqs, mdl)
