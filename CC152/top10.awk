# Programmer: Mihalis Tsoukalos
#
# This bash one-liner reads a text file and counts
# how many times each word appears in it with the
# help of AWK, sort and uniq.
#
# For Linux User and Developer, issue 152

awk '{for (i = 1; i <= NF; i++) {print tolower($i);}}' file.txt | sort | uniq -c | sort -rn
