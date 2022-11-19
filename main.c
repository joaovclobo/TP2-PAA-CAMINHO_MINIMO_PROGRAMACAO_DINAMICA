#include "Interfaces/interfaces.h"
#include <time.h>

/**
 * Executável principal do sistema. 
 * 
 * @authors João Vitor Chagas Lobo; Thiago Cândido; Aroldo Augusto Barbosa Simões
 * 
 * @class main.c
 * 
 * @headerfile Interface.h
 * @headerfile time.h
 * 
 * @implements: 
 *      main - Aplicação base;
 * 
 * @since 11/2022 xx:xx
 * 
 * @version 1.0
 * 
 */

int main(){

    int linhas, colunas, opcao, caminhoMin;
    short encerra = false;

    Matriz matPesos, matCaminhos;

    FILE *fptr;

    cabecalhoMain();

    do {
        int numCaminhosMin = 0;

        fptr = abreArquivo();

        /** Incicialização das matrizes e vetores*/
        leituraLinhasColunas(fptr, &linhas, &colunas);

        inicializaMatriz(&matCaminhos, linhas, colunas);
        printf("\nRepresentação dos caminhos:\n");
        printMatriz(matCaminhos);
        // numeraMatrizZeros(&matCaminhos);

        inicializaMatriz(&matPesos, linhas, colunas);
        copiaMatrizFILE(fptr, linhas, colunas, (matPesos.matDinamica));
        
        printf("\nRepresentação dos pesos dos caminhos:\n");
        printMatriz(matPesos);
        putchar('\n');

        int caminhoMin = calculaCaminhoMin(matPesos, matCaminhos);
        encontraCaminhoMinMemorization(0, 0, matCaminhos, matPesos, &numCaminhosMin);
        printf("Soma Mínima: %d\n", caminhoMin);
        printf("Quantidade de Caminhos: %d\n", numCaminhosMin);

        free(matCaminhos.matDinamica);
        free(matPesos.matDinamica);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Não.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}
