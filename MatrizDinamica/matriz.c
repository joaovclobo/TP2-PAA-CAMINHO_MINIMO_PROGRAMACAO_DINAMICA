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

//TODO avaliar se da pra reaproveitar
void geraFazenda1(int linhas, int colunas, int** matrizVazia, int* vetorFib){
    //Função responsável por gerar aleatoriamente uma matriz que representa a Fazenda.

    int nRand = rand() % (linhas*colunas);

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matrizVazia[i][j] = vetorFib[nRand];
            nRand = rand() % (linhas*colunas);
        }
        
    }
}

//TODO avaliar se da pra reaproveitar
void geraFazenda2(int linhas, int colunas, int** matrizVazia, int* vetorFib){
    //Função responsável por gerar aleatoriamente uma matriz que contém um caminho esperado e que representa a Fazenda.
    
    srand(time(NULL));
    int posVetorFibonacci = 0;
    int escolhaCaminho = 0; //caminho escolhido aleatoriamente para inserir o número de fibonacci;
    int escolhaAnterior = 0;
    int proxI = 0, proxJ = 0; //próxima posição a ser acessada da matriz;
    int baseI = 0, baseJ = 0;
    
    proxJ = rand() % (colunas);     //número aleatório para definir qual coluna da primeira linha será escolhida para inserir o primeiro número de fibonacci;
    
    matrizVazia[proxI][proxJ] = vetorFib[posVetorFibonacci]; //insere o primeiro núm. fibonacci na primeira linha da matriz;
    posVetorFibonacci++; //avança uma posição no vetor de fibonacci;

    short flagI = false;
    
    while (!flagI){
        baseI = proxI;
        baseJ = proxJ;
        if(escolhaAnterior != 0){
            escolhaCaminho = 0;
            escolhaAnterior = escolhaCaminho;
        }
        else {
            escolhaCaminho = rand() % 4;
            escolhaAnterior = escolhaCaminho;
        }
        
        switch (escolhaCaminho) {
            case 0:
                //Tenta para a posição a abaixo;
                proxI ++, proxJ = proxJ;
                break;
            case 1:
                //Tenta para a posição a esquerda;
                proxI = proxI; proxJ --;
                break;
            case 2:
                //Tenta a posição a direita;
                proxI = proxI; proxJ ++;
                break;
            case 3:
                //Tenta a posição acima;
                proxI --, proxJ = proxJ;
                break;        
            default:
                proxI ++, proxJ = proxJ;
                break;
        }

        //Confere se a proxima posição está dentro do limite da fazenda
        if((proxI >= 0 && proxI < linhas) && (proxJ >= 0 && proxJ < colunas)){ 
            
            //Confere se a próxima posição é valida
            if (matrizVazia[proxI][proxJ] == 0) {

                matrizVazia[proxI][proxJ] = vetorFib[posVetorFibonacci];
                posVetorFibonacci++;

                //Se 'flagI == true' então o caminho chegou ao final da matriz.
                if (proxI == linhas - 1){
                    flagI = true;
                }
            }
            else {
                proxI = baseI;
                proxJ = baseJ;
            }
        }
        else {
                proxI = baseI;
                proxJ = baseJ;
            }
    }
    
    int nRand = rand() % (linhas*colunas);

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matrizVazia[i][j] == 0) {
                 matrizVazia[i][j] = vetorFib[nRand];
                nRand = rand() % (linhas*colunas);
            }
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
    
            if (i < lin){
                matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i + 1][j];
                printf("IF do i:\nVal i: %d, Val j: %d\n", i, j);
                printMatriz(matCaminhos);
                putchar('\n');

            }


            if (j < col){
                matCaminhos.matDinamica[i][j] = matPesos.matDinamica[i][j] + matCaminhos.matDinamica[i][j + 1];
                printf("IF do j:\nVal i: %d, Val j: %d\n", i, j);
                printMatriz(matCaminhos);
                putchar('\n');
                
            }

        }
    }

    return matPesos.matDinamica[0][0];    
}
