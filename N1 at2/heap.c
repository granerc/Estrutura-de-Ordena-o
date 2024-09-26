//HeapSort é recomendado para conjuntos de dados ordenados aleatoriamente, pois tem um bom desempenho em tempo de execução.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6 // Define o tamanho do vetor como 6

// Função para gerar valores aleatórios e diferentes
void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100;  // Gera um número aleatório entre 0 e 99
            // Verifica se o valor gerado já está presente no vetor
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // // Se o valor já estiver no vetor, sai do loop
                    break;
                }
            }
        } while (j != i);  // // Repete o processo enquanto o valor gerado já existir no vetor
        vetor[i] = valor;  // // Atribui o valor único ao vetor
    }
}

// Função que "constrói" um heap maximizador a partir de um vetor
void heapify(int vetor[], int n, int i) {
    int maior = i; // Inicializa a raiz como o maior valor
    int esquerda = 2 * i + 1; // Índice do filho à esquerda: 2 * i + 1
    int direita = 2 * i + 2;  // Índice do filho à direita: 2 * i + 2

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;  // Atualiza a posição do maior valor

    // Se o filho da direita for maior que o maior valor até agora
    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;  // Atualiza a posição do maior valor

    // Se o maior valor não é a raiz
    if (maior != i) {
        // Troca o valor da raiz com o maior
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        // Chama recursivamente o heapify na subárvore afetada
        heapify(vetor, n, maior);
    }
}

// Função Heap Sort
void heap_sort(int vetor[], int n) {
    // Passo 1: Construir o heap maximizador (organiza o vetor como uma árvore binária)
    // Começa a partir do último nó não-folha (n / 2 - 1) e vai até a raiz (índice 0)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i); // Organiza a subárvore com raiz em i

    // Passo 2: Extrair elementos do heap, um por um
    // O laço remove a raiz (o maior elemento) e move para o final do vetor
    for (int i = n - 1; i >= 0; i--) {
        // Troca a raiz (maior elemento) com o último elemento
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Chama heapify no heap reduzido para restaurar a propriedade de heap
        heapify(vetor, i, 0); // A subárvore enraizada no índice 0 é reorganizada
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
     // Percorre todo o vetor e imprime cada elemento
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Exibe cada elemento do vetor seguido de um espaço
    }
    printf("\n");// Pula para a próxima linha
}

int main() {
    int vetor[TAMANHO]; // Declara o vetor com o tamanho definido
    
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual
    gerarValoresAleatorios(vetor, TAMANHO); // Chama a função para gerar valores aleatórios e diferentes
    
    // Exibe o vetor original (não ordenado)
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);
    
    // Ordena o vetor com Heap Sort
    heap_sort(vetor, TAMANHO);
    
    // Exibe o vetor ordenado
    printf("Vetor ordenado Heap: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
