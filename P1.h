#ifndef P1_H
#define P1_H

#include <stdio.h>
#include <stdlib.h>
#define PA 100
#define PB   3
#define PC   6

typedef struct Lista Lista;
typedef struct Block Block;
typedef struct Item Item;

struct Item {
    int val;
    char ch;//optando pela utilizacao desse modo pois o espaço alocado nao sera' tao grande por ser do tipo char
};

struct Block {
    Item data;
    Block *next;
};

struct Lista {
    Block *first;
    Block *last;
};

void init(Lista *l);
void insert(Lista *l, Item d);
void remove(Lista *l, Item d);
void swap(Block *a, Block *b);
void empty(Lista *l);
void printAll(Lista *l);

int numGen(int interval);

int menuP1();
void pA();
void pB();
void pC();

#endif