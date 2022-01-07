#!/usr/bin/python

my_list = [i*i for i in range(10, 20)]
print my_list
print my_list[4]


my_gen = (i*i for i in range(10, 20))
print my_gen
print my_list[4]
print next(my_gen)
print next(my_gen)
