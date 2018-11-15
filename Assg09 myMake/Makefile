mymake: myMake.c graph.o graph.h
	gcc -Wall -g myMake.c graph.o graph.h -o mymake

graph.o: graph.c graph.h
	gcc -Wall -c graph.c -o graph.o

clean:
	rm *.o

test:
	echo "Test good makefile" >diffOut
	
	echo "a" >>diffOut
	-mymake mt1 a >myOut
	-exMymake mt1 a >exOut
	-diff myOut exOut >>diffOut
	
	echo "b" >>diffOut
	-mymake mt1 b >myOut
	-exMymake mt1 b >exOut
	-diff myOut exOut >>diffOut
	
	echo "c" >>diffOut
	-mymake mt1 c >myOut
	-exMymake mt1 c >exOut
	-diff myOut exOut >>diffOut
	
	echo "d" >>diffOut
	-mymake mt1 d >myOut
	-exMymake mt1 d >exOut
	-diff myOut exOut >>diffOut
	
	echo "e" >>diffOut
	-mymake mt1 e >myOut
	-exMymake mt1 e >exOut
	-diff myOut exOut >>diffOut
	
	echo "f" >>diffOut
	-mymake mt1 f >myOut
	-exMymake mt1 f >exOut
	-diff myOut exOut >>diffOut
	
	echo "g" >>diffOut
	-mymake mt1 g >myOut
	-exMymake mt1 g >exOut
	-diff myOut exOut >>diffOut
	
	
	