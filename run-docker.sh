#!/bin/bash

docker build  -f Dockerfile -t alpine-for-9cc:latest .

docker run \
    -it \
    -v .:/mnt/ \
    alpine-for-9cc:latest
 