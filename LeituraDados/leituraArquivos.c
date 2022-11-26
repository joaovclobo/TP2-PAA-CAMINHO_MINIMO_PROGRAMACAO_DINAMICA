#include "leituraArquivos.h"

/**
 * Leitura de Arquivos de texto. 
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @Nome do arquivo leituraArquivos.c
 * 
 * @headerfile leituraArquivos.h
 * 
 * @implements: 
 *      leituraLinhasColunas - ;
 *      copiaMatrizFILE - .
 * 
 * @since 11/2022 xx:xx
 * 
 * @version 1.0
 * 
 */

FILE* abreArquivo(){

    char nomeArquivo[MAX_BUFFER];
    FILE *fptr;

    do{
        printf("\nInsira o nome completo do arquivo com a fazenda (o arquivo deve estar na mesma pasta que está este executavel e deve ter a extensão \".txt\")\n");
        scanf("%s", nomeArquivo);
        //strcpy(nomeArquivo, "./ArquivosTeste/matrizExemplo1");
        
        fptr = fopen(strcat(nomeArquivo, ".txt"), "r");

        if (fptr == NULL){
            printf("\nERRO: Arquivo não encontrado!\nPor favor, insira um arquivo válido!\n");
            
        }

    } while (fptr == NULL);

    return fptr;

}

void leituraLinhasColunas(FILE *fp, int* linha, int* coluna){

    char buffer[MAX_BUFFER] = "u";
    char secondary[MAX_BUFFER];

    strncat(buffer,fgets(secondary, MAX_BUFFER, fp), MAX_BUFFER);

    sscanf(buffer,"%*[^0123456789]%d%*[^0123456789]%d", linha, coluna);
      
}

void copiaMatrizFILE(FILE *fp, int linha, int coluna, int **matriz){

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }

}