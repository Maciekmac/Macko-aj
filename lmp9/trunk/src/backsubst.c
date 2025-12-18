#include "backsubst.h"
#include <stdio.h>

/**
 * Zwraca 0 - sukces
 * Zwraca 1 - błąd dzielenia przez 0
 * Zwraca 2 - błąd rozmiarów
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int n = mat->r;
    int i, j;

    
    if (mat->r != mat->c || x->r != n || b->r != n) {
        return 2;
    }

    
    for (i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        
        for (j = i + 1; j < n; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }

        if (mat->data[i][i] == 0) {
            return 1; 
        }

        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }

    return 0;
}

