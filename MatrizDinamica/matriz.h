#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

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

int calculaCaminhoMin(Matriz matPesos, Matriz matCaminhos);

//TODO avaliar se da pra reaproveitar
void geraFazenda1(int linhas, int colunas, int** matrizVazia, int* vetorFib);
void geraFazenda2(int linhas, int colunas, int** matrizVazia, int* vetorFib);

