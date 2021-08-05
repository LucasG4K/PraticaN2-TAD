#include "P3&Fila.h"

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

    d = f.first->next->data;
    desenfileira(&f, d);

    printf("apos desenfileirar: \n");

    printValF(&f);
    printTxtF(&f);
}

// void p3B();

