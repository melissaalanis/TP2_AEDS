//#include <stdio.h> 
#include <stdlib.h>
#include "Matriz.h"
//#include "Gerar_permutacoes.c"
//#define matriculas 65

/* Passo-a-Passo
1) Receber como entrada do usuario as N cidades
2) Calcular qual eh o menor caminho a ser percorrido, partindo de uma determinada cidade, passando por
todas as demais e retornando a ela mesma
3) Printar (por terminal ou arquivo) a menor distancia, qual foi o caminho, 
*/

int main(){
    int n, opcao;
    Matriz matriz;

    // Criando o Menu de interacao com o usuario
    printf("Bem-vindo ao Trabalho Prático II\n");
    printf("Digite, de acordo com o número correspondente, a opcao desejada\n");
    printf("1) Modo interativo\n");
    printf("2) Modo arquivo\n");
    
    scanf("%d", &opcao); 

    if (opcao == 1){
        scanf("%d", &n);
        //A contagem de tempo começa aqui:

        
        Inicializa_matriz(&matriz,n);
        Preencher_matriz_interativa(&matriz);

        //for de teste, retirar depois

        /**/
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", matriz.distancia_cidades[i][j]);
            }
            printf("\n");
        }

    } else if(opcao ==2) {
        FILE *arquivo;
        arquivo = fopen("ExemploTP2.txt", "r"); //Abre o arquivo para leitura  
        fscanf(arquivo, "%d", &n); //Quantidade de cidades
        Inicializa_matriz(&matriz, n);
        Preencher_matriz_arquivo(&matriz, arquivo);


        //for de teste, retirar depois
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", matriz.distancia_cidades[i][j]);
            }
            printf("\n");
        }
        
    } else{
        printf("Opcao Invalida! :/ \n");
    }

    // criar o for que vai preencher o vetor de 0 ate n-1
    Preencher_vetor(&matriz);

    Gerar_Permutacoes(&matriz, 0, (matriz.n)-2);

    printf("soma: %d\n", matriz.soma);
    for(int j = 0; j < n-1; j++){
        printf("%d ", matriz.vetor_resposta[j]);
    }
    return 0;
}
