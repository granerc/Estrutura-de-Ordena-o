//MergeSort é  indicado para aplicações que tem restrição de tempo (executa sempre em um determinado tempo para n). 
//Passível de ser transformado em estável.

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

// Função para mesclar dois subarrays
void merge(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1; //Tamaho do primeiro vetor auxiliar
    int n2 = direita - meio;      //Tamaho do segundo vetor auxiliar

    // Arrays temporários
    int vetorE[n1], vetorD[n2];

     //Passa os elementos do vetor principal para o primeiro vetor auxiliar (Esquerda)
    for (i = 0; i < n1; i++)
        vetorE[i] = vetor[esquerda + i];

    //Passa os elementos do vetor principal para o segundo vetor auxiliar (Direita)
    for (j = 0; j < n2; j++)
        vetorD[j] = vetor[meio + 1 + j];

    // Mescla os arrays temporários de volta no vetor original (reseta)
    i = 0; j = 0; k = esquerda;

    while (i < n1 && j < n2) {
        if (vetorE[i] <= vetorD[j]) { //Caso o valor na esquerda seja menor
            vetor[k] = vetorE[i];  //Passa para o meu vetor principal o valor menor
            i++; //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
        } else {
            vetor[k] = vetorD[j];  //Passa para o meu vetor principal o valor menor
            j++; //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
        }
        k++;  //Aumenta o índice de posicionamento do vetor
    }

   //Se faltarem alguns elemntos do array ESQUERDO passa eles para o array principal
    while (i < n1) {
        vetor[k] = vetorE[i];
        i++;
        k++;
    }

    //Se faltarem alguns elemntos do array DIREITO passa eles para o array principal
    while (j < n2) {
        vetor[k] = vetorD[j];
        j++;
        k++;
    }
}

// Função Merge Sort
void merge_sort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {

         //Encontra o meio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e segunda metades
        merge_sort(vetor, esquerda, meio); //Da metade para trás
        merge_sort(vetor, meio + 1, direita);  //Da metade para frente

        // Mescla as duas metades
        merge(vetor, esquerda, meio, direita);
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
    
    // Ordena com Merge Sort
    merge_sort(vetor, 0, TAMANHO - 1); 
    
     // Exibe o vetor ordenado
    printf("Vetor ordenado Merge: ");
    imprimirVetor(vetor, TAMANHO);
    
    return 0;
}
