#include "matriz.h"

void inicializaMatriz(Matriz *matriz, int i, int j){
    matriz->linhas = i;
    matriz->colunas = j;
    matriz->matDinamica = (int **)malloc(i*sizeof(int*));

    for(int k = 0; k < i; k++){
        matriz->matDinamica[k] = (int*)malloc(j*sizeof(int));
    }
}

void printMatriz(Matriz matriz){

    for (int i = 0; i < matriz.colunas; i++){
        printf("----");
    }

    for(int i = 0; i < matriz.linhas; i++){
        printf("\n");
        for(int j = 0; j < matriz.colunas; j++){
            printf(" %2d ", matriz.matDinamica[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < matriz.colunas; i++){
        printf("----");
    }

    printf("\n");
}

void printMatrizDelay(Matriz matriz){

    for (int i = 0; i < matriz.colunas; i++){
        printf("----");
    }

    for(int i = 0; i < matriz.linhas; i++){
        printf("\n");
        for(int j = 0; j < matriz.colunas; j++){
            if(matriz.matDinamica[i][j] == 0){
                printf("%s %2d %s",RED, matriz.matDinamica[i][j],RESET);
            }
            else{
                printf("%s %2d %s",GREEN, matriz.matDinamica[i][j],RESET);
            }
            
        }
    }
    printf("\n");
    for (int i = 0; i < matriz.colunas; i++){
        printf("----");
    }

    printf("\n");
    usleep(400000);

}

void geraCaminhos(int linhas, int colunas, int** matrizVazia, int maxCaminho){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matrizVazia[i][j] = rand() % maxCaminho + 1;
        }
    }
}

int calculaCaminhoMin(Matriz matPesos, Matriz matCaminhos){
    
    int lin = matPesos.linhas - 1;
    int col = matPesos.colunas - 1;

    matCaminhos.matDinamica[lin][col] = matPesos.matDinamica[lin][col];
    printMatriz(matCaminhos);
    

    for (int i = lin; i >= 0; i--){
        
        for (int j = col; j >= 0; j--){
            
            if (i < lin && j < col){

                if (matCaminhos.matDinamica[i+1][j] == 0 || matCaminhos.matDinamica[i][j+1] == 0 || matCaminhos.matDinamica[i + 1][j] > matCaminhos.matDinamica[i][j + 1]){
                   
                    matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i + 1][j];
                    matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i][j + 1];
                    printMatriz(matCaminhos); putchar('\n');

                } else {
                   
                    matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i][j + 1];
                    matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i + 1][j];
                    printMatriz(matCaminhos); putchar('\n');

                }

            } else if (i < lin) {
                matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i + 1][j];
                printMatriz(matCaminhos); putchar('\n');
                    
            } else if (j < col) {
                matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i][j + 1];
                printMatriz(matCaminhos); putchar('\n');

            }
        }
    }
    
    return matCaminhos.matDinamica[0][0];    
}

void encontraCaminhoMin(int i, int j, Matriz matCaminhos, Matriz matPesos, int* numCaminhosMins){
    
    if(i == matPesos.linhas - 1 && j == matPesos.colunas - 1){

        *numCaminhosMins += 1;
        return;

    } else {
        // printf("teste\n");
        if (i + 1 < matPesos.linhas && j + 1 < matPesos.colunas){

            if (matCaminhos.matDinamica[i+1][j] == matCaminhos.matDinamica[i][j+1]){
                // printf("Igual\n");
                encontraCaminhoMin(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
                encontraCaminhoMin(i, j + 1, matCaminhos, matPesos, numCaminhosMins);
                return;

            } else if (matCaminhos.matDinamica[i+1][j] < matCaminhos.matDinamica[i][j+1]) {
                // printf("Linha\n");
                encontraCaminhoMin(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
                return;

            } else {
                // printf("Coluna\n");
                encontraCaminhoMin(i, j + 1, matCaminhos, matPesos, numCaminhosMins);
                return;

            }
            
        } else if (i + 1 < matPesos.linhas){
            
            encontraCaminhoMin(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
            return;

        }else if (j + 1 < matPesos.colunas){
            
            // printf("Coluna\n");
            encontraCaminhoMin(i, j + 1, matCaminhos, matPesos, numCaminhosMins);

        }
    }
}

