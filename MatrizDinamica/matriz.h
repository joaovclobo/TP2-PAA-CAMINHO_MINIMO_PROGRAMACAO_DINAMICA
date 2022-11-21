#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

/**
 * @brief HeraderFile 
 * 
 * @authors @João Vitor @Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @implements struct Matriz: Matriz dinâmica
 * 
 * @since 11/2022 xx:xx
 * 
 * @version 1.0
 * 
 */

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
void encontraCaminhoMinFrocaBruta(int i, int j, Matriz caminhos, int caminhoMin, int somaCaminho, int* numCaminhosMins);
void encontraCaminhoMinBacktracking(int i, int j, Matriz caminhos, int caminhoMin, int somaCaminho, int* numCaminhosMins);

void geraCaminhos(int linhas, int colunas, int** matrizVazia, int maxCaminho);