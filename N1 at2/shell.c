//Shell  é indicado para ordenar coleções que estejam parcialmente ordenadas. 
//Pode ser usado quando o espaço de memória auxiliar é inexistente ou limitado e quando uma ordenação estável é necessária.

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

// Função Shell Sort
void shell_sort(int vetor[], int tamanho) {
    int gap, i, j, temp;

    // Inicializa o gap (intervalo de separação) com a metade do tamanho do vetor
    for (gap = tamanho / 2; gap > 0; gap /= 2) {
        // O laço percorre o vetor de gap em gap
        for (i = gap; i < tamanho; i++) {
            // Armazena o valor atual em uma variável temporária
            temp = vetor[i];
            
            // Desloca os elementos maiores para a direita, criando espaço para o valor armazenado
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap) {
                vetor[j] = vetor[j - gap]; // Move o elemento para frente
            }
            
            // Coloca o valor temporário na posição correta
            vetor[j] = temp;
        }
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
    
    // Ordena o vetor com o Shell Sort
    shell_sort(vetor, TAMANHO);
    
    // Exibe o vetor ordenado
    printf("Vetor ordenado Shell: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
