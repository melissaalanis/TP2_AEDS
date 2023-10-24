#include <stdio.h>

typedef struct {
    int n; // tamanho da Matriz
    int **distancia_cidades;
    int *vetor_permutacoes;
    int cidade_partida;
} Matriz;

int inicializa_matriz(Matriz* matriz, int n);
void preencher_matriz_interativa(Matriz* matriz);
void preencher_matriz_arquivo(Matriz* matriz, FILE* arquivo);
void Troca(int vetor[], int i, int j);
int Calcula_Distancia(Matriz* matriz, int vetor[]);
void Gerar_Permutacoes(Matriz* matriz, int inf, int sup);
void preencher_vetor(Matriz* matriz);

