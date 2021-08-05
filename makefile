output: main.o P1.o P2.o P3.o P4.o
	gcc main.o P1.o P2.o P3.o P4.o -o run

main.o: main.c
	gcc -c main.c

P1.o: P1.c P1.h
	gcc -c P1.c

P2.o: P2.c P2.h
	gcc -c P2.c

P3.o: P3.c P3.h
	gcc -c P3.c

P4.o: P4.c P4.h
	gcc -c P4.c

run:
	run.exe

clean:
	rm -f *.o *.exe