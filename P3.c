#include "P3.h"

//submenu 3
int menuP3() {
    do {
        system("CLS");
        char option;
        printf("Problema 3 - Filas:\n");
        printf("A - Binomio de Newton\n");
        printf("B - Classe maior valor\n");
        printf("X - Voltar\n");
        printf("Opcao: ");
        scanf(" %c", &option);

        system("CLS");

        switch (option) {
        case ('A'): case ('a'):
            p3A();
            break;

        case ('B'): case ('b'):
            // p3B();
            break;

        case ('X'): case ('x'):
            printf("Voltando para o menu principal...");
            return 0;
            break;

        default:
            printf("Opcao invalida!");
            break;
        }
        system("PAUSE");
    } while (1);
}

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

//esvaziar a fila inteira -> rever
// void emptyF(Fila *f);

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

void p3A() {
    Fila f;
    ItemP3 d;

    initF(&f);

    d.val = 10;
    d.txt = "Teste\n";
    enfileira(&f, d);
    enfileira(&f, d);
    enfileira(&f, d);

    printValF(&f);
    printTxtF(&f);
}

// void p3B();

