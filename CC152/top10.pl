#!/usr/bin/perl -w

# This version displays the Top 10
# words based on their frequency

use strict;

# Read the file
my $filename = "";
$filename = shift @ARGV || "Not Found!";

# Check if the file exists
if (-s $filename)
{
	open(FILE, "<$filename") || die "Cannot open file: $!";
}
else
{
	print "File $filename does not exist!\n";
	exit -1;
}

my $line = "";
my $word = "";
my %number = ();

while ($line = <FILE>)
{
	chomp $line;
	my @words = split( /\s+/, $line );
	for $word (@words)
	{
		if ( !defined($number{$word}) )
			{ $number{$word} = 1; }
		else
			{ $number{$word} = $number{$word} + 1; }
	}
}

# Find the top-10 words
my %times = ();
my $key = "";
foreach $key (keys %number)
{
	if ( !defined $times{ $number{$key} } )
		{ $times{ $number{$key} } = 1; }
	else
		{ $times{ $number{$key} } = $times{ $number{$key} } + 1; }
}

my @top10 = ();
my $i = 0;
foreach $key ( keys %times )
{
	$top10[$i] = $key;
	$i++;
}

my @sortedTop10 = sort { $b <=> $a } @top10;

# Find if we actually going to get a Top 10 or not...
my $max = 0;
if ( @sortedTop10 < 9 )
{
	$max = @sortedTop10;
}

for ( $i = 0; $i < $max; $i++ )
{
	foreach $key ( keys %number )
	{
		if ( $number{$key} == $sortedTop10[$i] )
		{
			print "$key appears $sortedTop10[$i] times\n";
		}
	}
}

close(FILE) || die "Cannot close file: $!\n";

exit 0;
