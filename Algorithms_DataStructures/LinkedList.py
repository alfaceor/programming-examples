#!/usr/bin/env python3
"""
https://realpython.com/linked-lists-python/
"""
from collections import deque


# 2. the nodes
class Node:
    def __init__(self, data):
        """
        :param data: any data to associated with the node
        """
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data

# 1. Create a class to represent a linked list
#  To save where the list starts
class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = Node(data=nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = Node(data=elem)
                node = node.next

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def add_first(self, node):
        node.next = self.head
        self.head = node

    def add_last(self, node):
        if self.head is None:
            self.head = node
            return
        for current_node in self:
            pass
        current_node.next = node

aaa = list("putaqparios")

my_iter = iter(aaa)
print("myiter: ", my_iter)
print(next(my_iter))
print(next(my_iter))
print("__next__()")
print(my_iter.__next__() )

# mmm = aaa.pop(0)
# print(mmm, aaa)
print("--------------")
llist = LinkedList(nodes=aaa)
for node in llist:
    print(node)


"""
llist = LinkedList()
print(llist)

first_node = Node("a")
llist.head = first_node
print(llist)


second_node = Node("b")
third_node = Node("c")

first_node.next = second_node
second_node.next = third_node
print(llist)
"""
