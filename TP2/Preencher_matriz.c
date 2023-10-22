#include "Matriz.h"
#include <stdlib.h>
//#define matriculas 65


void preencher_matriz_interativa() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distancia_cidades[i][j] = 0;
            } else {
                distancia_cidades[i][j] = rand() % 100;
            }
        }
    }
}

void preencher_matriz_arquivo(FILE* arquivo) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distancia_cidades[i][j] = 0;
            } else {
                fscanf(arquivo, "%d", &distancia_cidades[i][j]);
            }
        }
    }
}
