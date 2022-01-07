#!/usr/bin/env python

import argparse

parser = argparse.ArgumentParser()

group = parser.add_mutually_exclusive_group()
group.add_argument('-a', action='store_true')
group.add_argument('-b', action='store_true')
group.add_argument('-c', action='store_true')
group.add_argument('-d')
group.add_argument('-e', nargs=2)

print parser.parse_args()


