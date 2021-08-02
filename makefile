output: main.o P1.o P2.o P3.o P4.o
	g++ main.o P1.o P2.o P3.o P4.o -o run

main.o: main.c
	g++ -c main.c

P1.o: P1.c P1.h
	g++ -c P1.c

P2.o: P2.c P2.h
	g++ -c P2.c

P3.o: P3.c P3.h
	g++ -c P3.c

P4.o: P4.c P4.h
	g++ -c P4.c

run:
	run.exe

clean:
	rm -f *.o *.exe