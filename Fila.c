#include "P3&Fila.h"

//inicializa fila apontado para null
void initF(Fila *f) {
    f->first = (BlockP3 *) malloc (sizeof(BlockP3));
    f->last = f->first;
    f->first->next = NULL;
}

//inserir item especifico na fila
void enfileira(Fila *f, ItemP3 d) {
    f->last->next = (BlockP3 *) malloc (sizeof(BlockP3));
    f->last = f->last->next;
    f->last->data = d;
    f->last->next = NULL;
}

//remover item especifico da fila
void desenfileira(Fila *f, ItemP3 d) {
    BlockP3 *temp;

    if(f->first == f->last || f->first->next == NULL || f == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    temp = f->first;
    f->first = f->first->next;
    f->first->data = d;
    free(temp);
}

//esvaziar a fila inteira
void emptyF(Fila *f) {
    BlockP3 *temp, *value;

    value = f->first->next;
    while(value != NULL) {
        temp = value;
        value = temp->next;
        free(temp);
    }
    f->first = NULL;
    f->last  = NULL;
}

//imprimir numeros da fila
void printValF(Fila *f) {
    BlockP3 *temp;

    temp = f->first->next;
    while(temp != NULL) {
        printf("%d  ", temp->data.val);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir char da fila
void printTxtF(Fila *f) {
    BlockP3 *temp;

    temp = f->first->next;
    while(temp != NULL) {
        printf("%s", temp->data.txt);
        temp = temp->next;
    }
    printf("\n");
}