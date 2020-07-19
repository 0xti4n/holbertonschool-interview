#!/usr/bin/python3
"""unlock boxes"""


def canUnlockAll(boxes):
    """Function that unlock boxes"""
    if len(boxes) == 0:
        return False

    key = boxes[0]
    map_list = [[]] * len(boxes)
    map_list[0] = True
    copy_keys = []

    if not isinstance(key, list):
        return False

    if len(key) == 0:
        return False

    if key[0] > len(boxes) - 1:
        return False

    while key:
        if key[0] > len(boxes) - 1:
            return False
        if isinstance(boxes[key[0]], list):
            if boxes[key[0]] == []:
                map_list[key[0]] = True
            map_list[key[0]] = True

            for i in boxes[key[0]]:
                if i > len(boxes) - 1:
                    return False
                if i != 0:
                    if i not in key and i not in copy_keys:
                        key.append(i)
            copy = key.pop(0)
            copy_keys.append(copy)
    return all(map_list)
