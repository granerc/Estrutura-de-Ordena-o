//selection sort é recomenado seu uso quando: A memória extra é escassa. O custo para trocar elementos de posição 
//no arranjo é elevado e por fim quando o vetor é pequeno 

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
                if (vetor[j] == valor) {// Se o valor já estiver no vetor, sai do loop
                    break;
                }
            }
        } while (j != i); // Repete o processo enquanto o valor gerado já existir no vetor
        vetor[i] = valor; // Atribui o valor único ao vetor
    }
}

// Função Selection Sort
void selection_sort(int vetor[], int tamanho) {
    int i, j, posiaoMenorValor, aux;
    // Laço externo percorre o vetor
    for (i = 0; i < tamanho - 1; i++) {
        posiaoMenorValor = i; // Assume que o menor valor está na posição i

        //Analisa os elementos da frete
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[posiaoMenorValor]) { // Verifica se existe um valor menor na frente dos analisados
                posiaoMenorValor = j; // Atualiza o índice do menor valor
            }
        }
        // Troca o menor valor encontrado com o valor da posição i
        aux = vetor[i];
        vetor[i] = vetor[posiaoMenorValor];
        vetor[posiaoMenorValor] = aux;
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
    gerarValoresAleatorios(vetor, TAMANHO); // // Chama a função para gerar valores aleatórios e diferentes
    
    // Exibe o vetor original (não ordenado)
    printf("Vetor original: ");
    imprimirVetor(vetor, TAMANHO);
    
    // Ordena com Selection Sort
    selection_sort(vetor, TAMANHO); // Ordena com Selection Sort
    
     // Exibe o vetor ordenado
    printf("Vetor ordenado com Selection: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
