#!/bin/bash

cur=1

make

while (( "$cur" <= "15" ))
do
	echo "Gen TEST $cur"
	./generator $RANDOM > "tests/test"$cur".in"
	./validator < "tests/test"$cur".in"
	./main < "tests/test"$cur".in" > "tests/test"$cur".out"
	./validator < "tests/test"$cur".out"
	./checker "tests/test"$cur".in" "tests/test"$cur".out" "tests/test"$cur".in"
	let "cur = cur + 1"
done
