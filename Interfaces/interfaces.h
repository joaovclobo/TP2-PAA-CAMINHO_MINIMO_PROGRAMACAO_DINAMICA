#include <stdio.h>
#include "../LeituraDados/leituraArquivos.h"

#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

/** Funções de interface*/
void cabecalho();
int menuOpcoes();
void menuModoAnalise(short* modoAnalise);
void exibicaoOpcoes(int opcao, Matriz matrizCaminhos, Matriz matrizFazenda, int linhas, int colunas); //Apenas a opcao de animação é mostrada em outro momento

/** Funções para mostar as matrizes ou vetores*/
void printVetor(int* vetor, int tamVetor);
