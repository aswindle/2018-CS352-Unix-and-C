mymake2: mymake2.c graph.o graph.h
	gcc -Wall -g mymake2.c graph.o graph.h -o mymake2

graph.o: graph.c graph.h
	gcc -Wall -c graph.c -o graph.o

.PHONY: clean
clean:
	-rm *.o
	-rm mymake2

clean2:
	rm *.test

test:
	echo "###Bad inputs###" >diffOut
	
	echo "Too many inputs" >>diffOut
	-mymake2 -f test1 A.test bad >myOut
	-ex_mymake2 -f test1 A.test bad >exOut
	-diff myOut exOut >>diffOut
	
	echo "-f twice" >>diffOut
	-mymake2 -f test1 -f >myOut
	-ex_mymake2 -f test1 -f >exOut
	-diff myOut exOut >>diffOut
	
	echo "bad file" >>diffOut
	-mymake2 -f badfile A.test bad >myOut
	-ex_mymake2 -f badfile A.test bad >exOut
	-diff myOut exOut >>diffOut
	
	echo "bad target" >>diffOut
	-mymake2 -f test1 bad.test >myOut
	-ex_mymake2 -f test1 bad.test >exOut
	-diff myOut exOut >>diffOut
	
	echo "###Test 1###" >>diffOut
	
	echo "A.test #1" >>diffOut
	make clean2
	-mymake2 -f test1 A.test >myOut
	make clean2
	-ex_mymake2 -f test1 A.test >exOut
	-diff myOut exOut >>diffOut
	
	echo "A.test #2" >>diffOut
	make clean2
	-mymake2 A.test -f test1 >myOut
	make clean2
	-ex_mymake2 A.test -f test1 >exOut
	-diff myOut exOut >>diffOut
	
	echo "A.test, all files already there" >>diffOut
	-mymake2 -f test1 A.test >myOut
	-ex_mymake2 -f test1 A.test >exOut
	-diff myOut exOut >>diffOut
	
	echo "B.test" >>diffOut
	make clean2
	-mymake2 -f test1 B.test >myOut
	make clean2
	-ex_mymake2 -f test1 B.test >exOut
	-diff myOut exOut >>diffOut
	
	echo "C.test" >>diffOut
	make clean2
	-mymake2 -f test1 C.test >myOut
	make clean2
	-ex_mymake2 -f test1 C.test >exOut
	-diff myOut exOut >>diffOut
	
	echo "D.test" >>diffOut
	make clean2
	-mymake2 -f test1 D.test >myOut
	make clean2
	-ex_mymake2 -f test1 D.test >exOut
	-diff myOut exOut >>diffOut