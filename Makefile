# Makefile to build bcp
# We will use the gcc compiler infrastructure
# for building

PREFIX ?= /usr/local

CC=gcc

CFLAGS="-c -D_FILE_OFFSET_BITS=64"

# --- targets
all: bcp

bcp: bcp.c
	gcc -D_FILE_OFFSET_BITS=64 -o bcp bcp.c

install: bcp
	cp -f bcp $(PREFIX)/bin/bcp

uninstall:
	rm -f $(PREFIX)/bin/bcp

clean:
	rm -rf bcp.o bcp

.PHONY: install uninstall
