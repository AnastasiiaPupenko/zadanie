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

