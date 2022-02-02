override CFLAGS :=  -Werror -Wall -std=gnu99 -O0 -g $(CFLAGS) -I.
CC = gcc

# hello_p - printf shows library
# hello_w - write - show system calls
# sigchld  - example of waiting for a child
prog = hello_p hello_w sigchld

all: $(prog)

.PHONY: clean 

clean:
	rm -f *.o *~ $(prog)
