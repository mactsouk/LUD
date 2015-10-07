#!/usr/bin/python

# Programmer: Mihalis Tsoukalos
# Date: Wednesday 01 July 2015

import sys
from time import time

def powerOf2(num):
    if (num == 1):
        return True 
    if ( (num == 0) or (num % 2 == 1)):
        return False
    return powerOf2( num / 2 )

def read_and_calculate(filename):
    file = open(filename, "r")
    # Read first line
    line = file.readline()
    while line:
        powerOf2(int(line))
        line = file.readline()
    file.close()

repetitions = 10
start = time()
for i in range(0, repetitions):
    sys.stdout.write(".")
    sys.stdout.flush()
    read_and_calculate(sys.argv[1])
end = time()

print "Number of repetitions: %d" % repetitions
print "Time: %f " % (end - start)
