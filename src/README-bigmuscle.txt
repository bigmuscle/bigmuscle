

USING BIG-MUSCLE

BIG-MUSCLE can be built and used just like the traditional MUSCLE program it is based on.
The command line options are unchanged.

INPUT:

At present BIG-MUSCLE reads only from a file named "compositeinput.txt" in the program directory.
This file is processed into one called "compositeoutput.txt" which is the consensus sequences of
the input. This is used along with the full composite information.

Run big muscle as the program muscle with the following inputs: -in compositeoutput.txt -out [filename]

FORMATTING INPUT:

BIG-MUSCLE source includes a file compositeinput.txt as an example of the input the program takes.
Paste in FASTA format the alignments of groups of sequences you would like to composite.
Separate groups with a new line containing only the character "#"


INTERPRETING OUTPUT:

BIG-MUSCLE's final output is an alignment of the sequence groups performed by compositing in FASTA
format. The name for each group corresponds to the position of that group in the input files (the
first group is ">0" the second ">1", etc...).

Presently, I use a PHP script to put the initial alignment and the composite alignments into a mySQL 
database and use another script to reconstruct the final alignments as needed.

I will put the reconstruction process into the program itself as an additional output in a later update
and also make the input system more flexible.

CHANGES FROM ORIGINAL MUSCLE:

There may have been some minor, additional changes made as I explored various functions.
The only substantial changes are the following:

Modified:
main.cpp
msa2.cpp

Added:
readcomposite.h
readcomposite.cpp
composite.h
composite.cpp
compositevect.h
compositevect.cpp
