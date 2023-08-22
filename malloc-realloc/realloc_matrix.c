#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, size = 3;
    float **mat;

    // Alocação inicial
    mat = malloc(size * sizeof(float *));
    for(i = 0; i < size; i++)
        mat[i] = malloc(size * sizeof(float));

    // Valores iniciais
    for(i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            mat[i][j] = 1;

    // Impressão da matriz inicial
    for(i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%f ", mat[i][j]);
        printf("\n");
    }
    printf("\n");

    // Realocando
	// Adicionando uma nova linha e uma nova coluna
    mat = realloc(mat, (size+1)*sizeof(float*));
    for(i = 0; i < size; i++)
        mat[i] = realloc(mat[i], (size+1)*sizeof(float));
    mat[size] = malloc((size+1) * sizeof(float));

    for(i = 0; i <= size; i++) {
        mat[i][size] = 0;
        mat[size][i] = 0;
    }

    //Impressão da matriz alterada
    for(i = 0; i <= size; i++) {
        for (j = 0; j <= size; j++)
            printf("%f ", mat[i][j]);
        printf("\n");
    }

    //Liberação de memória
    for (i = 0; i <= size; i++)
        free(mat[i]);
    free(mat);
}