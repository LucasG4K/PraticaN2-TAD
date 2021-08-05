output: main.o P1.o P2.o P3.o P4.o Lista.o Pilha.o Fila.o
	gcc main.o P1.o P2.o P3.o P4.o Lista.o Pilha.o Fila.o -o run

main.o: main.c
	gcc -c main.c

P1.o: P1.c P1&Lista.h
	gcc -c P1.c

Lista.o: Lista.c P1&Lista.h
	gcc -c Lista.c

P2.o: P2.c P2&Pilha.h
	gcc -c P2.c

Pilha.o: Pilha.c P2&Pilha.h
	gcc -c Pilha.c

P3.o: P3.c P3&Fila.h
	gcc -c P3.c

Fila.o: Fila.c P3&Fila.h
	gcc -c Fila.c

P4.o: P4.c P4.h
	gcc -c P4.c

run:
	run.exe

clean:
	rm -f *.o *.exe