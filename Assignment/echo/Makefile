all:output

output:test_echo.o
	gcc -o output test_echo.o

test_echo.o:test_echo.c
	gcc -c -g -Wall test_echo.c


clean:
	rm -f *.o output
