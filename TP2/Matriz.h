#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n; //Tamanho da Matriz
    int **distancia_cidades; //Matriz de adjacencia
    int *vetor_permutacoes; //Vetor que sera permutado
    int cidade_partida; //Cidade de partida e chegada
    int soma; //Menor distancia 
    int *vetor_resposta; //Vetor do caminho percorrido para obter a menor distancia
} Matriz;

// Funcoes do Matriz.c
int Soma_matriculas();
int Inicializa_matriz(Matriz* matriz, int n);
void Preencher_matriz_interativa(Matriz* matriz);
void Preencher_matriz_arquivo(Matriz* matriz, FILE* arquivo);
void Printar_Dados(Matriz* matriz, double tempo_total);
int Printar_Dados_Arquivo(Matriz* matriz, double tempo_final);

// Funcoes do Gerar_permutacoes.c
void Troca(Matriz *matriz, int i, int j);
int Calcula_Distancia(Matriz* matriz);
void Gerar_Permutacoes(Matriz* matriz, int inf, int sup);
void Preencher_vetor(Matriz* matriz);
