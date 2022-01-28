override CFLAGS := -Wall -Werror -std=gnu99 -O1 -g $(CFLAGS) -I.

shell: myshell_parser.o 

myshell_parser.o: myshell_parser.c myshell_parser.h
test_simple_input.o: test_simple_input.c myshell_parser.h 
test_simple_input: test_simple_input myshell_parser.o

test_files=test_simple_input 

# Run the test programs
check: $(test_files) 
	bash run_tests.sh $(test_files) 

clean:
	rm -f *.o $(test_files) *~
