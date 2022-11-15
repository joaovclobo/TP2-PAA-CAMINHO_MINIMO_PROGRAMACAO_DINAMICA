#include "interfaces.h"

/** Funções de interface*/
void cabecalhoMain(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|======================================== Viagem com custo mínimo ==========================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

void cabecalhoGerador(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|==================================== Gerador de campos de asteroides ======================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

int menuOpcoes(){

    int opcao = 1;
    
    printf("\nDigite uma opção para mostrar o caminho resultante, caso haja solução para a fazenda :\n\n\
    1) - Sequencia de coordenadas da matriz (opção sugerida pela especificação).\n");

    scanf("%d", &opcao);
    return opcao;
}

//TODO avaliar se da pra reaproveitar
void exibicaoOpcoes(int opcao, Matriz matCaminhos, Matriz matrizFazenda, int linhas, int colunas){

    switch (opcao){

        case 1:
            printMatriz(matCaminhos);
            break;

        default:
            break;
    }
}

/** Funções para mostar as matrizes ou vetores*/
void printVetor(int* vetor, int tamVetor){
    for (int i = 0; i < tamVetor; i++){
        printf("%d ", vetor[i]);

    }

    putchar('\n');
}
