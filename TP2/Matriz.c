#include "Matriz.h"
#include <stdlib.h>
#define matriculas 65

int inicializa_matriz(Matriz* matriz, int n){
    matriz -> n = n;
    //// alocando dinamicamente o vetor 
    matriz -> vetor_permutacoes = (int *)malloc((n-1) * sizeof(int));
    // alocando dinamicamente as linhas da matriz de adjacência
    matriz -> distancia_cidades = (int **)malloc(matriz -> n * sizeof(int *));
    if (matriz -> distancia_cidades == NULL) {
        printf("Erro na alocacao das linhas\n");
        return 1;
    }

    // alocando dinamicamente as colunas da matriz de adjacencia
    for (int i = 0; i < matriz -> n; i++) {
        matriz -> distancia_cidades[i] = (int *)malloc(matriz -> n * sizeof(int));
        if (matriz -> distancia_cidades[i] == NULL) {
            printf("Erro na alocacao das colunas da linha %d.\n", i);
            return 1;
        }
    }
    matriz -> cidade_partida = matriculas%n;
    return 0;
}


void preencher_matriz_interativa(Matriz* matriz) {
    for (int i = 0; i < matriz -> n; i++) {
        for (int j = 0; j < matriz -> n; j++) {
            if (i == j) {
                matriz -> distancia_cidades[i][j] = 0;//Se i == j significa que a distância da cidade até ela mesma, logo é 0
            } else {
                matriz -> distancia_cidades[i][j] = (rand() % 60)+10; //A distancia entre as cidades vai de 10 a 60
            }
        }
    }
}

void preencher_matriz_arquivo(Matriz* matriz, FILE* arquivo) {
    for (int i = 0; i < matriz -> n; i++) {
        for (int j = 0; j < matriz -> n; j++) {
            if (i == j) { //Se i == j significa que a distância da cidade até ela mesma, logo é 0
                matriz -> distancia_cidades[i][j] = 0;
            } else {
                fscanf(arquivo, "%d", &(matriz->distancia_cidades[i][j])); //Pegando os valores do arquivo e preenchendo a matriz
            }
        }
    }
}

void preencher_vetor(Matriz* matriz){

    //int vetor[n-1]; // O vetor tem tamanho n-1, pois a nossa cidade_partida nao entrara na permutacao
    int aux = 0;
    for(int i=0; i< (matriz->n);i++){ // preenche o vetor com os valores(cidades) que serao utilizadas na permutacao
        if(i != matriz->cidade_partida){
            matriz -> vetor_permutacoes[aux] = i;
            aux += 1;
        }
    }
}


