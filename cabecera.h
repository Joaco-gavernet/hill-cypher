#ifndef CABECERA_DEFINED
#define CABECERA_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>

  // Se definen constantes de dimension para operar con matrices en memoria
  #ifndef DIM
    #define DIM 3
    #define MOD 255
  #endif

  // Inicializamos la matriz de key/llave para encriptar y desencriptar mensajes (alcance global)
  int matrizKey[DIM][DIM] = {{7, 0, 0}, {0, 1, 1}, {0, 8, 9}};
  int matrizKeyInvserse[DIM][DIM] = {{73, 0, 0}, {0, 9, 254}, {0, 247, 1}};

  // Se definen los tipos de datos utilizados
  typedef struct {
    char first;
    char second;
    char third;
  } tuple;

  // Se definen macros utilizadas en las funciones de matrices
  #define forn(i, n) for (int i = 0; i < n; i++)

  // Se incluyen los prototipos del archivo "cabecera.h"
  void printMatrix (int matrix[][DIM], int m, int n);
  void printMatrixFloat (float matrix[][DIM], int m, int n);
  // int * productoMatrices (int a[][DIM], int b[][DIM], int am, int an, int bm, int bn);
  void delay(int);

#endif