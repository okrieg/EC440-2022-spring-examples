override CFLAGS :=  -Werror -Wall -std=gnu99 -O0 -g $(CFLAGS) -I.
CC = gcc

# simplefork - simple fork to show gdb
prog = wo zombie forkoff wo-static

all: $(prog)

wo-static: wo.c
	gcc $(CFLAGS) -static  wo.c   -o wo-static
#	gcc -O0 -Werror -Wall -static  wo.c   -o wo-static

.PHONY: clean all

clean:
	rm -f *.o *~ $(prog)
