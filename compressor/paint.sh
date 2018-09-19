#!/bin/bash

# <input graph> <output picture> <format: png, pdf, etc>

inf="$1"
buf=$(mktemp buf.XXXXXX)
ouf="$2"
format="$3"

# init as empty file
echo "" > "$buf"
echo -n "" > "$buf"
echo -ne "digraph G {\n" >> "$buf"

terms=($(cat "$inf" | tail -1))
for x in "${terms[@]}"
do
	echo -ne "\t$x [peripheries=3];\n" >> "$buf"
done

start_state=$(cat "$inf" | tail -3 | head -1)

echo -ne "\t$start_state [color=green];\n" >> "$buf"

# [2 ... sz - 3]
sz=$(cat "$inf" | wc -l)
edges=$(cat "$inf" | head -n $(("$sz" - "3")) | tail -n $(("$sz" - "4")))

edges=$(echo "$edges" | sed -re "s/([0-9]*) ([0-9]*) ([0-9]*)/\t\1 -> \2 [label=\"\3\"]/g")
echo -ne "$edges\n" >> "$buf"

echo -ne "}\n" >> "$buf"
# cat "$buf"
dot -T"$format" "$buf" -o "$ouf.$format"
rm -f "$buf"
