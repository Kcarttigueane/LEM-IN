#!/bin/bash

map_directory=`ls ./tests/maps/unsolved`

make re
clear

for file in $map_directory
do
    ./lem_in < "./tests/maps/unsolved/$file" > test
    if [ $? == 139 ]; then
        echo "SEGFAULT : $file"
    fi
    diff -s test ./tests/maps/solved/$file > /dev/null
    if [ $? != 0 ]; then
        echo "DIFF: $file"
    fi
done
