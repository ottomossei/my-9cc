#!/bin/bash

mkdir -p tmp
cc -o ./tmp/test01 test01.s
./tmp/test01
echo $?
