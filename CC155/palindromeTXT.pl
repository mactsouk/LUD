#!/usr/bin/perl -w

# Programmer: Mihalis Tsoukalos
# Date: Wednesday 03 June 2015
#
# Finding out if a word is a palindrome or not
#
# Reads an external text file

use strict;
use warnings;

# Give exactly one command line argument
my $numArgs = $#ARGV + 1;
if ($numArgs != 1)
{
    die "Please give exactly one command line argument\n";
}

my $numberOfLines = 0;
my $palindromes = 0;

my $file = $ARGV[0];
open my $FILE, $file || die "Could not open $file: $!";

while(my $line = <$FILE>)  
{
    $numberOfLines++;
    chomp $line;
    # Check
    if ($line eq reverse($line))
    {
         # print "$line is a palindrome!\n";
         $palindromes++;
    }
}

close($FILE) || die "Could not close $file: $!";

print "$numberOfLines lines read!\n";
print "$palindromes palindromes found!\n";

exit 0;
