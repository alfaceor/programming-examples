#!/usr/bin/env python3
from collections import deque

palabra = 'asddf'
print("palabra: ", palabra)
aaa = deque(palabra)
bbb = aaa.pop()
print(aaa, bbb)
bbb = aaa.popleft()
print(aaa, bbb)


# 1. Create a class to represent a linked list
#  To save where the list starts
class LinkedList:
    def __init__(self):
        self.head = None

# 2. the nodes
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data

