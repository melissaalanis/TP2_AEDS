//#include "Matriz.h"
#include <stdio.h>

// Função para trocar dois elementos de um vetor
void troca(int vetor[], int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
int calcula_distancia(int distancia_cidades[n][n], int vetor[n], int cidade_partida){
	int soma = 0; // variavel que será retornada
	int aux = cidade_partida; // é criada a nossa variavel auxiliar, que recebe o valor da cidade_partida
	
	for(int i=0; i<n; i++){ // for que percorre o vetor
		if(i != n-1){ // enquanto o i nao for meu "ultimo" elemento do vetor
			soma += distancia_cidades[aux][vetor[i]]; // distancia de uma cidade a outra
			aux = i ; // o aux recebe o indice do meu elemento, para que ele seja usado na proxima iteracao 
		}
		else{
			soma += distancia_cidades[aux][vetor[i]];
			soma += distancia_cidades[vetor[i]][cidade_partida]; // distancia da ultima cidade da permutacao com a cidade de partida.
		}
}


	return soma;

}

// Função para gerar permutações de um vetor
void permuta(int vetor[], int inf, int sup) {
    if (inf == sup) {
        // Se o índice inferior for igual ao índice superior, uma permutação completa foi gerada
        for (int i = 0; i <= sup; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
        
    } else {
        for (int i = inf; i <= sup; i++) {
            // Troca os elementos do vetor
            troca(vetor, inf, i);

            // Chama a função recursivamente para continuar gerando permutações
            permuta(vetor, inf + 1, sup);

            // Realiza o "backtracking" desfazendo a troca
            troca(vetor, inf, i);
        }
    }
}

int main(int argc, char *argv[]) {
    int v[] = {1, 2, 3, 4};
    int tam_v = sizeof(v) / sizeof(int);

    // Chama a função para gerar permutações do vetor v
    permuta(v, 0, tam_v - 1);

    return 0;
}
