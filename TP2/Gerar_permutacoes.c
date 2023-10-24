#include "Matriz.h"

// Função para trocar dois elementos de um vetor
void Troca(int vetor[], int i, int j){
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int Calcula_Distancia(Matriz* matriz, int vetor[]){
	int soma = 0; // variavel que será retornada
	
    soma += matriz->distancia_cidades[matriz -> cidade_partida][vetor[0]]; // distancia de uma cidade a outra
    printf("soma aux %d\n", soma);
	for(int i=0; i< (matriz -> n)-2; i++){ // "for" que percorre o vetor
		soma += matriz->distancia_cidades[vetor[i]][vetor[i+1]]; // distancia de uma cidade a outra
		//aux = i ; // o aux recebe o indice do meu elemento, para que ele seja usado na proxima iteracao 
        printf("soma aux %d\n", soma);
    }
    soma += matriz->distancia_cidades[vetor[(matriz->n)-2]][matriz -> cidade_partida]; // distancia de uma cidade a outra
	return soma;
}

// Função para gerar permutações de um vetor
void Gerar_Permutacoes(Matriz *matriz, int inf, int sup) {
    if (inf == sup) {
        // Se o índice inferior for igual ao índice superior, uma permutação completa foi gerada
        for (int i = 0; i <= sup; i++) {
            printf("%d ", matriz->vetor_permutacoes[i]);
        }
        printf("\n");
        int soma = Calcula_Distancia(matriz, matriz->vetor_permutacoes);
        printf(" soma = %d\n", soma);

    } else {
        for (int i = inf; i <= sup; i++) {
            // Troca os elementos do vetor
            Troca(matriz->vetor_permutacoes, inf, i);

            // Chama a função recursivamente para continuar gerando permutações
            Gerar_Permutacoes(matriz, inf + 1, sup);

            // Realiza o "backtracking" desfazendo a troca
            Troca(matriz->vetor_permutacoes, inf, i);
        }
    }
}

