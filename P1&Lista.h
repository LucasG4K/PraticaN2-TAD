#ifndef P1_H
#define P1_H

#include <stdio.h>
#include <stdlib.h>
#define P1A 100
#define P1B   3
#define P1C   6

//lista padrao
typedef struct Lista Lista;
typedef struct BlockP1 BlockP1;
typedef struct ItemP1 ItemP1;

struct ItemP1 {
    int val;
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
void printL(Lista *l);

//lista problema C
typedef struct ListaC ListaC;
typedef struct BlockP1C BlockP1C;
typedef struct ItemP1C ItemP1C;

struct ItemP1C {
    int id;
    float val;
    char *produto;
    char *mercado;
};

struct BlockP1C {
    ItemP1C data;
    BlockP1C *next;
};

struct ListaC {
    BlockP1C *first;
    BlockP1C *last;
};

void initLc(ListaC *l);
void insertLc(ListaC *l, ItemP1C d);
void emptyLc(ListaC *l);
void printPrecoLc(ListaC* l);
void printIdLc(ListaC* l);
void printProdutoLc(ListaC* l);
void printMercadoLc(ListaC *l);
void printMercadoAllLc(ListaC *l);
void printProdutoAllc(ListaC *l);
void printAllLc(ListaC *l);

//Problema 1
int numGen(int interval);

int menuP1();
void p1A();
void p1B();
void p1C();

#endif