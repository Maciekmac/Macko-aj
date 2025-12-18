#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    if(mat->r != mat->c || mat->r != b->r){
            return 1;}
    int n = mat->r;
    int i, j, k;
    for (k = 0; k < n-1; k++){
            int main_row = k;
            for(i = k+1; i<n; i++){
                    if(fabs(mat->data[i][k]) > fabs(mat->data[main_row][k])){
                            main_row = i;}}
            if(fabs(mat->data[main_row][k]) < 1e-12){
                    return 1;}
            double *temp = mat->data[k];
            mat->data[k] = mat->data[main_row];
            mat->data[main_row] = temp;
            double *temp_b = b->data[k];
            b->data[k] = b->data[main_row];
            b->data[main_row] = temp_b;
            for(i = k+1; i<n; i++){
                    double factor = mat->data[i][k] / mat->data[k][k];
                    for(int j = k; j<mat->c; j++){
                            mat->data[i][j] -= factor*mat->data[k][j];}
                    b->data[i][0] -=factor*b->data[k][0];}}
    if(fabs(mat->data[n-1][n-1])<1e-12){
            return 1;}
                return 0;
}
//Wersja Maciek: koniec
