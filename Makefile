WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
TESTFALGS = -DTEST_CREATELIST -DTEST_ELIMINATE -DTEST_DELETENODE -DDEBUG
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose
EXEC = hw10

SRCS = main.c hw10.c
OBJS = $(SRCS:%.c=%.o)

$(EXEC): $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o $(EXEC)

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 

test1: $(EXEC)
	./$(EXEC) 6 3 > output1
	diff -w output1 testcases/expected1

test2: $(EXEC)
	./$(EXEC) 4 6 > output2
	diff -w output2 testcases/expected2

test3: $(EXEC)
	./$(EXEC) 25 7 > output3
	diff -w output3 testcases/expected3

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 6 3 > output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) 4 6 > output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) 25 7 > output3

clean: # remove all machine generated files
	rm -f $(EXEC) *.o output?
