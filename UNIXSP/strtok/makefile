all:code clean

code:strtok strtok_advanced

strtok:strtok.o
	cc -o strtok strtok.o
strtok.o:strtok.c
	cc -c strtok.c

strtok_advanced:strtok_advanced.o
	cc -o strtok_advanced strtok_advanced.o
strtok_advanced.o:strtok_advanced.c
	cc -c strtok_advanced.c




clean:
	rm strtok.o
