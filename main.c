#include "cabecera.h"
#include "matrix-operations.c"
#include "string.h"

// Set DEBUG to 1 to print debug messages
#define DEBUG 0

int * productoMatrices (int a[][DIM], int b[][DIM], int am, int an, int bm, int bn) {
  int * result = calloc((am * bn), sizeof(int));

  int i = 0, j = 0;
  while (i < am) {
    int k = 0;
    while (k < an) {
      result[(i*am) + j] += a[i][k] * b[k][j];
      k++;
    }
    if (j < an) j++;
    else {
      j = 0;
      i++;
    }
  }

  return result;
}

tuple hillCypher (tuple actual) {
  #if DEBUG
    printf("Tuple in hillCypher: %c%c%c\n", actual.first, actual.second, actual.third);
  #endif
  int input[1][3] = {{actual.first, actual.second, actual.third}};
  int * result = calloc(1*3, sizeof(int));
  result = productoMatrices(input, matrizKey, 1, 3, 3, 3);

  actual.first = result[0] % MOD;
  actual.second = result[1] % MOD;
  actual.third = result[2] % MOD;
  return actual;
}

void encrypt (char * input) {
  int length = strlen(input) - 1; // -1 para no contar el fin de cadena \0
  #if DEBUG
    printf("String length: %d\n", length);
  #endif

  for (int i = 0; i < length; i+=3) {
    tuple actual = {input[i], input[i+1], input[i+2]};
    tuple result = hillCypher(actual);
    input[i] = result.first;
    input[i+1] = ((i+1) < length) ? result.second : '\0';
    input[i+2] = ((i+2) < length) ? result.third : '\0';
  }
}

tuple hillCypherInvert (tuple actual) {
  #if DEBUG
    printf("Tuple in hillCypherInvert: %c%c%c\n", actual.first, actual.second, actual.third);
  #endif
    int input[1][3] = {{actual.first, actual.second, actual.third}};
  int * result = calloc(1*3, sizeof(int));
  result = productoMatrices(input, matrizKeyInvserse, 1, 3, 3, 3);

  actual.first = result[0] % MOD;
  actual.second = result[1] % MOD;
  actual.third = result[2] % MOD;
  return actual;
}

void decrypt (char * input) {
  int length = strlen(input) - 1; // -1 para no contar el fin de cadena \0
  printf("String length: %d\n", length);
  for (int i = 0; i < length; i+=3) {
    tuple actual = {input[i], input[i+1], input[i+2]};
    tuple result = hillCypherInvert(actual);
    input[i] = result.first;
    input[i+1] = ((i+1) < length) ? result.second : '\0';
    input[i+2] = ((i+2) < length) ? result.third : '\0';
  }
}

int main() {
  #if DEBUG
    puts("DEBUG MODE ACTIVATED");
    printf("Matriz key: \n");
    printMatrix(matrizKey, DIM, DIM);
  #endif

  int option;
  char input[200];
  char * output;

  puts("Si queres ingresar un mensaje para encriptar marca 0.");
  puts("Si queres ingresar un mensaje para desencriptar marca 1.");
  puts("Ingresar -1 para finalizar programa.");
  printf("Elijo la opcion: ");
  scanf("%d", &option);
  fflush(stdin);

  while (option != -1) {
    if (option == 0) {
      puts("Encendiendo encriptador...");
      printf("Encriptador encendido, ingresar mensaje para encriptar: ");
      fgets(input, 200, stdin);
      printf("Cadena ingresada: %s", input);
      puts("Encriptando cadena...");
      encrypt(input);
      printf("Cadena encriptada: %s\n", input);

    } else {
      puts("Encendiendo desencriptador...");
      printf("Desencriptador encendido, ingresar mensaje para desencriptar: ");
      fgets(input, 200, stdin);
      printf("Cadena ingresada: %s", input);
      puts("Desencriptando cadena...");
      decrypt(input);
      printf("Cadena desencriptada: %s\n", input);

    }

    puts("Si queres ingresar un mensaje para encriptar marca 0.");
    puts("Si queres ingresar un mensaje para desencriptar marca 1.");
    puts("Ingresar -1 para finalizar programa.");
    printf("Elijo la opcion: ");
    scanf("%d", &option);
    fflush(stdin);
  }

  return 0;
}