#include "Matriz.h"
#include <time.h>

/* Passo-a-Passo
1) Receber como entrada do usuario as N cidades
2) Calcular qual eh o menor caminho a ser percorrido, partindo de uma determinada cidade, passando por
todas as demais e retornando a ela mesma
3) Printar (por terminal ou arquivo) a menor distancia, qual foi o caminho, a matriz e o tempo de execucao.
*/

int main(){
    int n, opcao;
    Matriz matriz;
    clock_t tempo_inicio, tempo_final;
    double tempo_total;

    // Criando o Menu de interacao com o usuario
    printf("Bem-vindo ao Trabalho Prático II\n");
    printf("Digite, de acordo com o número correspondente, a opcao desejada\n");
    printf("1) Modo interativo\n");
    printf("2) Modo arquivo\n");
    
    scanf("%d", &opcao); 

    if (opcao == 1){
        scanf("%d", &n);
        if (n==0){
            printf("Digite um numero maior que 0 :/ ");
            return 0;
        }
    }
    //A contagem de tempo começa aqui:
    tempo_inicio = clock();   
    if(opcao == 1){
        Inicializa_matriz(&matriz,n);
        Preencher_matriz_interativa(&matriz);

    } else if(opcao == 2) {
        FILE *arquivo;
        arquivo = fopen("ExemploTP2.txt", "r"); //Abre o arquivo para leitura  
        fscanf(arquivo, "%d", &n); //Quantidade de cidades
        Inicializa_matriz(&matriz, n);
        Preencher_matriz_arquivo(&matriz, arquivo);
    } else{
        printf("Opcao Invalida! :/ \n");
        return 0;
    }

    // criar o for que vai preencher o vetor de 0 ate n-1
    Preencher_vetor(&matriz);
    Gerar_Permutacoes(&matriz, 0, (matriz.n)-2);
    tempo_final = clock();
    
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC;
    Printar_Dados(&matriz, tempo_total);
    Printar_Dados_Arquivo(&matriz, tempo_total);
    return 0;
}
