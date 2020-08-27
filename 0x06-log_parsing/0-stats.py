#!/usr/bin/python3
import signal
import sys


def signal_handler(sig, frame):
    print('File size: {}'.format(file_size))
    for k, v in sorted(status.items()):
        print('{}: {}'.format(k, v))
    sys.exit(0)

status = {}
file_size = 0
con = 0

for line in sys.stdin:
    token = line.split(' ')
    status_code = token[7]
    file_s = token[8]

    if status_code in status:
        status[status_code] += 1
    else:
        status[status_code] = 1

    file_size += int(file_s)
    if con % 10 == 0 and con != 0:
        print('File size: {}'.format(file_size))
        for k, v in sorted(status.items()):
            print('{}: {}'.format(k, v))
    con += 1
    signal.signal(signal.SIGINT, signal_handler)
