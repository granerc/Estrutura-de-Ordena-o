//insertion sort é recomendado quando a sequência de itens está quase ordenada e é preciso adicionar poucos itens a 
//uma sequência já ordenada 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 6 // Define o tamanho do vetor como 6

// Função para gerar valores aleatórios e diferentes
void gerarValoresAleatorios(int vetor[], int tamanho) {
    int i, j, valor;
    for (i = 0; i < tamanho; i++) {
        do {
            valor = rand() % 100;// Gera um número aleatório entre 0 e 99
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

// Função Insertion Sort
void insertion_sort(int vetor[], int tamanho) {
    int i, atual, j;
    // Laço externo percorre o vetor
    for (i = 1; i < tamanho; i++) {
        atual = vetor[i]; // Valor atual a ser inserido (elemento atual em análise)
        j = i - 1;//elemento anterior ao analisado

        // Analisa os membros anteriores e desloca os elementos maiores para a direita
        while (j >= 0 && vetor[j] > atual) {

            //posiciona os elementos uma posição para frente
            vetor[j + 1] = vetor[j];

            //faz o j andar para trás
            j--;
        }
        vetor[j + 1] = atual; // Insere o valor atual (menor número) na posição correta
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
     // Percorre todo o vetor e imprime cada elemento
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // // Exibe cada elemento do vetor seguido de um espaço
    }
    printf("\n");// Pula para a próxima linha
} 

int main() {
    int vetor[TAMANHO]; // Declara o vetor com o tamanho definido
    
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo atual
    gerarValoresAleatorios (vetor, TAMANHO); // Chama a função para gerar valores aleatórios e diferentes
    
     // Exibe o vetor original (não ordenado)
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);

    // Ordena com Insertion Sort
    insertion_sort(vetor, TAMANHO); 
    
     // Exibe o vetor já ordenado
    printf("Vetor ordenado com Insertion: "); 
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
