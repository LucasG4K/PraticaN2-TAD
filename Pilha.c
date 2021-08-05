#include "P2&Pilha.h"

//inicializa pilha apontado para null
void initP(Pilha *p) {
    p->base = (BlockP2 *)malloc(sizeof(BlockP2));
    p->top = p->base;
    p->base->next = NULL;
}

//inserir item especifico na pilha
void push(Pilha *p, ItemP2 d) {
    BlockP2 *temp = (BlockP2 *)malloc(sizeof(BlockP2));
    temp->data = d;
    temp->next = p->top;
    p->top = temp;
}

//remover ItemP2 especifico da pilha
void pop(Pilha *p, ItemP2 *d) {
    BlockP2 *temp;

    if (p->base == p->top|| p == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    temp = p->top;
    p->top = temp->next;
    *d = temp->data;
    free(temp);
}

//esvaziar a pilha inteira -> rever
void emptyP(Pilha *p) {
    BlockP2 *temp, *value;

    value = p->top->next;
    while(value != NULL) {
        temp = value;
        value = temp->next;
        free(temp);
    }

    p->base = NULL;
    p->top  = NULL;
}

//imprimir numeros da pilha
void printValP(Pilha *p) {
    BlockP2 *temp;

    temp = p->top;
    while(temp != p->base) {
        printf("|%d|\n", temp->data.val);
        temp = temp->next;
    }
    printf("----\n");
}

//imprimir char da pilha
void printTxtP(Pilha *p) {
    BlockP2 *temp;

    temp = p->top;
    while(temp != p->base) {
        printf("|%s|\n", temp->data.txt);
        temp = temp->next;
    }
    printf("----\n");
}

