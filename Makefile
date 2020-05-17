.PHONY: run

run: try-except-c
	./try-except-c Makefile

try-except-c: try-except-c.c
	cc -o try-except-c try-except-c.c
