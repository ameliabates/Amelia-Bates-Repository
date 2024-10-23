all: pseudo-shell

pseudo-shell: main.o command.o string_parser.o
	gcc -o pseudo-shell main.o command.o string_parser.o

main.o: main.c
	gcc -c $^

command.o: command.c
	gcc -c $^

string_parser.o: string_parser.c
	gcc -c $^

clean:
	rm -f *.o pseudo-shell
