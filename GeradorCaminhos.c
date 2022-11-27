#include "Interfaces/interfaces.h"

/**
 * Gerador de caminhos em arquivos de texto.
 * 
 * @authors @João Vitor Chagas Lobo, @Thiago Cândido, @Aroldo Augusto Barbosa Simões
 * 
 * @Nome do arquivo GeradorCaminhos.c
 * 
 * @headerfile Interface.h
 * 
 * @implements: 
 *      main - interação com usuário para criação do arquivo de caminho;
 * 
 * @since 11/2022 xx:xx 
 * 
 * @version 1.0
 * 
 */

int main(){
    
    int linhas, colunas, maxCaminho;

    short encerra = false;

    char nomeArquivo[MAX_BUFFER];

    Matriz matCaminhosArq;
    FILE *fptr;

    time_t tempo;
    srand((time(&tempo)));

   cabecalhoGerador();

    do {
        int escolhaGeradorCaminhos = 0;

        printf("Insira o nome completo do arquivo que será gerado (o arquivo será salvo na mesma pasta que está este executavel com a extensão \".txt\")\n");
        scanf("%s", nomeArquivo);

        do{
            printf("Digite o numero de LINHAS da matriz que será criada: ");
            scanf("%d", &linhas);

            if (linhas < 2 || linhas > 100){
                printf("Número de linhas fora do limite estabelecido! Por favor, digite um valor inteiro maior ou igual a 2 e menor ou igual a 100\n");

            }
            

        } while (linhas < 2 || linhas > 100);
        
        do{
            printf("Digite o numero de COLUNAS da matriz que será criada: ");
            scanf("%d", &colunas);

            if (colunas < 1 || colunas > 100){
                printf("Número de colunas fora do limite estabelecido! Por favor, digite um valor inteiro maior que 0 e menor ou igual a 100\n");

            }
            
        } while (colunas < 1 || colunas > 100);

        do{
            printf("Digite o numero do peso máximo de um caminho: ");
            scanf("%d", &maxCaminho);

            if (maxCaminho < 1){
                printf("Número do caminho fora do limite estabelecido! Por favor, digite um valor inteiro maior que 0!\n");

            }
            
        } while (colunas < 1 || colunas > 100);
        

        inicializaMatriz(&matCaminhosArq, linhas, colunas);

        geraCaminhos(linhas, colunas, matCaminhosArq.matDinamica, maxCaminho);

        printf("\nMatriz que foi preenchida no arquivo:\n");
        printMatriz(matCaminhosArq);

        fptr = fopen(strcat(nomeArquivo, ".txt"), "w");

        fprintf(fptr, "%d %d", linhas, colunas);
        fprintf(fptr, "%c", '\n');

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if (j != 0){
                    fprintf(fptr, " %d", matCaminhosArq.matDinamica[i][j]);

                } else {
                    fprintf(fptr, "%d", matCaminhosArq.matDinamica[i][j]);

                }
            }

            if (i != linhas - 1){
                fprintf(fptr, "%c", '\n');

            }
        }
                
        fclose(fptr);

        free(matCaminhosArq.matDinamica);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Nao.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}
