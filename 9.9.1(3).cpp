#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} MAT;

// Vytvoríme funkciu na inicializáciu štvorcovej matice, ktorá ju naplní nulami:

MAT* mat_init(int rows, int cols) {
    MAT *mat = (MAT *) malloc(sizeof(MAT));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
    return mat;
}
//Nezabudneme vytvoriť funkciu na uvoľnenie pamäte alokovanej pre maticu:

void mat_free(MAT *mat) {
    for(int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

//Vytvoríme hlavnú funkciu, ktorá bude maticu napĺňať náhodnou permutáciou:

char mat_create_random_permutation(MAT *mat) {
    if (mat->rows != mat->cols) {
        return 0; // Vráti neúspech, ak matica nie je štvorcová
    }
    
    int n = mat->rows;
    int *perm = (int *)malloc(n * sizeof(int));
    
    // Inicializácia permutácie
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    // Algoritmus Fisher-Yates na náhodné permutovanie
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
    }
    
    // Vytvorenie permutačnej matice na základe permutácie
    for (int i = 0; i < n; i++) {
        mat->data[i][perm[i]] = 1;
    }
    
    free(perm);
    return 1; // Vráti úspech
}









