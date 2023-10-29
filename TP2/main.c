#include "Matriz.h"
#include <time.h>

/* Passo-a-Passo
1) Receber como entrada do usuario a quantidade N de cidades
2) Calcular qual eh o menor caminho a ser percorrido, partindo de uma determinada cidade, passando por
todas as demais e retornando a ela mesma
3) Printar (por terminal ou arquivo) a menor distancia, qual foi o caminho, a matriz e o tempo de execucao.
*/

int main(){
    int n, opcao, op_saida;
    Matriz matriz;

    //Será utilizado para calcular o tempo de execucao
    clock_t tempo_inicio, tempo_final; 
    double tempo_total;

    // Criando o Menu de interacao com o usuario
    printf("Bem-vindo ao Trabalho Prático II\n");
    printf("Digite, de acordo com o número correspondente, a opcao desejada:\n");
    printf("1) Modo interativo\n");
    printf("2) Modo arquivo\n");
    
    scanf("%d", &opcao); 
    
    if (opcao == 1){
        scanf("%d", &n); //Pegar a quantidade de cidades
        if (n==0){ //Se n for igual a 0, nao tem como calcular, pois terá zero cidades
            printf("Digite um numero maior que 0 :/ ");
            return 0;
        }
    } 
    
    //A contagem de tempo começa aqui:
    tempo_inicio = clock(); //Marca o tempo inicial
    
    if (opcao == 1){
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

    Preencher_vetor(&matriz); //Preenchendo o vetor que será permutado, o vetor vai de 0 até n-1, retirando a cidade de partida
    Gerar_Permutacoes(&matriz, 0, matriz.n - 2);
    
    tempo_final = clock(); //Marca o tempo final 
    tempo_total = (double)(tempo_final-tempo_inicio) / CLOCKS_PER_SEC; //Calcula o tempo total em segundos

    // Criando o Menu para o usuario escolher como vai ser a saida  
    printf("Escolha, com base no número correspondente, como deseja imprimir sua matriz! \n");
    printf("1) Via terminal.\n");
    printf("2) Via arquivo.\n");

    scanf("%d", &op_saida);
    system("clear");
    
    if (op_saida == 1){
        Printar_Dados(&matriz, tempo_total);
    }
    else if(op_saida == 2){
        Printar_Dados_Arquivo(&matriz, tempo_total);
    }
    
    return 0;
}
