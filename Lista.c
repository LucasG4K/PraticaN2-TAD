#include "P1&Lista.h"

//-----------------------------------
//lista padrao

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

    while (value != NULL) {
        temp = value;
        value = temp->next;
        free(temp);
    }

    l->last  = NULL;
    l->first = NULL; 
}

//imprimir numeros da lista
void printL(Lista* l) {
    BlockP1* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%3d   ", temp->data.val);
        temp = temp->next;
    }
    printf("\n");
}


//-----------------------------------
//lista problema 1C

//inicializa listaC apontado para null
void initLc(ListaC* l) {
    l->first = (BlockP1C*)malloc(sizeof(BlockP1C));
    l->last = l->first;
    l->first->next = NULL;
}

//inserir item especifico na lista
void insertLc(ListaC* l, ItemP1C d) {
    l->last->next = (BlockP1C *)malloc(sizeof(BlockP1C));
    l->last = l->last->next;
    l->last->data = d;
    l->last->next = NULL;
}

//esvaziar a lista inteira -> rever
void emptyLc(ListaC* l) {
    BlockP1C *value, *temp;
    value = l->first->next;

    while (value != NULL) {
        temp = value;
        value = temp->next;
        free(temp);
    }

    l->last  = NULL;
    l->first = NULL; 
}

//imprimir preco da lista
void printPrecoLc(ListaC* l) {
    BlockP1C *temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%.2f   ", temp->data.val);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir id da lista
void printIdLc(ListaC* l) {
    BlockP1C *temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%3d   ", temp->data.id);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir produto da lista
void printProdutoLc(ListaC* l) {
    BlockP1C* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%s ", temp->data.produto);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir mercado
void printMercadoLc(ListaC *l) {
    BlockP1C* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("%s ", temp->data.mercado);
        temp = temp->next;
    }
    printf("\n");
}

//imprimir mercado e id juntos
void printMercadoAllLc(ListaC *l) {
    BlockP1C* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("Mercado: %s\n", temp->data.mercado);
        printf("Id: %d\n", temp->data.id);
        printf("----------------\n");
        temp = temp->next;
    }
    printf("\n");    
}

//imprimir produto, valor e id juntos
void printProdutoAllc(ListaC *l) {
    BlockP1C* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("Produto: %s\n", temp->data.produto);
        printf("Id: %d\n", temp->data.id);
        printf("Valor: R$%.2f\n", temp->data.val);
        printf("----------------\n");
        temp = temp->next;
    }
    printf("\n");    
}

//imprimir caracteres da lista
void printAllLc(ListaC *l) {
    BlockP1C* temp;
    temp = l->first->next;

    while (temp != NULL) {
        printf("Produto: %s\n", temp->data.produto);
        printf("Mercado: %s\n", temp->data.mercado);
        printf("Id: %d\n", temp->data.id);
        printf("Valor: R$%.2f\n", temp->data.val);
        printf("----------------\n");
        temp = temp->next;
    }
    printf("\n");
}

