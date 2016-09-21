all:code clean


code:\
01-badprocessID\
09-parentwaitpid\
11-fanwaitmsg\
12-chainwaitmsg


01-badprocessID:01-badprocessID.o
	cc -o 01-badprocessID 01-badprocessID.o
01-badprocessID.o:01-badprocessID.c
	cc -c 01-badprocessID.c


09-parentwaitpid:09-parentwaitpid.o
	cc -o 09-parentwaitpid 09-parentwaitpid.o
09-parentwaitpid.o:09-parentwaitpid.c
	cc -c 09-parentwaitpid.c



11-fanwaitmsg:11-fanwaitmsg.o
	cc -o 11-fanwaitmsg 11-fanwaitmsg.o
11-fanwaitmsg.o:11-fanwaitmsg.c
	cc -c 11-fanwaitmsg.c


12-chainwaitmsg:12-chainwaitmsg.o
	cc -o 12-chainwaitmsg 12-chainwaitmsg.o
12-chainwaitmsg.o:12-chainwaitmsg.c
	cc -c 12-chainwaitmsg.c









clean:
	rm *.o	
