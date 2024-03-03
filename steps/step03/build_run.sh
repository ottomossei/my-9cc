#!/bin/bash

rm -r tmp
mkdir -p tmp


# study check method
cc -o ./tmp/test01 test01.c
./tmp/test01

echo "----------------"

# study char pointer
cc -o ./tmp/test02 test02.c
./tmp/test02

echo "----------------"

# study tokenize
cc -o ./tmp/test03 test03.c
./tmp/test03

echo "----------------"
