#include "P1.h"
#include <time.h>

//submenu 1
int menuP1() {    
    do {
        system("CLS");
        char option;
        printf("Problema 1 - Listas:\n");
        printf("A - Concatenar L1 e L2\n");
        printf("B - Jogo\n");
        printf("C - \n");
        printf("X - Voltar\n");
        printf("Opcao: ");
        scanf(" %c", &option);

        system("CLS");

        switch (option) {
        case ('A'): case ('a'):
            pA();
            break;
            
        case ('B'): case ('b'):
            pB();
            break;

        case ('C'): case ('c'):
            printf("Opcao C");
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

//randomiza numeros para preencher listas 1 e 2 do PA
int numGen(int interval) {
    //srand(time(NULL));
    return rand() % interval;
}

//inicializa lista apontado para null
void init(Lista *l) {
    l->first = (Block *) malloc (sizeof(Block));
    l->last = l->first;
    l->first->next = NULL;
}

//inserir item especifico na lista
void insert(Lista *l, Item d) {
    l->last->next = (Block *) malloc (sizeof(Block));
    l->last = l->last->next;
    l->last->data = d;
    l->last->next = NULL;
}

//remover item especifico na lista
void remove(Lista *l, Item d) {
    Block *value, *temp;

    if(l->last == l->first || l == NULL || l->last->next == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    value = l->first;
    while (value->next != NULL) {
        if(value->next->data.val != d.val) {
            value = value->next;
        } else{
            temp = value;
            value = value->next;
            temp->next = value->next;
            free(value);
        }
    }
    
}

//esvaziar a lista inteira
void empty(Lista *l) {
    Block *value, *temp;

    if(l->last == l->first || l == NULL || l->last->next == NULL) {
        printf("OK!\n");
        return;
    }
    
    value = l->first;
    while (value->next != NULL) {
        temp = value;
        value = value->next;
        temp->next = value->next;
        free(value);
    }
}

//troca entre 2 blocos
void swap(Block *a, Block *b) {
    Item aux;
    aux = a->data;
    a->data = b->data;
    a->data = aux;
}

//imprimir lista
void print(Lista *l) {
    Block *temp;

    temp = l->first->next;
    while (temp != NULL) {
        printf("%3d   ", temp->data.val);
        temp = temp->next;
    }
    printf("\n");
}

//problema 1A (permutacao de 2 listas)
void pA() {
    Lista L1, L2, L3;
    Item d;
    Block *aux1, *aux2;
    int i = 0, k = 0, temp;

    init(&L1);
    init(&L2);
    init(&L3);

    //preenchimento L1 e L2 -> par e impar respectivamente
    while (i < PA || k < PA) {
        temp = numGen(200);
        if (temp % 2 == 0 && i < PA) {
            d.val = temp;
            insert(&L1, d);
            i++;
        } else if (temp % 2 != 0 && k < PA) {
            d.val = temp;
            insert(&L2, d);
            k++;
        }
    }
    
    i = 0;
    k = 0;

    //preenchimento L3
    aux1 = L1.first->next;
    aux2 = L2.first->next;
    while (i < PA) {
        d = aux1->data;
        insert(&L3, d);
        d = aux2->data;
        insert(&L3, d);
        aux1 = aux1->next;
        aux2 = aux2->next;
        i++;
    }
    
    printf("---------------\nLista 1\n");
    print(&L1);
    printf("---------------\nLista 2\n");
    print(&L2);
    printf("---------------\nLista 3\n");
    print(&L3);

    printf("---------------\nEsvaziando listas...\n");
    printf("Lista 1: ");
    empty(&L1);
    printf("Lista 2: ");
    empty(&L2);
    printf("Lista 3: ");
    empty(&L3);
}

//problema 1B (jogo)
void pB() {
    Lista L1, L2;
    Item d;
    int i = 0, k = 0;
    
    init(&L1);
    init(&L2);

    while(i < PB || k < PB) {
        d.val = numGen(13);
        if (d.val != 0 && i < PB) { 
            insert(&L1, d);
            i++;
        }
        d.val = numGen(13);
        if (d.val != 0 && k < PB) {
            insert(&L2, d);
            k++;
        }
    }

    printf("---------------\nLista 1\n");
    print(&L1);
    printf("---------------\nLista 2\n");
    print(&L2);

    int temp = numGen(13);
    temp == 0 ? temp = 1 : NULL;

    printf("Numero inicial: %d\n", temp);

    
}


