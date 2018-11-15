mymake : mymake.o graphTools.o
	gcc mymake.o graphTools.o -o mymake
graphTools.o : graphTools.c graphTools.h
	gcc -Wall -c graphTools.c
mymake.o : mymake.c graphTools.h
	gcc -Wall -c mymake.c
