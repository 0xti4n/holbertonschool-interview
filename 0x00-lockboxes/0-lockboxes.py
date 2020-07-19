#!/usr/bin/python3
"""unlock boxes"""


def canUnlockAll(boxes):
    """Function that unlock boxes"""
    keys = [0]
    map_list = list(range(len(boxes)))
    unlock = False

    while map_list:
        copy_list = []
        for i in keys:
            if i in map_list:
                unlock = True
                for j in boxes[i]:
                    if j not in keys and j in map_list:
                        copy_list.append(j)
                map_list.remove(i)
        keys = [cpy for cpy in copy_list]
        if not unlock:
            return False
        unlock= False
    return True
