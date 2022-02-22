override CFLAGS := -Wall -Werror -std=gnu99 -O0 -g $(CFLAGS) -I.
override LDFLAGS +=  -pthread
CC = gcc

prog = test_pthread_create_launches_start_routine test_pthread_barrier_basic  test_pthread_mutex_basic

all: $(prog) 

test_pthread_create_launches_start_routine: test_pthread_create_launches_start_routine.o
test_pthread_barrier_basic  : test_pthread_barrier_basic.o
test_pthread_mutex_basic: test_pthread_mutex_basic.o

# Run the test programs
check: 
	./run_tests.sh $(prog)

clean:
	rm -f *.o $(prog) *.o 

