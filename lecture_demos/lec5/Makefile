override CFLAGS :=  -Werror -Wall -std=gnu99 -O0 -g $(CFLAGS) -I.
CC = gcc

# simplefork - simple fork to show gdb
prog = simplefork

all: $(prog)

.PHONY: clean 

clean:
	rm -f *.o *~ $(prog)
