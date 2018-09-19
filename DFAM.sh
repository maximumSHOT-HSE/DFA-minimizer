#!/bin/bash

cmd="$1"
inf="$2"
ouf="$3"

if [[ "$cmd" = "paint" ]]
then
	format=$(echo "$ouf" | sed -re "s/.*\.([^\.]*)/\1/g")
	ouf=$(echo "$ouf" | sed -re "s/(.*)\.([^\.]*)/\1/g")
	./compressor/paint.sh "$inf" "$ouf" "$format" > /dev/null
elif [[ "$cmd" = "compress" ]]
then
	cd compressor
	make > /dev/null
	./main < ../"$inf" > ../"$ouf"
	make clean > /dev/null
else
	echo "incorrect cmd"
fi
