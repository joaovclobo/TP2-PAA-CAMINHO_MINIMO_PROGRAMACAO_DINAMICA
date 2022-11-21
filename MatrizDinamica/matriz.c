#include "matriz.h"

/**
 * Implementação do header 'matriz.h' e funcionalidades relacionadas a matriz
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @class matriz.c
 * 
 * @headerfile matriz.h
 * 
 * @implements: 
 *      inicializaMatriz - Inicializa matriz vazia;
 *      ...
 * 
 * @version 1.0
 * 
 * @since 11/2022 xx:xx 
 * 
 */


 /**Método inicializaMatriz -  
 * @author x
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @since 11/2022 xx:xx
 */

void inicializaMatriz(Matriz *matriz, int i, int j){
    matriz->linhas = i;
    matriz->colunas = j;
    matriz->matDinamica = (int **)malloc(i*sizeof(int*));

    for(int k = 0; k < i; k++){
        matriz->matDinamica[k] = (int*)malloc(j*sizeof(int));
    }
}

/**Método printMatriz -  
 * @author x
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @since 11/2022 xx:xx
 */

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

/**Método printMatrizDelay -  
 * @author x
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @since 11/2022 xx:xx
 */

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

/**Método geraCaminhos -  
 * @author x
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @param int linhas - Valor que representa quantidade de LINHAS da matriz.
 * @param int colunas - Valor que representa quantidade de COLUNAS da matriz.
 * @param int matrizVazia -
 * @param int maxCaminho -
 * @since 11/2022 xx:xx
 */

void geraCaminhos(int linhas, int colunas, int** matrizVazia, int maxCaminho){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matrizVazia[i][j] = rand() % maxCaminho + 1;
        }
    }
}

/**Método calculaCaminhoMin -  
 * @author x
 * @param Matriz matPesos - 
 * @param Matriz matCaminhos - 
 * @return int
 * @since 11/2022 xx:xx
 */

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

/**Método encontraCaminhoMinMemorization -  
 * @author x
 * @param Matriz matPesos - 
 * @param Matriz matCaminhos - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @since 11/2022 xx:xx
 */

//Usa os valores já calculados na matriz de caminhos mínimos para acha-los
void encontraCaminhoMinMemorization(int i, int j, Matriz matCaminhos, Matriz matPesos, int* numCaminhosMins){
    
    if(i == matPesos.linhas - 1 && j == matPesos.colunas - 1){

        *numCaminhosMins += 1;
        return;

    } else {
        if (i + 1 < matPesos.linhas && j + 1 < matPesos.colunas){

            if (matCaminhos.matDinamica[i+1][j] == matCaminhos.matDinamica[i][j+1]){
                
                encontraCaminhoMinMemorization(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
                encontraCaminhoMinMemorization(i, j + 1, matCaminhos, matPesos, numCaminhosMins);
                return;

            } else if (matCaminhos.matDinamica[i+1][j] < matCaminhos.matDinamica[i][j+1]) {

                encontraCaminhoMinMemorization(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
                return;

            } else {

                encontraCaminhoMinMemorization(i, j + 1, matCaminhos, matPesos, numCaminhosMins);
                return;

            }
            
        } else if (i + 1 < matPesos.linhas){
            
            encontraCaminhoMinMemorization(i + 1, j, matCaminhos, matPesos, numCaminhosMins);
            return;

        }else if (j + 1 < matPesos.colunas){
            
            encontraCaminhoMinMemorization(i, j + 1, matCaminhos, matPesos, numCaminhosMins);

        }
    }

}

/**Método encontraCaminhoMinFrocaBruta -  
 * @author x
 * @param Matriz caminhos - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @param int caminhoMin - 
 * @param int somaCaminho - 
 * @since 11/2022 xx:xx
 */

//Testa todas as possibilidades e verifica se o caminho total é igual ao caminho mínimo
void encontraCaminhoMinFrocaBruta(int i, int j, Matriz caminhos, int caminhoMin, int somaCaminho, int* numCaminhosMins){

    somaCaminho += caminhos.matDinamica[i][j];

    if(i == caminhos.linhas - 1 && j == caminhos.colunas - 1){

        if (somaCaminho == caminhoMin){

            *numCaminhosMins += 1;
        }

        printf("Soma do caminho: %d\n", somaCaminho);
        somaCaminho = 0;
        return;

    } else {

        if (i + 1 < caminhos.linhas){

            encontraCaminhoMinFrocaBruta(i + 1, j, caminhos, caminhoMin, somaCaminho, numCaminhosMins);
        } 

        if (j + 1 < caminhos.colunas){

            encontraCaminhoMinFrocaBruta(i, j + 1, caminhos, caminhoMin, somaCaminho, numCaminhosMins);    
        }
    }

}

/**Método encontraCaminhoMinBacktracking -  
 * @author x
 * @param Matriz caminhos - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @param int caminhoMin - 
 * @param int somaCaminho - 
 * @since 11/2022 xx:xx
 */

//Caminha para todas as possibilidades e retorna caso a soma seja maior que a soma mínima
void encontraCaminhoMinBacktracking(int i, int j, Matriz caminhos, int caminhoMin, int somaCaminho, int* numCaminhosMins){

    somaCaminho += caminhos.matDinamica[i][j];

    //Esta condição visa tornar o algorítimo de encontrar o caminho minimo mais eficiente
    if (somaCaminho > caminhoMin){
        somaCaminho = 0;
        return;
    }

    if(i == caminhos.linhas - 1 && j == caminhos.colunas - 1){

        if (somaCaminho == caminhoMin){

            *numCaminhosMins += 1;
        }

        printf("Soma do caminho: %d\n", somaCaminho);
        somaCaminho = 0;
        return;

    } else {

        if (i + 1 < caminhos.linhas){

            encontraCaminhoMinBacktracking(i + 1, j, caminhos, caminhoMin, somaCaminho, numCaminhosMins);
        } 

        if (j + 1 < caminhos.colunas){

            encontraCaminhoMinBacktracking(i, j + 1, caminhos, caminhoMin, somaCaminho, numCaminhosMins);    
        }
    }

}