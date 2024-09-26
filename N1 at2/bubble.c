//bubble sort: recomendado para listas pequenas, quase ordenadas ou quando a simplicidade do algoritmo é uma prioridade.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6 // Define o tamanho do vetor como 6

// Função para gerar valores aleatórios e diferentes
void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100; // Gera um número aleatório entre 0 e 99
            // Verifica se o valor gerado já está presente no vetor
            for (j = 0; j < i; j++) {
                if (vetor[j] == valor) { // Se o valor já estiver no vetor, sai do loop
                    break;
                }
            }
        } while (j != i); // Repete o processo enquanto o valor gerado já existir no vetor
        vetor[i] = valor; // Atribui o valor único ao vetor
    }
}

// Função Bubble Sort para ordenar o vetor
void bubble_sort(int vetor[], int tamanho) {
    int i, j, aux;
    // O laço externo controla o número de passadas
    for (i = 0; i < tamanho - 1; i++) {
        // O laço interno realiza a comparação e troca dos elementos
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) { // Se o valor da posição atual for maior que o próximo
                // Troca os dois valores
                aux = vetor[j]; 
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

// Função para imprimir os elementos do vetor
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    // Percorre todo o vetor e imprime cada elemento
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Exibe cada elemento do vetor seguido de um espaço
    }
    printf("\n"); // Pula para a próxima linha
}

int main() {
    int vetor[TAMANHO]; // Declara o vetor com o tamanho definido
    
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual
    gerarValoresAleatorios(vetor, TAMANHO); // Chama a função para gerar valores aleatórios e diferentes
    
    // Exibe o vetor original (não ordenado)
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);
    
    // Ordena o vetor utilizando o algoritmo Bubble Sort
    bubble_sort(vetor, TAMANHO);
    
    // Exibe o vetor já ordenado
    printf("Vetor ordenado com Bubble: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}

