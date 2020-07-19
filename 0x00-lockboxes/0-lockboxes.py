#!/usr/bin/python3
"""unlock boxes"""


def canUnlockAll(boxes):
    """Function that unlock boxes"""
    keys = [0]
    map_list = list(range(len(boxes)))
    unlock = False

    while keys:
        copy_keys = []
        if keys[0] in map_list:
            unlock = True
            for idx in boxes[keys[0]]:
                if idx not in keys and idx in map_list:
                    copy_keys.append(idx)
            map_list.remove(keys[0])
            keys.pop(0)
        keys.extend(copy_keys)
        if not unlock:
            return False
        unlock = False

    if len(map_list) > 0:
        return False
    return True
