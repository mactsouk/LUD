#!/usr/bin/python

# Programmer: Mihalis Tsoukalos
# Date: Wednesday 01 July 2015

import random

MIN = 0
MAX = 1000
TOTAL = 1000000
for i in range(0, TOTAL):
    print random.randrange(MIN, MAX)
