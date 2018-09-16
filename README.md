# DFA-minimizer (deterministic finite automata)
Implementation of compression algorithm for deterministic finite state machine.

## How to run:

`./DFAM.sh <command> <input_file> <output_file>` (or `bash DFAM.sh` ...)
(**NB!** Incorrect arguments or incorrect io files format can lead to undefined behaviour)

## What commands are there?

* compress: take DFA from input file, compress it and place in the output file
(you can find format description of DFA below)

## DFA format

`<number of states;signed 32 bit int;> (enumeration from 1)
<number of directed edges; signed 32 bit int>
<starting state; signed 32 bit int> (value in range [1, n])
<number of terminal states; 32 bit int> (value >= 0)
<list of terminal states: 1 <= st_1 < st_2 < ... < st_k>`
