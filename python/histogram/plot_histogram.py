#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

inFilename ="histograma.DAT" 
data = np.loadtxt(inFilename)


np.histogram(data)
