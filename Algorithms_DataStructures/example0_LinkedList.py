#!/usr/bin/env python3
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
    def __init__(self):
        self.head = None

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)

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

