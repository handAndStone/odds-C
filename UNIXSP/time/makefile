all:code clean

code:showtimes

showtimes:showtimes.o
	cc -o showtimes showtimes.o
showtimes.o:showtimes.c
	cc -c showtimes.c

clean:
	rm showtimes.o
