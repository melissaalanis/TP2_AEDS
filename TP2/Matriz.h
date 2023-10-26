#include <stdio.h>

typedef struct {
    int n; // tamanho da Matriz
    int **distancia_cidades;
    int *vetor_permutacoes;
    int cidade_partida;
    int soma;
    int *vetor_resposta;
} Matriz;

int Inicializa_matriz(Matriz* matriz, int n);
void Preencher_matriz_interativa(Matriz* matriz);
void Preencher_matriz_arquivo(Matriz* matriz, FILE* arquivo);
void Troca(int vetor[], int i, int j);
int Calcula_Distancia(Matriz* matriz, int vetor[]);
void Gerar_Permutacoes(Matriz* matriz, int inf, int sup);
void Preencher_vetor(Matriz* matriz);
int Soma_matriculas();
