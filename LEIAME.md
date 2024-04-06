## Integrantes:
Bruno Crestani GRR:20221240

Mateus Ruzene GRR:20221223

# EP-01 - Sistemas Lineares

## Explicação sobre o algoritimo

Este programa executa algoritmos de eliminação de Gauss e Gauss-Seidel, tanto para sistemas lineares convencionais quanto para sistemas tridiagonais. Ele lê um sistema linear da entrada padrão, aloca memória para matrizes e vetores, realiza os cálculos necessários e imprime os resultados.

- As funções gaussElimination e gaussSeidel são utilizadas para resolver sistemas lineares convencionais.
- As funções gaussElimination3d e gaussSeidel3d são utilizadas para resolver sistemas tridiagonais.
- O código também utiliza a biblioteca LIKWID para realizar medições de desempenho.

A alocação de memória das matrizes e dos vetores de constantes opera em torno da alocação de 2 matrizes e 2 vetores, sendo um par de matriz e vetor responsável pelo sistema linear original, e o outro par é modificado durante os processos que ocorrem na execução.
  Ao fim de cada operação isolada, o par alterado recebe a cópia do par original para prosseguir com as operações posteriores, além disso, o vetor resultante é zerado.
  
Ele segue a seguinte sequência de passos:
1) Leitura do tamanho do sistema linear.
2) Alocação de memória para as matrizes e vetores.
3) Leitura do sistema linear e preparação dos dados.
4) Execução dos algoritmos de eliminação de Gauss e Gauss-Seidel.
5) Impressão dos resultados, incluindo tempo de execução e resíduo.
6) Após a execução, o programa libera toda a memória alocada.

## Funções de Eliminação de Gauss

Este projeto contém funções em C para realizar a eliminação de Gauss, tanto para sistemas lineares padrão quanto para sistemas tridiagonais.

### Função `lineSwap`

Esta função é usada para evitar que o elemento pivô seja zero, para que uma divisão por zero não ocorra durante a eliminação de Gauss.

#### Parâmetros

- `A`: Matriz de tamanho `n` que representa o sistema linear.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `n`: Ordem da matriz `A`.
- `i`: Índice da linha atual que está sendo analisada.

### Função `gaussElimination`

Esta função implementa o método de eliminação de Gauss para resolver sistemas lineares.

#### Parâmetros

- `A`: Matriz de tamanho `n` que representa o sistema linear.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `x`: Vetor de tamanho `n` que conterá a solução do sistema.
- `n`: Ordem da matriz `A`.

### Função `gaussElimination3d`

Esta função implementa o método de eliminação de Gauss para resolver sistemas lineares tridiagonais.

#### Parâmetros

- `d`: Vetor de tamanho `n` que contém os elementos diagonais da matriz tridiagonal.
- `a`: Vetor de tamanho `n-1` que contém os elementos abaixo da diagonal principal da matriz tridiagonal.
- `c`: Vetor de tamanho `n-1` que contém os elementos acima da diagonal principal da matriz tridiagonal.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `x`: Vetor de tamanho `n` que conterá a solução do sistema.
- `n`: Ordem da matriz tridiagonal.

---

## Funções de Gauss-Seidel

No arquivo foi definido que o número máximo de iterações é 50:
```c
#define MAX_ITER 50
```

### Função `calculatesError`

Esta função calcula o erro entre duas iterações consecutivas do método de Gauss-Seidel.

#### Parâmetros

- `x`: Vetor de tamanho `n` que contém a solução atual do sistema linear.
- `x0`: Vetor de tamanho `n` que contém a solução da iteração anterior do sistema linear.
- `n`: Ordem do sistema linear.
- `max`: Valor máximo do erro entre os elementos de `x` e `x0`.

#### Retorno

- Retorna o valor máximo do erro entre os elementos de `x` e `x0`.

Este projeto contém funções em C para resolver sistemas lineares utilizando o método de Gauss-Seidel, tanto para sistemas lineares padrão quanto para sistemas tridiagonais.

### Função `gaussSeidel`

Esta função resolve um sistema linear utilizando o método de Gauss-Seidel.

#### Parâmetros

- `A`: Matriz de tamanho `n` que representa o sistema linear.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `x`: Vetor de tamanho `n` que contém uma estimativa inicial da solução.
- `n`: Ordem da matriz `A`.
- `tol`: Tolerância para o critério de parada.
- `iter`: Ponteiro para um inteiro que contará o número de iterações realizadas.

### Função `gaussSeidel3d`

Esta função resolve um sistema linear tridiagonal utilizando o método de Gauss-Seidel.

#### Parâmetros

- `d`: Vetor de tamanho `n` que contém os elementos diagonais da matriz tridiagonal.
- `a`: Vetor de tamanho `n-1` que contém os elementos abaixo da diagonal principal da matriz tridiagonal.
- `c`: Vetor de tamanho `n-1` que contém os elementos acima da diagonal principal da matriz tridiagonal.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `x`: Vetor de tamanho `n` que contém uma estimativa inicial da solução.
- `n`: Ordem da matriz tridiagonal.
- `tol`: Tolerância para o critério de parada.
- `iter`: Ponteiro para um inteiro que contará o número de iterações realizadas.

---

## Funções para Manipulação de Matrizes em C

Este programa contém funções em C para a alocação de memória, leitura, impressão, cópia, cálculo de resíduos e liberação de matrizes.

### Função `readLinearSystem`

Esta função lê um sistema linear da entrada padrão.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa o sistema linear.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `n`: Ordem da matriz `A`.

### Função `allocateMatrix`

Esta função aloca memória para uma matriz.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa a matriz a ser alocada.
- `n`: Ordem da matriz `A`.

### Função `freeMatrix`

Esta função libera a memória alocada para uma matriz.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa a matriz a ser liberada.
- `n`: Ordem da matriz `A`.

### Função `printMatrix`

Esta função imprime uma matriz.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa a matriz a ser impressa.
- `n`: Ordem da matriz `A`.

### Função `printVector`

Esta função imprime um vetor.

#### Parâmetros

- `b`: Vetor de tamanho `n` que representa o vetor a ser impresso.
- `n`: Tamanho do vetor `b`.

### Função `copiesMatrix`

Esta função copia uma matriz para outra matriz.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa a matriz a ser copiada.
- `B`: Matriz de tamanho `n x n` que representa a matriz de destino.
- `n`: Ordem das matrizes `A` e `B`.

### Função `copiesVector`

Esta função copia um vetor para outro vetor.

#### Parâmetros

- `a`: Vetor de tamanho `n` que representa o vetor a ser copiado.
- `b`: Vetor de tamanho `n` que representa o vetor de destino.
- `n`: Tamanho dos vetores `a` e `b`.

### Função `copiesLinearSystem`

Esta função copia um sistema linear para outro sistema linear.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa o sistema linear a ser copiado.
- `aux`: Matriz de tamanho `n x n` que representa o sistema linear de destino.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear a ser copiado.
- `bux`: Vetor de tamanho `n` que representa o lado direito do sistema linear de destino.
- `n`: Ordem da matriz `A` e do vetor `b`.

### Função `copies3dLinearSystem`

Esta função copia um sistema linear tridiagonal para outro sistema linear tridiagonal.

#### Parâmetros

- `aux`: Matriz de tamanho `n x n` que representa o sistema linear tridiagonal a ser copiado.
- `a`: Vetor de tamanho `n-1` que representa os elementos abaixo da diagonal principal do sistema linear tridiagonal de destino.
- `c`: Vetor de tamanho `n-1` que representa os elementos acima da diagonal principal do sistema linear tridiagonal de destino.
- `d`: Vetor de tamanho `n` que representa os elementos diagonais do sistema linear tridiagonal de destino.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear tridiagonal a ser copiado.
- `bux`: Vetor de tamanho `n` que representa o lado direito do sistema linear tridiagonal de destino.
- `n`: Ordem da matriz `aux` e tamanho dos vetores `a`, `c`, `d`, `b` e `bux`.

### Função `CalculatesResidual`

Esta função calcula o resíduo de um sistema linear em relação a uma solução estimada.

#### Parâmetros

- `A`: Matriz de tamanho `n x n` que representa o sistema linear.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear.
- `x`: Vetor de tamanho `n` que representa a solução estimada.
- `residue`: Vetor de tamanho `n` que armazena o resíduo calculado.
- `n`: Ordem da matriz `A` e tamanho dos vetores `b`, `x` e `residue`.

### Função `CalculatesResidual3d`

Esta função calcula o resíduo de um sistema linear tridiagonal em relação a uma solução estimada.

#### Parâmetros

- `d`: Vetor de tamanho `n` que representa os elementos diagonais do sistema linear tridiagonal.
- `a`: Vetor de tamanho `n-1` que representa os elementos abaixo da diagonal principal do sistema linear tridiagonal.
- `c`: Vetor de tamanho `n-1` que representa os elementos acima da diagonal principal do sistema linear tridiagonal.
- `b`: Vetor de tamanho `n` que representa o lado direito do sistema linear tridiagonal.
- `x`: Vetor de tamanho `n` que representa a solução estimada.
- `residual`: Vetor de tamanho `n` que armazena o resíduo calculado.
- `n`: Ordem da matriz tridiagonal e tamanho dos vetores `d`, `a`, `c`, `b`, `x` e `residual`.

### Função `initVector`

Esta função inicializa um vetor com zeros.

#### Parâmetros

- `v`: Vetor de tamanho `n` a ser inicializado com zeros.
- `n`: Tamanho do vetor `v`.

### Função `freeAll`

Esta função libera toda a memória alocada para matrizes e vetores.

#### Parâmetros

- `A`: Matriz de tamanho `

## Possíveis Erros

Os erros tratados neste projeto circulam em volta de alocação de memória e atribuição de de dados. Todos foram tratados de forma traduzida para português, caso ocorra algum erro, será impresso no terminal o erro ocorrido.
