#include <stdio.h>
#include "../LeituraDados/leituraArquivos.h"

#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

/** Funções de interface*/
void cabecalhoMain();
void cabecalhoGerador();
int menuOpcoes();

//TODO avaliar se da pra reaproveitar
void exibicaoOpcoes(int opcao, Matriz matCaminhos, Matriz matrizFazenda, int linhas, int colunas); //Apenas a opcao de animação é mostrada em outro momento

/** Funções para mostar as matrizes ou vetores*/
void printVetor(int* vetor, int tamVetor);
