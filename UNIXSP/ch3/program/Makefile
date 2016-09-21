all:code clean


code:\
01-simplechain\
02-simplefan\
04-execls\
05-execcmd

01-simplechain:01-simplechain.o
	cc -o 01-simplechain 01-simplechain.o
01-simplechain.o:01-simplechain.c
	cc -c 01-simplechain.c

02-simplefan:02-simplefan.o
	cc -o 02-simplefan 02-simplefan.o
02-simplefan.o:02-simplefan.c
	cc -c 02-simplefan.c


04-execls:04-execls.o
	cc -o 04-execls 04-execls.o
04-execls.o:04-execls.c
	cc -c 04-execls.c


05-execcmd:05-execcmd.o
	cc -o 05-execcmd 05-execcmd.o
05-execcmd.o:05-execcmd.c
	cc -c 05-execcmd.c

















clean:
	rm *.o
