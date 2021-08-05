#ifndef P2_H
#define P2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P2B 3
#define P2C 20

typedef struct ItemP2 ItemP2;
typedef struct BlockP2 BlockP2;
typedef struct Pilha Pilha;

struct ItemP2 {
    int val;
    char *txt;
};

struct BlockP2 {
    ItemP2 data;
    ItemP2 aux;
    BlockP2 *next;
};

struct Pilha {
    BlockP2 *base;
    BlockP2 *top;
};

void initP(Pilha *p);
void push(Pilha *p, ItemP2 d);
void pop(Pilha *p, ItemP2 *d);
void emptyP(Pilha *p);
void printValP(Pilha *p);
void printTxtP(Pilha *p);

int numGen(int interval);

int menuP2();
void p2A();
void p2B();
void p2C();

#endif