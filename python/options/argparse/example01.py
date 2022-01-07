#!/usr/bin/env python
import argparse
parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('integers', metavar='N', type=int, nargs='+',
                    help='an integer for the accumulator')
parser.add_argument('--sum', dest='accumulate', action='store_const',
                    const=sum, default=max,
                    help='sum the integers (default: find the max)')

args = parser.parse_args()
print(args.accumulate(args.integers))


"""
parser = OptionParser()
# Use IGoR default model
parser.add_option("-s", "--species", dest="species", help='Igor species')
parser.add_option("-c", "--chain", dest="chain", help='Igor chain')

# Or specify directory in IGoR structure.
parser.add_option("-m", "--model_path", dest="model_path",
                  help='IGoR model directory path, this path include ref_genomes and model_parms')

# To load all data files use batchname
parser.add_option("-b", "--batch", dest="batch",
                  help='Batchname to identify run. If not set random name is generated')
# parser.add_option(dest="path_ref_genome")
parser.add_option("-o", "--output", dest="output", help='filename of csv file to export data')

(options, args) = parser.parse_args()


"""
