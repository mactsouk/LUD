#!/usr/bin/perl -w

# Programmer: Mihalis Tsoukalos
# Date: Monday 20 April 2015
#

use strict;

my $WORD = "";
print "Give me a string: ";
$WORD = <>;
chomp $WORD;

if ( length($WORD) != 0 )
{
	print "The signature of $WORD is ".signature($WORD)."\n";
}

exit 0;

sub signature
{
	my $word = shift;
	my $sign = "";
	my @sign = ();
	my $i = 0;
	
	# Separate letters
	for ($i = 0; $i < length($word); $i++)
	{
		@sign = (@sign, substr($word, $i, 1));
	}
	
	# Perl Quick sort will be used for sorting the letters
	@sign = sort @sign;
	
	my $letter = "";
	foreach $letter (@sign)
	{
		$sign .= $letter;
	}
	
	return $sign;
}
