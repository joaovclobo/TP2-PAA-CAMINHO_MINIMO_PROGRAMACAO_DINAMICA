#include "leituraArquivos.h"

FILE* abreArquivo(){

    char nomeArquivo[MAX_BUFFER];
    FILE *fptr;

    do{
        printf("\nInsira o nome completo do arquivo com a fazenda (o arquivo deve estar na mesma pasta que está este executavel - Ex. do nome da entrada esperada: fazenda.txt)\n");
        // scanf("%s", nomeArquivo);
        strcpy(nomeArquivo, "./ArquivosTeste/matrizExemplo4.txt");
        
        fptr = fopen(nomeArquivo, "r");

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