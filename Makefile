# Makefile to build bcp
# We will use the gcc compiler infrastructure
# for building

PREFIX ?= /usr/local

CC=gcc

CFLAGS_1=-c -D_FILE_OFFSET_BITS=64
CFLAGS_2=-D_FILE_OFFSET_BITS=64
# --- targets
all: bcp

bcp: bcp.c lib/control.o lib/networking.o
		$(CC) $(CFLAGS_2) bcp.c lib/control.o lib/networking.o -o bcp 
lib/control.o: lib/control.c
		$(CC) $(CFLAGS_1) lib/control.c -o lib/control.o
lib/networking.o: lib/networking.c lib/control.o
		$(CC) $(CFLAGS_1) lib/networking.c -o lib/networking.o

install: bcp
	cp -f bcp $(PREFIX)/bin/bcp

uninstall:
	rm -f $(PREFIX)/bin/bcp

clean:
	rm -rf bcp.o bcp lib/control.o lib/networking.o

.PHONY: install uninstall
