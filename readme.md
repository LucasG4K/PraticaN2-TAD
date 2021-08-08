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
Através da criação de duas listas que recebem valores aleatórios pares e ímpares separadamente e de uma terceira, utilizada como auxiliar, a concatenação entre duas listas pôde ser feita através de um loop em que eram adicionados sempre dois itens (1 item de L1 e 1 de L2, nesta ordem) a esta auxiliar, até que se chegasse ao último valor da segunda lista.

###### Obs: Aux 1 aponta para o primeiro item da lista 1 e aux 2 aponta para o primeiro da lista 2. Devido a adição de L2 por último, o loop o tem como condição de parada. A cada passagem pela função os ponteiros são redirecionados para a próxima posição com o valor armazenado de L1 e L2. São feitas duas inserções a lista 3 (auxiliar) de forma que fosse matida a ordem de L1 e L2 em L3; 

###### *ver trecho de código abaixo.

    aux1 = L1.first->next;
    aux2 = L2.first->next;
    while (aux2 != NULL) {
        d = aux1->data;
        insertL(&L3, d);
        d = aux2->data;
        insertL(&L3, d);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }

#### B) Jogo


###### Obs: Aux 1 aponta para o primeiro item da lista 1 e aux 2 aponta para o primeiro da lista 2. Devido a adição de L2 por último, o loop o tem como condição de parada. A cada passagem pela função os ponteiros são redirecionados para a próxima posição com o valor armazenado de L1 e L2. São feitas duas inserções a lista 3 (auxiliar) de forma que fosse matida a ordem de L1 e L2 em L3; 

###### *ver trecho de código abaixo.



#### C) Mercado
Não obtive sucesso na realização desse tópico;

---
### Problema 2 - Pilhas

Outra forma típica para o armazenamento de dados é a forma de pilha. Essa é uma estrutura que apresenta valores de forma sequencial, feita pelo empilhamento de itens sempre acima de outro previamente posicionado. Um exemplo de sua aplicação são as navegações entre páginas na internet, que são feitas por meio dessa organização.

Para essa tarefa, utilizei uma contrução de pilhas em seu formato dinâmico semelhante ao apresentado para a estrutura anterior. Essa, também chamada de pilha encadeada, é uma estrutura que se inicia pelo empilhamento de um valor que será a base e, até a próxima adição, o topo de nossa pilha. Ao se adicionar novos valores ao topo, o ponteiro guia de nossa função sempre contemplará o valor anterior, ou seja, o topo sempre apontará para valores em direção a base da pilha. Além disso, essa estrutura permite o empilhamento ou desempilhamento de novos valores utilizando as funções push e pop respectivamente. A imagem abaixo nos da uma explicação visual sucinta sobre seu funcionamento.

![](https://www.cos.ufrj.br/~rfarias/cos121/operacoesPilha1.png)

As declarações das funções de pilha foram feitas por meio de uma estrutura principal que abrange o problema em toda sua extensão. Essa estrutura pode ser observada em "P2&Pilha.h". Além disso, a implementação relacionada a essas funções pode ser localizada em Pilha.c.

#### A) Parênteses

#### B) Tranferência entre Pilhas

#### C) Co-Primos

---
### Problema 3 - Filas

Mais um modelo para organização de dados, a fila também é uma estrutura de que apresenta valores de forma sequencial, feita por meio do enfileiramento de itens desejados. Desse modo, sua forma é aplicada como vemos em filas de bancos por exemplo, onde, em nosso caso, temos valores chegando e ocupando a primeira posição e outros ocupando as posições que se sucedem de forma em que o primeiro a "entrar" é sempre o primeiro a "sair". Vale ressaltar que essa é uma forma amplamente utilizada para auxiliar na medição de distância entre pontos, que se baseia em modelos de grafos.

Para essa tarefa, utilizei uma contrução de filas em seu formato dinâmico semelhante ao apresentado para a implementação da lista. Nas funções definidas, o último item adicionado sempre aponta para onde poderá ser adicionado um novo valor e assim sucessivamente. O método para desenfileiramento acontece retirando sempre o valor inicial e movendo o ponteiro de primeiro para o valor que imediatamente sucede o item removido. A imagem abaixo nos guia para um entendimento de forma visual sobre o funcionamento da fila.

![](https://www.cos.ufrj.br/~rfarias/cos121/fila1.png)

As declarações das funções de fila foram feitas por meio de uma estrutura principal que abrange o problema em toda sua extensão. Essa estrutura pode ser observada em "P3&Fila.h". Além disso, a implementação relacionada a essas funções pode ser localizada em Fila.c.


#### A) Binômio de Newton

#### B) Classe de maior valor

---
### Problema 4

