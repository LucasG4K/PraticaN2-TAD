#include "P3&Fila.h"

//submenu 3
int menuP3() {
    do {
        system("CLS");
        char option;
        printf("Problema 3 - Filas:\n");
        printf("A - Binomio de Newton (nao feita)\n");
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
            p3B();
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

// Binomio de Newton
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

//Classe maior valor
void p3B() {
    Fila F1;
    ItemP3 d;
    BlockP3 *temp;

    initF(&F1);

    for (int i = 0; i < 99; i++) {
        d.val = i + 1;
        for (int j = 0; j < 5; j++) 
            d.subVal[j] = numGen(9);

        enfileira(&F1, d);
    }

    temp = F1.first->next;
    while (temp != NULL) {
        temp->data.maior = temp->data.subVal[0];
        temp->data.pos = 0;
        temp->data.soma = 0; 
        for (int i = 0; i < 5; i++) {
            temp->data.soma += temp->data.subVal[i];
            if (temp->data.subVal[i] > temp->data.maior) {
                temp->data.maior = temp->data.subVal[i];
                temp->data.pos = i;
            }
        }
        temp = temp->next;
    }
    printValFc(&F1);

    temp = F1.first->next;
    int maior = temp->data.soma;
    int i = 0, control;
    while (temp != NULL) {
        if (maior < temp->data.soma) {
            maior = temp->data.soma;
            control = i + 1;
        }
        i++;
        temp = temp->next;
    }

    printf("Posicao da fila com a classe de maior valor: %d -> soma = %d\n", control, maior);
    

}
