program: *.c
	clang *.c -o program

run: program
	./program

clean:
	rm -f program