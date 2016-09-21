all:code clean

code:kill raise alarm sigset sigprocmask 8-1blocktest 8-3blockchild

kill:kill.o
	cc -o kill kill.o
kill.o:kill.c
	cc -c kill.c

raise:raise.o
	cc -o raise raise.o
raise.o:raise.c
	cc -c raise.c

alarm:alarm.o
	cc -o alarm alarm.o
alarm.o:alarm.c
	cc -c alarm.c

sigset:sigset.o
	cc -o sigset sigset.o
sigset.o:sigset.c
	cc -c sigset.c

sigprocmask:sigprocmask.o
	cc -o sigprocmask sigprocmask.o
sigprocmask.o:sigprocmask.c
	cc -c sigprocmask.c

8-1blocktest:8-1blocktest.o
	cc -o 8-1blocktest 8-1blocktest.o -lm
8-1blicktest.o:8-1blocktest.c
	cc-c 8-1blocktest.c

8-3blockchild:8-3blockchild.o
	cc -o 8-3blockchild 8-3blockchild.o
8-3blockchild.o:8-3blockchild.c
	cc -c 8-3blockchild.c


.PHONY:
clean:
	rm kill.o raise.o alarm.o sigset.o sigprocmask.o 8-1blocktest.o

