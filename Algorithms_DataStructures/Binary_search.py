#!/usr/bin/env python3
import numpy as np

np_num = sorted(np.random.random(10))
print(np_num)

def bisect_search2(L, e):
    def bisect_search_helper(L,e, low, high):
        if high == low:
            return L[low] == e
        mid = (low+high) // 2
        if L[mid] == e:
            return True
        elif L[mid] > e:
            if low == mid: # nothing left to search
                return False
            else:
                return bisect_search_helper(L, e, low, mid -1)

        else:
            return bisect_search_helper(L, e, mid+1, high)

    if len(L) == 0:
        return False
    else:
        return bisect_search_helper(L, e, 0, len(L) -1 )


# EXPONENTIAL COMPLEXITY
def genSubsets(L):
    res = []
    if len(L) == 0:
        return [[]]
    smaller = genSubsets(L[:-1])
    extra = L[-1:]
    new = []
    for small in smaller:
        new.append(small+extra)

    return smaller + new
