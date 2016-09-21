all:code phony


code:pid forklink forkfan execl
pid:pid.o
	cc -o pid pid.o
pid.o:pid.c
	cc -c pid.c

forklink:forklink.o
	cc -o forklink forklink.o
forklink.o:forklink.c
	cc -c forklink.c

forkfan:forkfan.o
	cc -o forkfan forkfan.o
forkfan.o:forkfan.c
	cc -c forkfan.c

execl:execl.o
	cc -o execl execl.o
execl.o:execl.c
	cc -c execl.c

phony:rm
rm:
	rm pid.o forklink.o forkfan.o execl.o
