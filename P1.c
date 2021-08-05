#include "P1.h"
#include <time.h>
#include <string.h>

//submenu 1
int menuP1() {
    do {
        system("CLS");
        char option;
        printf("Problema 1 - Listas:\n");
        printf("A - Concatenar L1 e L2\n");
        printf("B - Jogo\n");
        printf("C - Mercado\n");
        printf("X - Voltar\n");
        printf("Opcao: ");
        scanf(" %c", &option);

        system("CLS");

        switch (option) {
        case ('A'): case ('a'):
            p1A();
            break;

        case ('B'): case ('b'):
            p1B();
            break;

        case ('C'): case ('c'):
            p1C();
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

//retorna numeros randomizados no intervalo desejado
int numGen(int interval) {
    //srand(time(NULL));
    return rand() % interval;
}

//inicializa lista apontado para null
void initL(Lista* l) {
    l->first = (BlockP1*)malloc(sizeof(BlockP1));
    l->last = l->first;
    l->first->next = NULL;
}

//inserir item especifico na lista
void insertL(Lista* l, ItemP1 d) {
    l->last->next = (BlockP1*)malloc(sizeof(BlockP1));
    l->last = l->last->next;
    l->last->data = d;
    l->last->next = NULL;
}

//esvaziar a lista inteira -> rever
void emptyL(Lista* l) {
    BlockP1 *value, *temp;
    value = l->first->next;

    while (temp != NULL) {
        temp = value;
        value = temp->next;
        free(temp);
    }
    l->first->next = NULL;
    l->last = NULL;
}

//imprimir numeros da lista
void printValL(Lista* l) {
    BlockP1* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%3d   ", temp->data.val);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir caracteres da lista
void printStrL(Lista* l) {
    BlockP1* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%s ", temp->data.str);
        temp = temp->next;
    }
    printf("\n");

}

//problema 1A (permutacao de 2 listas)
void p1A() {
    Lista L1, L2, L3;
    ItemP1 d;
    BlockP1* aux1, * aux2;
    int i = 0, k = 0, temp;

    initL(&L1);
    initL(&L2);
    initL(&L3);

    //preenchimento L1 e L2 -> par e impar respectivamente
    while (i < P1A || k < P1A) {
        temp = numGen(200);
        if (temp % 2 == 0 && i < P1A) {
            d.val = temp;
            insertL(&L1, d);
            i++;
        }
        else if (temp % 2 != 0 && k < P1A) {
            d.val = temp;
            insertL(&L2, d);
            k++;
        }
    }

    //preenchimento L3
    aux1 = L1.first->next;
    aux2 = L2.first->next;
    while (i > 0) {
        d = aux1->data;
        insertL(&L3, d);
        d = aux2->data;
        insertL(&L3, d);
        aux1 = aux1->next;
        aux2 = aux2->next;
        i--;
    }

    printf("---------------\nLista 1\n");
    printValL(&L1);
    printf("---------------\nLista 2\n");
    printValL(&L2);
    printf("---------------\nLista 3\n");
    printValL(&L3);

    // emptyL(&L1);
    // emptyL(&L2);
    // emptyL(&L3);
}

//problema 1B (jogo)
void p1B() {
    Lista L1, L2, L3;
    BlockP1* temp1, * temp2, * temp3;
    ItemP1 d;
    int i = 0, k = 0;

    initL(&L1);
    initL(&L2);
    initL(&L3);

    //preenche L1 e L2
    while (i < P1B || k < P1B) {
        d.val = numGen(13);
        if (d.val != 0 && i < P1B) {
            insertL(&L1, d);
            i++;
        }
        d.val = numGen(13);
        if (d.val != 0 && k < P1B) {
            insertL(&L2, d);
            k++;
        }
    }

    //numero inicial para o jogo
    int temp = numGen(13);
    temp == 0 ? temp = 1 : temp;
    printf("...................\n"
        "Numero inicial: %d\n"
        "...................\n"
        "Regra: (L1[i] - inicial + L2[i] - inicial = ?) => O maior ganha!\n\n", temp);

    //preenche lista auxilixar (L3) e imprime L1 e L2 em intervalos
    temp1 = L1.first->next;
    temp2 = L2.first->next;
    printf("Pares: {");

    while (i > 0) {
        printf("{%d , %d", temp1->data.val, temp2->data.val);
        i != P1B - 2 ? printf("}, ") : printf("}");

        d.val = temp1->data.val - temp + temp2->data.val - temp;
        insertL(&L3, d);

        temp1 = temp1->next;
        temp2 = temp2->next;
        i--;
    }

    printf("}\n\n");

    temp1 = L3.first->next;
    while (temp1 != NULL) {

        printf("Soma %d: %d\n", i + 1, temp1->data.val);

        i++;
        temp2 = temp1;
        temp1 = temp2->next;
    }

    //comparacoes => rever caso de empate
    temp1 = L3.first->next;
    printf("---------------------------------");
    if (temp1->data.val > temp1->next->data.val && temp1->data.val > temp1->next->next->data.val)
        printf("\n|Soma 1 (valor: %d) vencedor!!!|\n", temp1->data.val);

    else if (temp1->next->data.val > temp1->data.val && temp1->next->data.val > temp1->next->next->data.val)
        printf("\n|Soma 2 (valor: %d) vencedor!!!|\n", temp1->next->data.val);

    else printf("\n|Soma 3 (valor: %d) vencedor!!!|\n", temp1->next->next->data.val);
    printf("---------------------------------\n");

    // emptyL(&L1);
    // emptyL(&L2);
    // emptyL(&L3);
}

//problema 1C (mercado) -> rever
void p1C() {
    Lista L1, L2, L3;
    ItemP1 d;

    //contadores
    int i = 0, j = 0, k = 0;
    char nome[25];

    printf("nome: ");
    fflush(stdin);
    gets(nome);

    initL(&L1);
    initL(&L2);
    initL(&L3);

    d.str = nome;

    insertL(&L1, d);
    printStrL(&L1);

    // emptyL(&L1);
    // emptyL(&L2);
    // emptyL(&L3);

}