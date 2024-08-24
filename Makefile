# Variables
CFLAGS=-std=c11 -g -static
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=build/%.o)
TARGET=build/9cc

# Default target: Build 9cc
9cc: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Compile source files to object files
build/%.o: src/%.c src/9cc.h | build
	$(CC) $(CFLAGS) -c -o $@ $<

# Ensure build directory exists
build:
	mkdir -p build

# Test script
test: $(TARGET)
	cp $(TARGET) ./9cc
	./test.sh
	rm ./9cc ./tmp ./tmp.s

# Clean up build files
clean:
	rm -rf build 9cc tmp tmp.s

.PHONY: 9cc test clean
