#include "P2&Pilha.h"

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
            p2C();
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

void p2A() {
    Pilha p;
    ItemP2 d;
    int control = 0;
    BlockP2 *temp;

    char *teste = malloc(sizeof(char) * 50);

    printf("Insira a frase para verificar a parentizacao: ");
    fflush(stdin);
    gets(teste);
    printf("--------------------\n");

    initP(&p);
    for (int i = 0; i < strlen(teste); i++) {
        if(teste[i] == ')') {
            d.txt = ")";
            push(&p, d);
        } else if(teste[i] == '(') {
            d.txt = "(";
            push(&p, d);
        }
    }

    printTxtP(&p);

    temp = p.top;
    while(temp != p.base) {
        if(temp->data.txt == ")") 
            control++;

        else if(temp->data.txt == "(") 
            control--;

        pop(&p, &d);

        if (control < 0) {
            break;
        }
        temp = temp->next;
    }

    if (control == 0) printf("PARENTIZACAO CORRETA!\n");
    else printf("PARENTIZACAO ERRADA!\n");

    emptyP(&p);
}

void p2B() {
    
}

void p2C() {
    Pilha p;
    ItemP2 d;

    initP(&p);

    for (int i = 0; i < P2C; i++) {
        d.val = numGen(99);
        d.val == 0 ? d.val = 1 : d.val;
        printf("%d - ", d.val);
        push(&p, d);
    }
    printf("\n\n");

    printValP(&p);

    emptyP(&p);

}