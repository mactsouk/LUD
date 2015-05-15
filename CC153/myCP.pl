#!/usr/bin/perl -w

use strict;
use File::Copy;

my $input = shift;
my $output = shift;

copy($input, $output) || 
    die "File copying failed: $!";

exit 0;
