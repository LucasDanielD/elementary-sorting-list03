# Estrutura de Dados II - Ordenação Avançada (Divisão e Conquista)

Este repositório contém as implementações em C++ referentes à Lista Prática 04 da unidade curricular de Estrutura de Dados II. O foco desta lista é a aplicação e análise de algoritmos fundamentados no paradigma de Divisão e Conquista, nomeadamente o **Merge Sort** e o **Quick Sort**, assim como técnicas de particionamento essenciais (**Lomuto** e **Hoare**).

## Estrutura do Projeto

Os códigos estão organizados de forma independente dentro da pasta `src/`:

```text
ed2-advanced-sorting-list04-cpp/
├── src/
│   ├── Exer01_MergeSortCountInversions.cpp
│   ├── Exer02_StabilityMergeSortVsQuickSort.cpp
│   ├── Exer03_QuickselectLomutoKthLargest.cpp
│   └── Exer04_HoarePartitionParitySort.cpp
├── CMakeLists.txt
└── README.md
```

---

## Mapeamento e Resolução dos Exercícios

### 1. Contagem de Inversões (`Exer01_MergeSortCountInversions.cpp`)
*   **Objetivo:** Determinar a quantidade exata de inversões presentes num vetor de N números inteiros distintos, além de devolver a sequência final ordenada. Uma inversão ocorre quando um par de índices $(i, j)$ satisfaz $i < j$ e $A[i] > A[j]$.
*   **Resolução:** Embora algoritmos elementares calculem as inversões em tempo quadrático $\mathcal{O}(N^2)$, a solução implementada tira partido da fase de intercalação (*merge*) do **Merge Sort**. Durante a combinação das sublistas, sempre que um elemento da metade direita é posicionado antes dos elementos da metade esquerda, adiciona-se ao contador o número de itens que ainda estão pendentes na esquerda. Esta abordagem garante uma complexidade ótima de tempo $\mathcal{O}(N \log N)$.

### 2. O Desafio da Estabilidade (`Exer02_StabilityMergeSortVsQuickSort.cpp`)
*   **Objetivo:** Demonstrar empiricamente a importância e o impacto da **estabilidade** nos algoritmos de ordenação, processando um conjunto de palavras pelo seu comprimento em ordem decrescente.
*   **Resolução:** Foram implementadas ambas as estratégias para evidenciar o contraste. 
    *   O **Merge Sort** demonstrou a sua estabilidade: na etapa de intercalação, a condição de desempate prioriza de forma determinística os elementos da partição esquerda, preservando a ordem original de palavras com o mesmo número de caracteres.
    *   O **Quick Sort**, pelo contrário, mostrou ser instável. As trocas pontuais de longa distância (*long-distance swaps*) intrínsecas ao seu procedimento de particionamento *in-place* transpõem chaves equivalentes, corrompendo a ordem relativa original da entrada.

### 3. Seleção Linear via Quickselect (`Exer03_QuickselectLomutoKthLargest.cpp`)
*   **Objetivo:** Localizar o K-ésimo maior elemento de uma sequência de N inteiros sem que seja necessário ordenar a totalidade do vetor, contabilizando de forma estrita o número de trocas efetivas (*swaps*) efetuadas na memória.
*   **Resolução:** A solução recorre ao **Quickselect** acoplado ao esquema de **particionamento de Lomuto** (varredura unidirecional). A cada iteração recursiva, a posição final do pivô é comparada com o índice alvo (K), descartando a metade irrelevante do vetor. Esta técnica reduz o esforço computacional, operando num tempo médio linear $\mathcal{O}(N)$. As trocas de memória foram geridas com a condição de $i \neq j$ para isolar e ignorar as auto-trocas, garantindo a validação exata do número de movimentações físicas.

### 4. Ordenação Par-Ímpar (`Exer04_HoarePartitionParitySort.cpp`)
*   **Objetivo:** Segregar e reorganizar um conjunto de números inteiros de forma a que todos os números pares antecedam os ímpares. A partição par deve ficar ordenada de forma crescente, e a partição ímpar de forma decrescente.
*   **Resolução:** Para atingir o objetivo com memória auxiliar nula $\mathcal{O}(1)$ e tempo linear $\mathcal{O}(N)$, utilizou-se o particionamento bidirecional convergente de **Hoare**. Dois ponteiros iniciam nas extremidades opostas do arranjo e movem-se em direção ao centro, trocando elementos que violam a regra de paridade. Finalizada essa separação, aplicou-se a ordenação padrão aos dois subgrupos resultantes.
