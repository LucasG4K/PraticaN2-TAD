#ifndef P3_H
#define P3_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ItemP3 ItemP3;
typedef struct BlockP3 BlockP3;
typedef struct Fila Fila;

struct ItemP3 {
    int val;
    char *txt;
};

struct BlockP3 {
    ItemP3 data;
    BlockP3 *next;
};

struct Fila {
    BlockP3 *first;
    BlockP3 *last;
};

void initF(Fila *f);
void enfileira(Fila *f, ItemP3 d);
void desenfileira(Fila *f, ItemP3 d);
void emptyF(Fila *f);
void printValF(Fila *f);
void printTxtF(Fila *f);

int menuP3();
void p3A();
void p3B();

#endif