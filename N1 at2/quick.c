//QuickSort é extremamente eficiente para ordenar arquivos de dados. 
//Necessita de apenas uma pequena pilha como memória auxiliar. 

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
        } while (j != i);// Repete o processo enquanto o valor gerado já existir no vetor
        vetor[i] = valor;// Atribui o valor único ao vetor
    }
}

// Função para particionar o vetor
int particao(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto]; // Define o pivô como o último elemento do vetor
    int i = (baixo - 1); // i é o índice que marca a posição do menor elemento encontrado até o momento

    // Loop que percorre o vetor da posição 'baixo' até 'alto - 1'
    for (int j = baixo; j < alto; j++) {
        // Verifica se o elemento atual é menor ou igual ao pivô
        // Isso garante que todos os elementos menores ou iguais ao pivô
        // fiquem à esquerda dele, após a partição
        if (vetor[j] <= pivo) {
            i++; // Incrementa o índice para o menor elemento
            
            // Troca o elemento no índice i com o elemento na posição j
            // Essa troca move o menor elemento para a esquerda do pivô
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    // Após o loop, o índice i marca o final da porção de elementos menores que o pivô
    // Agora, o pivô precisa ser colocado em sua posição correta no vetor ordenado
    // O pivô é trocado com o elemento imediatamente após o último menor elemento
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[alto]; // Coloca o pivô na posição correta
    vetor[alto] = temp; // O antigo pivô é trocado

    // Retorna o índice do pivô, que agora está na posição correta
    // Todos os elementos à esquerda são menores ou iguais ao pivô,
    // e todos os elementos à direita são maiores
    return (i + 1);
}

// Função Quick Sort para ordenar o vetor
void quick_sort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        // Chama a função de partição que organiza o vetor ao redor de um pivô e retorna a posição final do pivô
        int pi = particao(vetor, baixo, alto);

        // Recursivamente ordena os elementos antes do pivô. (Aqui, são os elementos entre 'baixo' e 'pi - 1')
        quick_sort(vetor, baixo, pi - 1);

        // Recursivamente ordena os elementos após o pivô. (Aqui, são os elementos entre 'pi + 1' e 'alto')
        quick_sort(vetor, pi + 1, alto);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
     // Percorre todo o vetor e imprime cada elemento
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);// Exibe cada elemento do vetor seguido de um espaço
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
    
    // Ordena com Quick Sort
    quick_sort(vetor, 0, TAMANHO - 1); 
    
     // Exibe o vetor ordenado
    printf("Vetor ordenado Quick: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
