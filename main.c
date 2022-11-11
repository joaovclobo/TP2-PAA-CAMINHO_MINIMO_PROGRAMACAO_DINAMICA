#include "Interfaces/interfaces.h"
#include <time.h>

int main(){

    int linhas, colunas, opcao;

    short encerra = false;

    Matriz matrizPesos, matrizCaminhos;

    FILE *fptr;

    cabecalho();

    do {

        fptr = abreArquivo();

        /** Incicialização das matrizes e vetores*/
        leituraLinhasColunas(fptr, &linhas, &colunas);

        inicializaMatriz(&matrizCaminhos, linhas, colunas);
        printf("\nRepresentação dos caminhos:\n");
        printMatriz(matrizCaminhos);
        // numeraMatrizZeros(&matrizCaminhos);

        inicializaMatriz(&matrizPesos, linhas, colunas);
        copiaMatrizFILE(fptr, linhas, colunas, (matrizPesos.matrizDinamica));
        
        printf("\nRepresentação dos pesos dos caminhos:\n");
        printMatriz(matrizPesos);
        putchar('\n');

        // opcao = menuOpcoes();

        // exibicaoOpcoes(opcao, matrizCaminhos, matrizFazenda, linhas, colunas);

        free(matrizCaminhos.matrizDinamica);
        free(matrizPesos.matrizDinamica);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Não.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}
