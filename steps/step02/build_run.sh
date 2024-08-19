#!/bin/bash

mkdir -p tmp
cc -o ./tmp/test01 test01.s
./tmp/test01
echo $?

echo "----------------"

# study char pointer
cc -o ./tmp/test02 test02.c
./tmp/test02

echo "----------------"

# study strtol
cc -o ./tmp/test03 test03.c
./tmp/test03

echo "----------------"
