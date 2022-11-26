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
 * @since 11/2022 14:00 
 * 
 */


 /**FunçãoinicializaMatriz -  
 * @author @Thiago Cândido
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @since 10/2022 14:00
 */
void inicializaMatriz(Matriz *matriz, int i, int j){
    matriz->linhas = i;
    matriz->colunas = j;
    matriz->matDinamica = (int **)malloc(i*sizeof(int*));

    for(int k = 0; k < i; k++){
        matriz->matDinamica[k] = (int*)malloc(j*sizeof(int));
    }
}

/**Função printMatriz -  
 * @author @Thiago Cândido
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @since 10/2022 14:00
 */
void printMatriz(Matriz matriz){

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
}



/**Função printCaminhoEmoji -  
 * @author @Thiago Cândido
 * @param int **caminho
 * @param int linhas
 * @param int colunas
 * @since 11/2022 20:00
 */
void printCaminhoEmoji(int **caminho, int linhas, int colunas){
    int emojiSort;
    char *caminhoEmoji[linhas][colunas];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(caminho[i][j] != 0){
                caminhoEmoji[i][j] = "\U0001F6F8";
            }
            else{
                caminhoEmoji[i][j] = "\U0001F7E6"; 
                
            }
        }
    }

    printf("Caminho emojis:\n");
    for(int i = 0; i < linhas; i++){
        printf("\n");
        for(int j = 0; j < colunas; j++){
            printf("%s", caminhoEmoji[i][j]);
        }
    }
    printf("\n\n");
}

/**Função printCaminhoEmoji -  
 * @author @Thiago Cândido
 * @param Matriz matriz
 * @since 11/2022 20:00
 */
void printCaminhoCoordenadas(Matriz matriz){
    for(int i = 0; i < matriz.linhas; i++){
        //printf("\n");
        for(int j = 0; j < matriz.colunas; j++){
            if(matriz.matDinamica[i][j] != 0){
                printf("(%d,%d)->", i,j);
            }
        }
    }
    printf("\n\n");
}
/**Função geraCaminhos -  
 * @author @João Vitor Chagas Lobo
 * @param Matriz *matriz - Ponteiro para matriz dinâmica.
 * @param int linhas - Valor que representa quantidade de LINHAS da matriz.
 * @param int colunas - Valor que representa quantidade de COLUNAS da matriz.
 * @param int matrizVazia - 
 * @param int maxCaminho - 
 * @since 11/2022 20:00
 */
void geraCaminhos(int linhas, int colunas, int** matrizVazia, int maxCaminho){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matrizVazia[i][j] = rand() % maxCaminho + 1;
        }
    }
}

/**Função calculaCaminhoMin -  
 * @author @João Vitor Chagas Lobo
 * @param Matriz matViagem - 
 * @param Matriz matCaminhosMin - 
 * @return int
 * @since 11/2022 20:00
 */
int calculaCaminhoMin(Matriz matViagem, Matriz matCaminhosMin){
    
    int lin = matViagem.linhas - 1;
    int col = matViagem.colunas - 1;

    matCaminhosMin.matDinamica[lin][col] = matViagem.matDinamica[lin][col];

    for (int i = lin; i >= 0; i--){
        
        for (int j = col; j >= 0; j--){
            
            if (i < lin && j < col){

                if (matCaminhosMin.matDinamica[i+1][j] == 0 || matCaminhosMin.matDinamica[i][j+1] == 0 || matCaminhosMin.matDinamica[i + 1][j] > matCaminhosMin.matDinamica[i][j + 1]){
                   
                    matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i + 1][j];
                    matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i][j + 1];

                } else {
                   
                    matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i][j + 1];
                    matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i + 1][j];

                }

            } else if (i < lin) {
                matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i + 1][j];

            } else if (j < col) {
                matCaminhosMin.matDinamica[i][j] = matViagem.matDinamica[i][j] + matCaminhosMin.matDinamica[i][j + 1];

            }
        }
    }
    
    return matCaminhosMin.matDinamica[0][0];    
}


/**Função encontraCaminhoMinMemorization -  
 * @author @João Vitor Chagas Lobo
 * @param Matriz matViagem - 
 * @param Matriz matCaminhosMin - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @since 11/2022 20:00
 */

//Usa os valores já calculados na matriz de caminhos mínimos para acha-los
void encontraCaminhoMinMemorization(int i, int j, Matriz matCaminhosMin, Matriz matViagem, int* numCaminhosMins){
    
    if(i == matViagem.linhas - 1 && j == matViagem.colunas - 1){

        *numCaminhosMins += 1;
        return;

    } else {
        if (i + 1 < matViagem.linhas && j + 1 < matViagem.colunas){

            if (matCaminhosMin.matDinamica[i+1][j] == matCaminhosMin.matDinamica[i][j+1]){
                
                encontraCaminhoMinMemorization(i + 1, j, matCaminhosMin, matViagem, numCaminhosMins);
                encontraCaminhoMinMemorization(i, j + 1, matCaminhosMin, matViagem, numCaminhosMins);
                // return;

            } else if (matCaminhosMin.matDinamica[i+1][j] < matCaminhosMin.matDinamica[i][j+1]) {

                encontraCaminhoMinMemorization(i + 1, j, matCaminhosMin, matViagem, numCaminhosMins);
                // return;

            } else {

                encontraCaminhoMinMemorization(i, j + 1, matCaminhosMin, matViagem, numCaminhosMins);
                // return;

            }
            
        } else if (i + 1 < matViagem.linhas){
            
            encontraCaminhoMinMemorization(i + 1, j, matCaminhosMin, matViagem, numCaminhosMins);
            // return;

        }else if (j + 1 < matViagem.colunas){
            
            encontraCaminhoMinMemorization(i, j + 1, matCaminhosMin, matViagem, numCaminhosMins);

        }
    }
}

/**Função encontraCaminhoMinBacktracking -  
 * @author @João Vitor Chagas Lobo
 * @param Matriz caminhos - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @param int caminhoMin - 
 * @param int somaCaminho - 
 * @since 11/2022 20:00
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

/**Função encontraCaminhoMinFrocaBruta -  
 * @author @João Vitor Chagas Lobo
 * @param Matriz caminhos - 
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @param int caminhoMin - 
 * @param int somaCaminho - 
 * @since 11/2022 20:00
 */
//Testa todas as possibilidades e verifica se o caminho total é igual ao caminho mínimo
void encontraCaminhoMinFrocaBruta(int i, int j, Matriz caminhos, int caminhoMin, int somaCaminho, int* numCaminhosMins){

    somaCaminho += caminhos.matDinamica[i][j];

    if(i == caminhos.linhas - 1 && j == caminhos.colunas - 1){

        if (somaCaminho == caminhoMin){

            *numCaminhosMins += 1;
        }

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

void encontraCaminhoDivK(int i, int j, Matriz caminhos, int k, int somaCaminho, int* numCaminhosDivK){

    somaCaminho += caminhos.matDinamica[i][j];

    if(i == caminhos.linhas - 1 && j == caminhos.colunas - 1){

        if (somaCaminho % k == 0){
            *numCaminhosDivK += 1;
        }

        somaCaminho = 0;
        return;

    } else {

        if (i + 1 < caminhos.linhas){

            encontraCaminhoDivK(i + 1, j, caminhos, k, somaCaminho, numCaminhosDivK);
        } 

        if (j + 1 < caminhos.colunas){

            encontraCaminhoDivK(i, j + 1, caminhos, k, somaCaminho, numCaminhosDivK);    
        }
    }
}

/**Função encontraCaminhoMinImprime -  
 * @author @Thiago Cândido Rocha
 * @param Matriz matCaminhosMin
 * @param Matriz matViagem
 * @param Matriz matPrint
 * @param int i - Valor que representa quantidade de LINHAS da matriz.
 * @param int j - Valor que representa quantidade de COLUNAS da matriz.
 * @param int* numCaminhosMins - 
 * @param int caminhoMin - 
 * @param int somaCaminho - 
 * @since 11/2022 19:00
 */

void encontraCaminhoMinImprime(int i, int j, Matriz matCaminhosMin, Matriz matViagem, Matriz matPrint, int* numCaminhosMins, int opcoes){
    
    if(opcoes != 4)
        matPrint.matDinamica[i][j] = 1;

    else
        matPrint.matDinamica[i][j] = matCaminhosMin.matDinamica[i][j];

    if(i == matViagem.linhas - 1 && j == matViagem.colunas - 1){
        //printMatriz(matPrint);
        switch(opcoes){
            case 1:
                printMatriz(matPrint);
                break;
            case 2:
                printCaminhoEmoji(matPrint.matDinamica, matPrint.linhas, matPrint.colunas);
                break;
            case 3:
                printCaminhoCoordenadas(matPrint);
                break;
            case 4:
                printMatriz(matPrint);
                break;
        }
        //numeraMatrizZeros(&matPrint);
        *numCaminhosMins += 1;
        return;

    } else {
        if (i + 1 < matViagem.linhas && j + 1 < matViagem.colunas){
            
            if (matCaminhosMin.matDinamica[i+1][j] == matCaminhosMin.matDinamica[i][j+1]){
                
                encontraCaminhoMinImprime(i + 1, j, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);
                encontraCaminhoMinImprime(i, j + 1, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);
                //return;

            } else if (matCaminhosMin.matDinamica[i+1][j] < matCaminhosMin.matDinamica[i][j+1]) {

                encontraCaminhoMinImprime(i + 1, j, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);
                //return;

            } else {

                encontraCaminhoMinImprime(i, j + 1, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);
                //return;

            }
            
        } else if (i + 1 < matViagem.linhas){
            
            encontraCaminhoMinImprime(i + 1, j, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);
            //return;

        }else if (j + 1 < matViagem.colunas){
            
            encontraCaminhoMinImprime(i, j + 1, matCaminhosMin, matViagem, matPrint, numCaminhosMins, opcoes);

        }
    }
    matPrint.matDinamica[i][j] = 0;
}
