.PHONY: clean compile run

compile fork: main.o
	@gcc -o fork main.c -Wall

main.o: main.c
	@gcc -c main.c

run: fork
	@./fork

clean:
	rm -rf *.o fork
