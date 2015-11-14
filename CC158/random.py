#!/usr/bin/python

# Programmer: Mihalis Tsoukalos
# Date: Wednesday 27 August 2015

import sys

totalResults = 0
filename = sys.argv[1]
file = open(filename, "r")
# Read first line
line = file.readline()

while line and totalResults < 10000:
    result = 0
    for i in range(0, int(line)):
        line = file.readline()
        result = result + int(line)
    result = result % 7 + 1
    totalResults = totalResults + 1
    print result
    # Read anothe line
    line = file.readline()
    
file.close()
