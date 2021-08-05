#ifndef P1_H
#define P1_H

#include <stdio.h>
#include <stdlib.h>
#define P1A 100
#define P1B   3
#define P1C   6

typedef struct Lista Lista;
typedef struct BlockP1 BlockP1;
typedef struct ItemP1 ItemP1;

struct ItemP1 {
    int val;
    char *str;//optando pela utilizacao desse modo pois o espaço alocado nao sera' tao grande por ser do tipo char
};

struct BlockP1 {
    ItemP1 data;
    BlockP1 *next;
};

struct Lista {
    BlockP1 *first;
    BlockP1 *last;
};

void initL(Lista *l);
void insertL(Lista *l, ItemP1 d);
void emptyL(Lista *l);
void printValL(Lista *l);
void printStrL(Lista *l);

int numGen(int interval);

int menuP1();
void p1A();
void p1B();
void p1C();

#endif