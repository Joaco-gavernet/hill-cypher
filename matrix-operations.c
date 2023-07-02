#include "cabecera.h"

void printMatrix (int matrix[][DIM], int m, int n) {
    int i,j;
    forn(i,m) {
        forn(j, n) printf("%3d ", matrix[i][j]);
        printf("\n");
    }
    printf("//////////////\n");
}

void printMatrixFloat (float matrix[][DIM], int m, int n) {
    int i,j;
    forn(i,m) {
        forn(j, n) printf("%.2f ", matrix[i][j]);
        printf("\n");
    }
    printf("//////////////\n");
}