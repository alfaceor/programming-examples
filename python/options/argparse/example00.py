#!/usr/bin/env python

import argparse
parser = argparse.ArgumentParser()
# parser.add_argument("echo")
# parser.add_argument("nose", nargs=argparse.REMAINDER)

# Use IGoR default model
parser.add_argument("-s", "--species", dest="species", help='Igor species')
parser.add_argument("-c", "--chain", dest="chain", help='Igor chain') #, type=str, choices=['TRB', 'TRA'])

# Or specify directory in IGoR structure.
parser.add_argument("-m", "--model_path", dest="model_path",
                  help='IGoR model directory path, this path include ref_genomes and model_parms')

# To load all data files use batchname
parser.add_argument("-b", "--batch", dest="batch",
                  help='Batchname to identify run. If not set random name is generated')
# parser.add_option(dest="path_ref_genome")
parser.add_argument("-o", "--output", dest="output", help='filename of csv file to export data')

args = parser.parse_args()
print(args.species)
print(args)
print(type(args))



"""
parser = OptionParser()
# Use IGoR default model
parser.add_option("-s", "--species", dest="species", help='Igor species')
parser.add_option("-c", "--chain", dest="chain", help='Igor chain')

(options, args) = parser.parse_args()


"""
