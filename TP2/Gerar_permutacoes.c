#include "Matriz.h"

// Função para trocar dois elementos de um vetor
void Troca(Matriz *matriz, int i, int j){
    int aux = matriz->vetor_permutacoes[i];
    matriz->vetor_permutacoes[i] = matriz->vetor_permutacoes[j];
    matriz->vetor_permutacoes[j] = aux;
}

int Calcula_Distancia(Matriz* matriz){
	int soma = 0; // variavel que será retornada
	
    // Pega a distancia da cidade de partida até a primeira cidade do vetor
    soma += matriz->distancia_cidades[matriz -> cidade_partida][matriz->vetor_permutacoes[0]]; 

	for(int i=0; i< (matriz -> n)-2; i++){ // "for" que percorre o vetor
	// Pega a distancia das cidades do vetor
        soma += matriz->distancia_cidades[matriz->vetor_permutacoes[i]][matriz->vetor_permutacoes[i+1]]; 
    }
    
    // Pega a distancia da ultima cidade do vetor ate a cidade de partida
    soma += matriz->distancia_cidades[matriz->vetor_permutacoes[(matriz->n)-2]][matriz -> cidade_partida];
	return soma;
}

// Função para gerar permutações de um vetor
void Gerar_Permutacoes(Matriz *matriz, int inf, int sup) {
    if (inf == sup) { // Se o índice inferior for igual ao índice superior, uma permutação completa foi gerada
        int soma_aux = Calcula_Distancia(matriz); 
        // Verifca se a nova distancia que esta sendo calculada é menor que a nossa menor distancia 
        if (soma_aux < (matriz->soma) || matriz->soma == 0){ 
            matriz -> soma = soma_aux;  //soma recebe a menor soma das distancias
            
            //Atualiza o vetor que guarda o caminho da menor soma
            for(int i = 0; i<matriz->n-1; i++){
                matriz->vetor_resposta[i] = matriz->vetor_permutacoes[i];
            }
        }

    } else {
        for (int i = inf; i <= sup; i++) {
            // Troca os elementos do vetor
            Troca(matriz, inf, i);

            // Chama a função recursivamente para continuar gerando permutações
            Gerar_Permutacoes(matriz, inf + 1, sup);

            // Realiza o "backtracking" desfazendo a troca
            Troca(matriz, inf, i);
        }
    }
}
