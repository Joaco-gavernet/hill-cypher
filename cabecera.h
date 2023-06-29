#ifndef CABECERA_DEFINED
#define CABECERA_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

  // Se definen constantes de dimension para operar con matrices en memoria
  #ifndef DIM
    #define DIM 3
    #define MOD 255
  #endif

  // Inicializamos la matriz de key/llave para encriptar y desencriptar mensajes (alcance global)
  int matrizKey[DIM][DIM] = {{4, 1, 20}, {2, 1, 0}, {0, 1, 5}};

  // Se definen los tipos de datos utilizados
  typedef struct {
    char first;
    char second;
    char third;
  } tuple;

  // Se definen macros utilizadas en las funciones de matrices
  #define forn(i, n) for (i = 0; i < n; i++)

  // Se incluyen los prototipos del archivo "cabecera.h"
  void printMatrix (int matrix[][DIM], int m, int n);
  void printMatrixFloat (float matrix[][DIM], int m, int n);
  int sumaDefinida(int am, int an, int bm, int bn);
  void sumarMatrices (const int A[][DIM], const int B[][DIM], int C[][DIM], int m, int n);
  int * productoDefinido (int am, int an, int bm, int bn);
  int * productoMatrices (int a[][DIM], int b[][DIM], int result[DIM][DIM], int am, int an, int bm, int bn);
  int * submatriz(int a[][DIM], int x, int y, int n);
  int determinante (int a[][DIM], int n);
  int * calcularInversa (int a[][DIM], float result[][DIM], int n);
  void permutacion (int arr[][DIM], int first, int second, int n);
  void eliminacionGaussiana (int arr[][DIM], int m, int n);
  int esCompatible (int a[][DIM], int m, int n);

#endif