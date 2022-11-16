#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

typedef struct{
    int linhas;
    int colunas;
    int **matDinamica;
}Matriz;

enum trueFalse {
    true = 1, false = 0
};

void inicializaMatriz(Matriz *matriz, int linhas, int colunas);

void printMatriz(Matriz matriz);
void printMatrizDelay(Matriz matriz);

int calculaCaminhoMin(Matriz matPesos, Matriz matCaminhos);
void encontraCaminhoMinMemorization(int i, int j, Matriz matCaminhos, Matriz matPesos, int* numCaminhosMins);

void geraCaminhos(int linhas, int colunas, int** matrizVazia, int maxCaminho);
