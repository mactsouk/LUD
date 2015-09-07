#!/usr/bin/perl -w

# Programmer: Mihalis Tsoukalos
# Date: Monday 25 May 2015
#
# Finding out if a word is a palindrome or not

use strict;
use warnings;

# Give exactly one command line argument
my $numArgs = $#ARGV + 1;
if ($numArgs != 1)
{
    die "Please give exactly one command line argument\n";
}

# Read the word
my $word = $ARGV[0];

# Check
if ( $word eq reverse($word) )
{
     print "$word is a palindrome!\n";
}
else
{
     print "$word is not a palindrome!\n";
}

exit 0;
