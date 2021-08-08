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
            p2B();
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

//parentizacao
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

    //para essa verificacao, a referencia para controle e' o parentese ')' pois ele e' responsavel por incrementar a variavel controle; alem disso sempre que a parentizacao estiver correta, esse caractere aparecera no topo e o '(' estara na base. Porem as regras nao se limitam a isso...
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

//transferencia entre pilhas
void p2B() {
    Pilha P1, P2;
    BlockP2 *temp;
    ItemP2 d;

    initP(&P1);
    initP(&P2);

    int cont = 0;
    int i = 0;

    while (cont < P2B) {
        d.val = cont + 1;
        push(&P1, d);
        cont++;
    }

    temp = P1.top;  
    while (cont > 0) {
        if (i == cont) {
            d = temp->data;
            push(&P2, d);
            temp = P1.top;
            cont--;
            i = 0;
        }
        i++;
        if (i != cont) temp = temp->next;
    }

    printf("P1: \n");
    printValP(&P1);
    printf("  |   Fazendo a transferencia...\n");
    printf("  V\n");
    printf("P2: \n");
    printValP(&P2);

    emptyP(&P1);
    emptyP(&P2);

}

//utilizado para o problema C
int mdc(int aux, int d) {
    if(aux % d == 0)
        return d;
    else
        return mdc(d, aux % d);
}

//co-primos
void p2C() {
    Pilha P1, v;
    ItemP2 d, d2;
    BlockP2 *temp;
    int aux;
    int cont = 0;

    initP(&P1);

    for (int i = 0; i < P2C; i++) {
        cont = 0;
        initP(&v);
        d.val = numGen(99);
        d.val == 0 ? d.val = 1 : d.val;
        push(&P1, d);

        printf("|%2.d| ->", d.val);
        
        aux = d.val;
        int j = 0;

        for (int j = 0; j < aux; j++) {
            d.val = aux - j;

            if(mdc(aux, d.val) == 1) {
                push(&v, d);
                cont++;
            }
        }

        
        printValHorizontalP(&v);
        printf("Phi = %d\n\n", cont);
        emptyP(&v);
    }

    emptyP(&P1);
}
