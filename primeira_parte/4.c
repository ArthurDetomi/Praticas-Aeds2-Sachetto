#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 4

void preenche_matriz(int matriz[][TAM], int max_rand);
char **vet_maiores_que_30_matriz(int matriz[][4], int valor_max, int mat_n_linhas,
                                 int mat_n_colunas, int *vet_l, int *vet_colu);

int main(void) {
    int matriz[TAM][TAM];
    preenche_matriz(matriz, 80);

    int vet_l = 0, vet_colu = 0;
    char **vetor = vet_maiores_que_30_matriz(matriz, 30, TAM, TAM, &vet_l, &vet_colu);
    if (vetor == NULL) {
        printf("Error de alocacao\n");
        return 1;
    }

    for (int i = 0; i < vet_l; i++) {
        printf("%s\n", vetor[i]); 
    }

    for (int i = 0; i < vet_l; i++) { free(vetor[i]); }
    free(vetor);
    return 0;
}

void preenche_matriz(int matriz[][TAM], int max_rand) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            srand(time(NULL));
            matriz[i][j] = rand() % TAM + (25 + i * j);
            printf("%3d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char **vet_maiores_que_30_matriz(int matriz[][TAM], int valor_max, int mat_n_linhas,
                                 int mat_n_colunas, int *vet_l, int *vet_colu) {
    char **vet;
    *vet_l = 0;
    *vet_colu = 3;
    vet = (char **)malloc((*vet_l + 1) * sizeof(char *));
    if (vet == NULL) {
        printf("Falha de alocacao\n");
        exit(1);
    }

    for (int i = 0; i < mat_n_linhas; i++) {
        for (int j = 0; j < mat_n_colunas; j++) {
            if (matriz[i][j] > valor_max) {
                vet[*vet_l] = (char *)malloc(((*vet_colu) + 1) * sizeof(char));
                sprintf(vet[*vet_l], "%d*%d", i, j);
                (*vet_l) += 1;
                vet = (char**) realloc(vet, (*vet_l + 1) * sizeof(char *)); 
            }
        }
    }
    return vet;
}
