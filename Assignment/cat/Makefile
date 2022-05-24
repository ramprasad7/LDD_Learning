all:output

output:test_cat.o
	gcc -o output test_cat.o

test_cat.o:test_cat.c
	gcc -c -g -Wall test_cat.c


clean:
	rm -f *.o output
