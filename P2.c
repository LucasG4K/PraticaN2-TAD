#include "P2.h"

//submenu 2
int menuP2() {
    do {
        system("CLS");
        char option;
        printf("Problema 2 - Pilhas:\n");
        printf("A - Parenteses\n");
        printf("B - Tranferencia entre pilhas\n");
        printf("C - Co-primos\n");
        printf("X - Voltar\n");
        printf("Opcao: ");
        scanf(" %c", &option);

        system("CLS");

        switch (option) {
        case ('A'): case ('a'):
            p2A();
            break;

        case ('B'): case ('b'):
            //p2B();
            break;

        case ('C'): case ('c'):
            //p2C();
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
void pop(Pilha *p, ItemP2 d) {
    BlockP2 *temp;

    if (p->base == p->top|| p == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    temp = p->top;
    p->top = temp->next;
    d.val = temp->data.val;
    free(temp);
}

//esvaziar a pilha inteira -> rever
void emptyP(Pilha *p) {
    BlockP2 *temp, *aux;

    temp = p->top;
    while(temp->next != NULL) {
        p->top = temp->next;
        //d.val = temp->data.val;
        free(temp);
    }

    if (p->base == p->top|| p == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
}

//imprimir numeros da pilha
void printValP(Pilha *p) {
    BlockP2 *temp;

    temp = p->top;
    while(temp != p->base) {
        printf("%d\n", temp->data.val);
        temp = temp->next;
    }
}

//imprimir char da pilha
void printTxtP(Pilha *p) {
    BlockP2 *temp;

    temp = p->top;
    while(temp != p->base) {
        printf("%s\n", temp->data.txt);
        temp = temp->next;
    }
}

//retorna numeros randomizados no intervalo desejado
// int numGen(int interval) {
//     return rand() % interval;
// }

void p2A() {
    Pilha p;
    ItemP2 d;
    int control = 0;
    BlockP2 *temp;

    char teste[50];

    printf("Coloque os parenteses que deseja verificar: ");
    fflush(stdin);
    gets(teste);
    printf("--------------------\n");

    
    initP(&p);
    for (int i = 0; i < strlen(teste); i++) {
        if(teste[i] == '('){
            d.txt = "(";
            push(&p, d);
        } else if(teste[i] == ')') {
            control++;
        }
    }
    printf("Quantidade de ')': %d\n", control);
    printf("Verificando...\n");
    
    temp = p.top;
    while(temp != p.base) {
        if(temp != NULL) {
            control--;
            d = temp->data;
            printf("----\n %s  -> saindo\n----\n", d.txt);
            pop(&p, d);
            temp = temp->next;
        }
    }

    if (control == 0) printf("PARENTIZACAO CORRETA!\n");
    else printf("PARENTIZACAO ERRADA!\n");
}

void p2B() {

}

void p2C() {

}