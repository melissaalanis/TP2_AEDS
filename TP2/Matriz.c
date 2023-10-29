#include "Matriz.h"
#include <stdlib.h>
#include <time.h>

//Cores que serao utilizadas para printar a matriz no terminal
#define cor_vermelha  "\x1b[31m" 
#define cor_branca    "\x1b[0m"

// Matriculas dos alunos do grupo, serão utilizadas para calcular a cidade de partida
#define melissa 5384 
#define leticia 5781
#define caio 5784

int Soma_matriculas(){ 
   // Fazendo o mod de cada numero de matricula por 1000, 100, 10 e 01, temos os respectivos 
   // numeros relacionados a cada casa decimal das matriculas
   int mm = (((melissa %  1000)/10)+((melissa%100)/10)+((melissa%10)/10)+((melissa%1)/10));
   int mc = (((caio %  1000)/10)+((caio%100)/10)+((caio%10)/10)+((caio%1)/10));
   int ml = (((leticia % 1000)/10)+((leticia%100)/10)+((leticia%10)/10)+((leticia%1)/10));
   
   return mm + mc + ml; // Soma todas as matrículas para utilizarmos no calculo da cidade de partida.
}

int Inicializa_matriz(Matriz* matriz, int n){
    matriz -> n = n;
    // alocando dinamicamente o vetor 
    // O vetor tem tamanho n-1, pois a nossa cidade_partida nao entrara na permutacao
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
    matriz -> cidade_partida = Soma_matriculas()%n; //Pegamos a soma das matriculas e fazemos mod n para descobrir a cidade de partida
    matriz -> soma = 0; //Inicializando a soma com 0
    
    // alocando dinamicamente o vetor 
    // O vetor tem tamanho n-1, pois a nossa cidade_partida nao entrara na permutacao
    matriz->vetor_resposta = (int *)malloc((n-1) * sizeof(int));
    return 0;
}


void Preencher_matriz_interativa(Matriz* matriz) {
    srand(time(NULL));
    for (int i = 0; i < matriz -> n; i++) {
        for (int j = 0; j < matriz -> n; j++) {//
            if (i == j) {
                matriz -> distancia_cidades[i][j] = 0;//Se i == j significa que é a distância da cidade até ela mesma, logo é 0
            } else {
                matriz -> distancia_cidades[i][j] =  (rand() % 60)+10; //A distancia entre as cidades vai de 10 a 60
            }
        }
    }
}

void Preencher_matriz_arquivo(Matriz* matriz, FILE* arquivo) {
    for (int i = 0; i < (matriz -> n); i++) {
        for (int j = 0; j < (matriz -> n); j++) {
            if (i == j) { //Se i == j significa que é a distância da cidade até ela mesma, logo é 0
                matriz -> distancia_cidades[i][j] = 0;
            } else {
                fscanf(arquivo, "%d", &(matriz->distancia_cidades[i][j])); //Pegando os valores do arquivo e preenchendo a matriz
            }
        }
    }
}

void Preencher_vetor(Matriz* matriz){
    int aux = 0;
    for(int i=0; i< (matriz->n);i++){ //preenche o vetor com os valores(cidades) que serao utilizadas na permutacao
        if(i != matriz->cidade_partida){ //se i for igual a cidade de partida, não entra no vetor
            matriz -> vetor_permutacoes[aux] = i; 
            aux += 1;
        }
    }
}

void Printar_Dados(Matriz* matriz, double tempo_final){
    printf("MATRIZ:\n");    
    // Printamos todas as distancias entre as cidades 
    for(int i = 0; i < matriz->n; i++){
        for(int j = 0; j < matriz->n; j++){
            if(i == j){
                //deixamos a diagonal principal vermelha, representando a distacia dela até ela mesma 
                printf(cor_vermelha "%d " cor_branca, matriz->distancia_cidades[i][j]); 
            } else {
                printf("%d ", matriz->distancia_cidades[i][j]); 
            }
        }
        printf("\n");
    }
    printf("Menor caminho percorrido: %d\n", matriz->soma); //Printando a menor soma
    
    printf("Caminho percorrido: ");
    //A cidade de partida é sempre o primeiro e o ultimo elemento do caminho, as demais cidades estão no vetor resposta
    printf("%d ", matriz -> cidade_partida); 
    for(int j = 0; j < (matriz->n)-1; j++){
        printf("%d ", matriz->vetor_resposta[j]);
    }
    printf("%d\n", matriz -> cidade_partida);

    //Printando o tempo de execucao
    printf("Tempo de execução: %lf \n", tempo_final);
}

int Printar_Dados_Arquivo(Matriz* matriz, double tempo_final){
    FILE *arquivo;
    //Cria o arquivo "resultado.txt", se ele não existir, ou sobreescreve o seu conteudo, se ele existir
    arquivo = fopen("resultado.txt", "w"); 
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1;
    }

    //Escrevendo os daados no arquivo:
    fprintf(arquivo, "Matriz:\n");
    for(int i = 0; i < matriz->n; i++){
        for(int j = 0; j < matriz->n; j++){
            fprintf(arquivo, "%d ", matriz->distancia_cidades[i][j]); // Printamos todas as distancias entre as cidades 
        }
        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "Menor caminho percorrido: %d\n", matriz->soma); //Printando a menor soma
    
    fprintf(arquivo, "Caminho percorrido: ");
    //A cidade de partida é sempre o primeiro e o ultimo elemento do caminho, as demais cidades estão no vetor resposta
    fprintf(arquivo,"%d ", matriz -> cidade_partida); 
    for(int j = 0; j < (matriz->n)-1; j++){
        fprintf(arquivo, "%d ", matriz->vetor_resposta[j]);
    }
    fprintf(arquivo, "%d\n", matriz -> cidade_partida);

    fprintf(arquivo, "Tempo de execução: %lf \n", tempo_final);
    return 0;
}