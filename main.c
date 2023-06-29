#include "cabecera.h"
#include "matrix-operations.c"
#include "string.h"

// Set DEBUG to 1 to print debug messages
#define DEBUG 1

tuple hillCypher (tuple actual) {
  #if DEBUG
    printf("Tuple in hillCypher: %c%c%c\n", actual.first, actual.second, actual.third);
  #endif
  productoMatrices((int *) &actual, matrizKey, (int *) &actual, 1, 3, 3, 3);
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
  productoMatrices((int *) &actual, calcularInversa(matrizKey, matrizKey, DIM), (int *) &actual, 1, 3, 3, 3);
  return actual;
}

void desencrypt (char * input) {
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
  int option;
  static char input[200];
  static char * output;

  puts("Hola bro!");
  puts("Si queres ingresar un mensaje para encriptar marca 0.");
  puts("Si queres ingresar un mensaje para desencriptar marca 1.");
  puts("Ingresar -1 para finalizar programa.");
  printf("Elijo la opcion: ");
  scanf("%d", &option);
  fflush(stdin);

  #if DEBUG
    puts("DEBUG MODE ACTIVATED");
    printf("Matriz llave: \n");
    printMatrix(matrizKey, DIM, DIM);
  #endif

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
      desencrypt(input);
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