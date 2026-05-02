all: bin/Fork

bin/Fork: Fork.c
	gcc -Wall -g -o bin/Fork Fork.c

run: bin/Fork
	bin/Fork

clean:
	rm bin/Fork
