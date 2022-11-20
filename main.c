#include "Interfaces/interfaces.h"
#include <time.h>

/**
 * Executável principal do sistema. 
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
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
        int escolhaUsuario = 0;
        
        //Variáveis usadas no cálculo de tempo de execução:
        double time_spent = 0.0;
        clock_t begin;
        clock_t end;

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

        opcoesEncontraCaminho();
        scanf("%d", &escolhaUsuario);

        do
        {
            
            switch (escolhaUsuario){
                case 1:
                    begin = clock(); 
                    encontraCaminhoMinMemorization(0, 0, matCaminhos, matPesos, &numCaminhosMin);
                    break;
                
                case 2:
                    begin = clock(); 
                    encontraCaminhoMinFrocaBruta();
                    break;

                case 3:
                    begin = clock(); 
                    encontraCaminhoMinBacktracking();
                    break;

                default:
                    printf("Entre com uma opcao valida! \n");
                    break;
            }
        } while (escolhaUsuario <= 0 || escolhaUsuario > 3);
        
        end = clock();
 
        // calcula o tempo decorrido encontrando a diferença (end - begin) e
        // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
        printf("\nTEMPO GASTO PARA EXECUÇÃO: %f segundos\n", time_spent);

        int somaCaminhoMin = calculaCaminhoMin(matPesos, matCaminhos);

        printf("Soma Mínima: %d\n", somaCaminhoMin);
        printf("Quantidade de Caminhos: %d\n", numCaminhosMin);

        free(matCaminhos.matDinamica);
        free(matPesos.matDinamica);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Não.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}
