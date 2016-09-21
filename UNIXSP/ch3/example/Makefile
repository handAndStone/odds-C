all:code clean


code:\
01-outputPID\
02-outputIDs\
05-simplefork\
06-twoprocs\
09-fanwait\
10-showreturnstatus\

01-outputPID:01-outputPID.o
	cc -o 01-outputPID 01-outputPID.o
01-outputPID.o:01-outputPID.c
	cc -c 01-outputPID.c

02-outputIDs:02-outputIDs.o
	cc -o 02-outputIDs 02-outputIDs.o
02-outputIDs.o:02-outputIDs.c
	cc -c 02-outputIDs.c

05-simplefork:05-simplefork.o
	cc -o 05-simplefork 05-simplefork.o
05-simplefork.o:05-simplefork.c
	cc -c 05-simplefork.c

06-twoprocs:06-twoprocs.o
	cc -o 06-twoprocs 06-twoprocs.o
06-twoprocs.o:06-twoprocs.c
	cc -c 06-twoprocs.c


09-fanwait:09-fanwait.o
	cc -o 09-fanwait 09-fanwait.o
09-fanwait.o:09-fanwait.c
	cc -c 09-fanwait.c

10-showreturnstatus:10-showreturnstatus.o
	cc -o 10-showreturnstatus 10-showreturnstatus.o
10-showreturnstatus.o:10-showreturnstatus.c
	cc -c 10-showreturnstatus.c

























clean:
	rm *o
