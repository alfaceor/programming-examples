#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser(formatter_class=argparse.UsageGroupHelpFormatter)

bar = parser.add_usage_group(kind='mxg', dest='s|m')
bar.add_argument('-s', action='store_true', default=True)
bar.add_argument('-m', action='store_true', default=False)


bar = parser.add_usage_group(kind='mxg', dest='year|more')
bar.add_argument('-y', metavar='year', type=int)

baz = bar.add_usage_group(kind='any', dest='', joiner=' ', parens='[]')

g_13 = baz.add_usage_group(kind='mxg', dest='1|3')
g_13.add_argument('-1', dest='i1')
g_13.add_argument('-3', dest='i3')

baz.add_argument(metavar='month', type=int)
baz.add_argument(metavar='year', type=int)



parser = argparse.ArgumentParser()
# parser.add_argument("echo")
# parser.add_argument("nose", nargs=argparse.REMAINDER)
