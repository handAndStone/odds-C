all:code clean

code:\
01-readline\
02-copyfile1\
09-copyfilemain\
11-monitorfork\
12-whichisready

01-readline:01-readline.o
	cc -o 01-readline 01-readline.o
01-readline.o:01-readline.c
	cc -c 01-readline.c

02-copyfile1:02-copyfile1.o
	cc -o 02-copyfile1 02-copyfile1.o
02-copyfile1.o:02-copyfile1.c
	cc -c 02-copyfile1.c

09-copyfilemain:09-copyfilemain.o
	cc -o 09-copyfilemain 09-copyfilemain.o
09-copyfilemain.o:09-copyfilemain.c
	cc -c 09-copyfilemain.c

11-monitorfork:11-monitorfork.o
	cc -o 11-monitorfork 11-monitorfork.o
11-monitorfork.o:11-monitorfork.c
	cc -c 11-monitorfork.c

12-whichisready:12-whichisready.o
	cc -o 12-whichisready 12-whichisready.o
12-whichisready.o:12-whichisready.c
	cc -c 12-whichisready.c

























clean:
	rm *.o
