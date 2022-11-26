#include "Interfaces/interfaces.h"
#include <time.h>

/**
 * Executável principal do sistema. 
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @Nome do arquivo main.c
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

    int linhas, colunas, k, escolhaUsuario;
    short encerra = false;

    Matriz matViagem, matCaminhosMin, matImprime;

    FILE *fptr;

    cabecalhoMain();

    do {
        
        int numCaminhosMin = 0;
        int numCaminhosDivk = 0;
        
        //Variáveis usadas no cálculo de tempo de execução:
        double time_spent = 0.0;
        clock_t begin;
        clock_t end;

        fptr = abreArquivo();

        //Incicialização das matrizes
        leituraLinhasColunas(fptr, &linhas, &colunas);

        inicializaMatriz(&matCaminhosMin, linhas, colunas);
        inicializaMatriz(&matImprime, linhas, colunas);
        inicializaMatriz(&matViagem, linhas, colunas);

        copiaMatrizFILE(fptr, linhas, colunas, (matViagem.matDinamica));
        
        printf("\nRepresentação da matriz de caminhos da viagem:\n");
        printMatriz(matViagem);
        putchar('\n');

        
        printf("Calculando a matriz de caminhos mínimos...\nMatriz com a soma dos caminhos:\n");
        int somaMinima = calculaCaminhoMin(matViagem, matCaminhosMin);
        printMatriz(matCaminhosMin);

        escolhaUsuario = opcoesEncontraCaminho();

        do {
            
            switch (escolhaUsuario){
                case 1:
                    begin = clock(); 
                    encontraCaminhoMinMemorization(0, 0, matCaminhosMin, matViagem, &numCaminhosMin);
                break;
                
                case 2:
                    begin = clock();
                    encontraCaminhoMinBacktracking(0, 0, matViagem, somaMinima, 0, &numCaminhosMin);
                break;

                case 3:
                    begin = clock(); 
                    encontraCaminhoMinFrocaBruta(0, 0, matViagem, somaMinima, 0, &numCaminhosMin);
                break;

                case 4:
                    begin = clock(); 
                    encontraCaminhoMinImprime(0, 0, matCaminhosMin, matViagem, matImprime, &numCaminhosMin);
                break;

                case 5:
                    begin = clock(); 

                    printf("Digite o valor de \"k\": ");
                    scanf("%d", &k);

                    encontraCaminhoDivK(0, 0, matViagem, k, 0, &numCaminhosDivk);
                    
                    printf("Quantidade de caminhos divisiveis por k = %d: %d\n", k, numCaminhosDivk);
                break;

                default:
                    printf("Entre com uma opcao valida! \n");
                    escolhaUsuario = opcoesEncontraCaminho();

                break;

            }

        } while (escolhaUsuario <= 0 || escolhaUsuario > 5);
    
        end = clock();
    
        // calcula o tempo decorrido encontrando a diferença (end - begin) e dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    
        if (escolhaUsuario <= 4){

            printf("\nSoma mínima: %d\n", somaMinima);
            printf("Quantidade de caminhos minimos: %d\n", numCaminhosMin);

            if (escolhaUsuario < 4){
                printf("\nTempo gasto para a execução: %f segundos\n", time_spent);

            }
        }
        
        free(matCaminhosMin.matDinamica);
        free(matViagem.matDinamica);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Não.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}
