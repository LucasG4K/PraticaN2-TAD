# <div align="center"> Prática Nº2</div>

## <div align="center">Tipo abstrato de dados (TAD): Listas, Pilhas e Filas</div>


No trabalho proposto em aula, o objetivo era que nós, alunos, pudéssemos praticar as implementações de tipos abstratos de dado vistos previamente. Desse modo, o exercício para tal prática foi dividido nas seguintes etapas:

- Problema 1: Listas
- Problema 2: Pilhas
- Problema 3: Filas
- Problema 4: Abordagem geral

### Sobre o desenvolvimento
Os arquivos com os algoritmos desenvolvidos podem ser localizados neste repositório. O código foi escrito nos padrões da linguagem C, utilizando o sistema operacional Windows 10 versão 20H2 (compilador gcc). A compilação do programa pode ser feita utilizando o comando "make" e, em seguida, executada com "make run". Após compilado, a navegação é feita por meio de submenus contidos em um menu principal.

---
### Problema 1 - Listas 

Listas são estruturas de dados muito utilizadas. Elas servem como armazenamento de dados e é formatada utilizando a maneira pela qual é nomeada. Sendo assim, a imagem a baixo pode ser usada para melhor compreendimento de suas funções.

Para essa tarefa, utilizei uma contrução de listas em seu formato dinâmico e, por esse motivo, composta por nós. Também chamada de lista encadeada, essa estrutura é iniciada pelo armazenamento de um valor ("value") sendo indicada por um ponteiro auxiliar ("next") que aponta sempre para a próxima região a se armazenar um valor. Dessa forma, os valores são conectados por espécies de nós do início ao fim e por isso podem ser percorridos. Além disso, essa estrutura permite o acréscimo ou remoção de novos valores.

![](https://www.mundojs.com.br/wp-content/uploads/2020/06/DataStructuresLinkedList.png)

As declarações das funções de lista foram feitas por meio de uma estrutura principal que abrange o problema em toda sua extensão. Essa estrutura pode ser observada em "P1&Lista.h". Além disso, a implementação relacionada a essas funções pode ser localizada em Lista.c.

#### A) Concatenação entre Listas
###### Arquivo: P1.c - Função: void p1A();
Através da criação de duas listas que recebem valores aleatórios pares e ímpares separadamente e de uma terceira, utilizada como auxiliar, a concatenação entre duas listas pôde ser feita através de um loop em que eram adicionados sempre dois itens (1 item de L1 e 1 de L2, nesta ordem) a esta auxiliar, até que se chegasse ao último valor da segunda lista.

###### Obs: Aux 1 aponta para o primeiro item da lista 1 e aux 2 aponta para o primeiro da lista 2. Devido a adição de L2 por último, o loop o tem como condição de parada. A cada passagem pela função os ponteiros são redirecionados para a próxima posição com o valor armazenado de L1 e L2. São feitas duas inserções a lista 3 (auxiliar) de forma que fosse matida a ordem de L1 e L2 em L3; 

###### *ver trecho de código abaixo.

    aux1 = L1.first->next;
    aux2 = L2.first->next;
    while (aux2 != NULL) {
        d = aux1->data; //valor de L1 a ser acrescentado em L3
        insertL(&L3, d);
        d = aux2->data; //valor de L2 a ser acrescentado em L3
        insertL(&L3, d);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }

#### B) Jogo
###### Arquivo: P1.c - Função: void p1B();
Partindo do preenchimento de L1 (lista 1) e L2 (lista 2) com 3 valores para cada e seguindo pelo sorteio de um número inicial para comparação dos valores, utilizei um método para somar os valores em posições iguais de L1 e L2, armazenando em uma terceira lista, que vem a ser um auxiliar, o total somado. Com os 3 valores em L3, basta que seja feito um comparativo e assim, exiba o vencedor da partida.

###### Obs: Aux 1 aponta para o primeiro item da lista 1 e aux 2 aponta para o primeiro da lista 2. Devido a adição de L2 por último, o loop o tem como condição de parada. A cada passagem pela função os ponteiros são redirecionados para a próxima posição com o valor armazenado de L1 e L2. São feitas duas inserções a lista 3 (auxiliar) de forma que fosse matida a ordem de L1 e L2 em L3; 

###### *ver trecho de código abaixo.



#### C) Mercado
###### Arquivo: P1.c - Função: void p1C();
Tópico não solucionado.

---
### Problema 2 - Pilhas

Outra forma típica para o armazenamento de dados é a forma de pilha. Essa é uma estrutura que apresenta valores de forma sequencial, feita pelo empilhamento de itens sempre acima de outro previamente posicionado. Um exemplo de sua aplicação são as navegações entre páginas na internet, que são feitas por meio dessa organização.

Para essa tarefa, utilizei uma contrução de pilhas em seu formato dinâmico semelhante ao apresentado para a estrutura anterior. Essa, também chamada de pilha encadeada, é uma estrutura que se inicia pelo empilhamento de um valor que será a base e, até a próxima adição, o topo de nossa pilha. Ao se adicionar novos valores ao topo, o ponteiro guia de nossa função sempre contemplará o valor anterior, ou seja, o topo sempre apontará para valores em direção a base da pilha. Além disso, essa estrutura permite o empilhamento ou desempilhamento de novos valores utilizando as funções push e pop respectivamente. A imagem abaixo nos da uma explicação visual sucinta sobre seu funcionamento.

![](https://www.cos.ufrj.br/~rfarias/cos121/operacoesPilha1.png)

As declarações das funções de pilha foram feitas por meio de uma estrutura principal que abrange o problema em toda sua extensão. Essa estrutura pode ser observada em "P2&Pilha.h". Além disso, a implementação relacionada a essas funções pode ser localizada em Pilha.c.

#### A) Parênteses
###### Arquivo: P2.c - Função: void p2A();
A investigação da parentização de frases utilizando pilha pode ser feita por meio empilhamento de todos os parênteses contidos na expressão e aA partir daí a verificação pode ser feita tendo base no parêntese de fechamento das declarações. Para que uma expressão esteja correta, é necessário que exista um balanceamento entre '(' e ')' que foi garantida por um controle (int control) que era acrescido ao encontrar parênteses fechados e descrescido em casos análogos. Esse controle, sempre deveria manter valores maiores que 0 para que a execução continuasse. Caso o controle assuma um valor inferior a 0, a parentização está errada e por isso a aplicação imediatamente se fecha dando uma mensagem de sobre sua incoerência. Além disso, caso não tivéssemos a ciscustância anterior, outro possível motivo para a parentização incorreta é que se ao final da execução o valor de controle for diferente de 0 indica que a expressão está desbalanceada em relação a abertura e fechamento desses sinais. Para resultados de controle distintos a esses dois apresentados, a expressão deve aparecer como correta.

###### *Observar os trechos de código abaixo.

###### Insere '(' e ')' à pilha.

    for (int i = 0; i < strlen(teste); i++) {
        if(teste[i] == ')') {
            d.txt = ")";
            push(&p, d);
        } else if(teste[i] == '(') {
            d.txt = "(";
            push(&p, d);
        }
    }

###### Verifica o balanceamento entre '(' e ')' na pilha.

    //para essa verificacao, a referencia para controle e' o parentese ')' pois ele e' responsavel por incrementar a variavel controle; alem disso sempre que a parentizacao estiver correta, esse caractere aparecera' no topo e o '(' estara' na base. Porem as regras nao se limitam a isso...
    
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

#### B) Tranferência entre Pilhas

###### Arquivo: P2.c - Função: void p2B();

Sobre a tranferência de valores de uma pilha para outra, mantendo a mesma posição de ocupação e sem utilizar uma pilha auxiliar, a ideia implementada funciona da seguinte forma:

* Inicialização e preenchimento de P1 (pilha 1);
* Inicialização de P2 (pilha 2);

Após fazer o empilhamento em P1 e tendo o tamanho dessa pilha, é necessário que se faça um loop que se inicia do topo e segue em direção a base. Esse loop verifica cada posição de nossa pilha e portanto se faz capaz de obter os valores de P1 e assim transferi-los para P2. 

###### Abaixo, pode ser observada a implementação dessa ideia.

    temp = P1.top;  
    while (cont > 0) { // cont => quantidade de valores em P1 (verificação começa de baixo para cima)
        if (i == cont) { // caso i atinja a posição verificada de P1, faz-se o empilhamneto desse valor em P2
            d = temp->data;
            push(&P2, d);
            temp = P1.top;
            cont--; // avança a verificação para um valor acima na pilha
            i = 0;
        }
        i++;
        if (i != cont) temp = temp->next;
    }

#### C) Co-Primos

###### Arquivo: P2.c - Função: int mdc(int aux, int d) e void p2C();

Em se tratando da função totiente de Euler, que se almeja encontrar o phi (Φ) de um número, esse problema pode ser resolvido utilizando o M.D.C do número para descobrir primos entre si. A quantidade de números primos entre si, ou apenas co-primos, indica para nós o valor Φ desse número. Essa verificação deve ser feita partindo do número desejado e comparado até que chegue ao menor número positivo da sequência, 1. Para os casos em que o MDC é igual a 1, o número é co-primo e portanto é um valor a ser acrescentado a phi. Dessa maneira, utilizei uma pilha para armazenar os valores a serem verificados e com "subpilhas" armazenei os co-primos encontrado pela função mdc. Durante o empilhamento dos primos entre si estipulei um contador que me forcesse o valor phi ao final de sua execução e era zerado na próxima vez que um valor da pilha principal fosse gerado.

###### *Observar os trechos de código abaixo.

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


---
### Problema 3 - Filas

Mais um modelo para organização de dados, a fila também é uma estrutura de que apresenta valores de forma sequencial, feita por meio do enfileiramento de itens desejados. Desse modo, sua forma é aplicada como vemos em filas de bancos por exemplo, onde, em nosso caso, temos valores chegando e ocupando a primeira posição e outros ocupando as posições que se sucedem de forma em que o primeiro a "entrar" é sempre o primeiro a "sair". Vale ressaltar que essa é uma forma amplamente utilizada para auxiliar na medição de distância entre pontos, que se baseia em modelos de grafos.

Para essa tarefa, utilizei uma contrução de filas em seu formato dinâmico semelhante ao apresentado para a implementação da lista. Nas funções definidas, o último item adicionado sempre aponta para onde poderá ser adicionado um novo valor e assim sucessivamente. O método para desenfileiramento acontece retirando sempre o valor inicial e movendo o ponteiro de primeiro para o valor que imediatamente sucede o item removido. A imagem abaixo nos guia para um entendimento de forma visual sobre o funcionamento da fila.

![](https://www.cos.ufrj.br/~rfarias/cos121/fila1.png)

As declarações das funções de fila foram feitas por meio de uma estrutura principal que abrange o problema em toda sua extensão. Essa estrutura pode ser observada em "P3&Fila.h". Além disso, a implementação relacionada a essas funções pode ser localizada em Fila.c.


#### A) Binômio de Newton
###### Não foi feita.

#### B) Classe de maior valor
###### Arquivo: P3.c - Função: void p3A();
Para encontrar a classe de maior valor dentro de uma determinada posição na fila, podem ser implementadas algumas estruturas para a struct Item que servirá para armazenar as posições do vetor, o maior valor desses dados e a posição em que se encontra. Desse modo, o preenchimento da fila foi feito e juntamente com o preenchimento das 5 posições do vetor dentro da fila. Uma vez feito o enfileiramento e preenchimento dos valores ao vetor, basta que os valores do vetor sejam comparados entre si para encontrar o maior elemento e também é possível que se armazene a posição com uma variável auxiliar, bem como outra variável para guardar a soma dos 5 itens. Por fim, a fila pode ser percorrida para encontrar a maior soma obtida de cada classe e assim obter a classe de maior valor dentro da fila.

---
### Problema 4

###### Não foi feita.