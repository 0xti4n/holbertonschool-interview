#!/usr/bin/python3
"""Log file"""
import sys


status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}
file_size = 0
con = 1

try:
    for line in sys.stdin:
        token = line.split()

        if len(token) > 2:
            file_s = token[-1]
            status_code = token[-2]
            file_size += int(file_s)

            if status_code in status:
                status[status_code] += 1

        if con % 10 == 0:
            print('File size: {}'.format(file_size))
            for k, v in sorted(status.items()):
                if v != 0:
                    print('{}: {}'.format(k, v))
        con += 1

except Exception:
    pass

finally:
    print('File size: {}'.format(file_size))
    for k, v in sorted(status.items()):
        if v != 0:
            print('{}: {}'.format(k, v))
