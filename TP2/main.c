#include <stdio.h> 
#include <stdlib.h>
#define matriculas 65

/* Passo-a-Passo
1) Receber como entrada do usuario as N cidades
2) Calcular qual eh o menor caminho a ser percorrido, partindo de uma determinada cidade, passando por
todas as demais e retornando a ela mesma
3) Printar (por terminal ou arquivo) a menor distancia, qual foi o caminho, 
*/

int main(){
    int n, opcao;
    int cidade_partida;
    
    // Criando o Menu de interacao com o usuario
    printf("Bem-vindo ao Trabalho Prático II\n");
    printf("Digite, de acordo com o número correspondente, a opcao desejada\n");
    printf("1) Modo interativo\n");
    printf("2) Modo arquivo\n");
    
    scanf("%d", &opcao); 
    if (opcao == 1){
        scanf("%d", &n);
        cidade_partida = matriculas%n;
        int distancia_cidades[n][n]; //matriz que armazena a distância entre as cidades

        for(int i = 0; i < n; i++){ //responsavel por preencher a matriz
            for(int j = 0; j < n; j++){
                if(i == j){
                    distancia_cidades[i][j] = 0; //A distância da cidade até ela mesma é 0
                }
                else{
                    distancia_cidades[i][j] = rand() % 100; //Perguntar para o monitor qual intervalo dos números (distância entre as cidades)
                }
            }
        }
        
        //for de teste, retirar depois
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", distancia_cidades[i][j]);
            }
            printf("\n");
        }

    } else if(opcao ==2) {
        int aux;
        FILE *arquivo;

        arquivo = fopen("ExemploTP2.txt", "r"); //Abre o arquivo para leitura  
        
        fscanf(arquivo, "%d", &n); //Quantidade de cidades
        cidade_partida = matriculas%n;
        int distancia_cidades[n][n]; ///Matriz que armazena a distância entre as cidades
          
        for(int i = 0; i < n; i++){ //Responsável por preencher a matriz
            for(int j = 0; j < n; j++){
                if(i == j){
                    distancia_cidades[i][j] = 0; //A distância da cidade até ela mesma é 0
                }
                else{
                    fscanf(arquivo, "%d", &distancia_cidades[i][j]); //Pegando os valores do arquivo
                }
            }
        }

        //for de teste, retirar depois
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", distancia_cidades[i][j]);
            }
            printf("\n");
        }
        
    } else{
        printf("Opcao Invalida! :/ \n");
    }

    // criar o for que vai preencher o vetor de 0 ate n-1

    int vetor[n-1]; // O vetor tem tamanho n-1, pois a nossa cidade_partida nao entrara na permutacao

    for(int i=0; i<n ;i++){ // preenche o vetor com os valores(cidades) que serao utilizadas na permutacao
        if(i != cidade_partida){
            vetor[i] = i;
        }
    }

    return 0;
}
