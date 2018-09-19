# DFA-minimizer (deterministic finite automata)
Implementation of compression algorithm for deterministic finite state machine.

## How to run:

`./DFAM.sh <command> <input_file> <output_file>` (or `bash DFAM.sh` ...)

(**NB!** Incorrect arguments or incorrect io files format can lead to undefined behaviour)

(**NB! x2** You should execute DFAM.sh from root dir of project)

(**NB! x3** All file paths are relative)

## What commands are there?

* *compress*: take DFA from input file, compress it and place into the output file
(you can find format description of DFA below)

example: `./DFAM compress sample.in sample.out`

* *paint*: take DFA from input file, place picture into the output file

examples: 

- `./DFAM paint sample.in sample.pdf` (you will get `.pdf` file)

- `./DFAM paint sample.in sample.png` (you will get `.png` file)

## DFA format

- #### `<number of states;signed 32 bit int;> // enumeration from 1`

- #### `<number of directed edges; signed 32 bit int>`

- #### `<size of alphabet;signed 32 bit int;> // symbols in range [0, sigma - 1] `

- #### `<list of directed edge: <u_1, v_1, c_1>, ..., <u_m, v_m, c_m> >`

- #### `<starting state; signed 32 bit int> // value in range [1, n]`

- #### `<number of terminal states; 32 bit int> // value >= 0`

- #### `<list of terminal states: 1 <= st_1 < st_2 < ... < st_k>`

(See `compressor/tests/sample.*` for better understanding)

**NB!** In our situation num of edges = (num of states) * (size of alphabet)

## What additional packages do you need?

* utility `dot`
* compiler `g++` with `-std=c++17`
