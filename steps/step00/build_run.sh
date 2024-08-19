#!/bin/bash
mkdir -p tmp
cc -o ./tmp/test1 test1.c
./tmp/test1
echo $?

cc -o ./tmp/test2 test2.s
./tmp/test2
echo $?

cc -o ./tmp/test3 test3.s
./tmp/test3
echo $?
