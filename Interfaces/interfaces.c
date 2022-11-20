#include "interfaces.h"

/**
 * Implementação do header 'interfaces.h' e funcionalidades relacionadas a interface visível para o Usuário.
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @class interfaces.c
 * 
 * @headerfile interfaces.h
 * 
 * @implements: 
 *      cabecalhoMain - Cabeçalho do arquivo principal(main);
 *      ...
 * 
 * @version 1.0
 * 
 * @since 11/2022 xx:xx 
 * 
 */

/** Funções de interface*/

 /**Método cabecalhoMain -  
 * @author x
 * @since 11/2022 xx:xx
 */

void cabecalhoMain(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|======================================== Viagem com custo mínimo ==========================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

/**Método cabecalhoGerador -  
 * @author x
 * @since 11/2022 xx:xx
 */

void cabecalhoGerador(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|==================================== Gerador de campos de asteroides ======================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

/**Método menuOpcoes -  
 * @author x
 * @return int
 * @since 11/2022 xx:xx
 */
int menuOpcoes(){

    int opcao = 1;
    
    printf("\nDigite uma opção para mostrar o caminho resultante, caso haja solução para a fazenda :\n\n\
    1) - Sequencia de coordenadas da matriz (opção sugerida pela especificação).\n");

    scanf("%d", &opcao);
    return opcao;
}

/**Método exibicaoOpcoes -  
 * @author x
 * @since 11/2022 xx:xx
 */

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

/**Método printVetor -  Função para mostar as matrizes ou vetores
 * @author x
 * @since 11/2022 xx:xx
 */

void printVetor(int* vetor, int tamVetor){
    for (int i = 0; i < tamVetor; i++){
        printf("%d ", vetor[i]);

    }

    putchar('\n');
}

/** Funções para mostar as matrizes ou vetores*/

/**Método opcoesEncontraCaminho -  Função que mostra opções para o usuário escolher a função para escolher o caminho;
 * @author @Aroldo Augusto Barbosa Simões
 * @since 19/11/2022 21:00
 */

void opcoesEncontraCaminho(){
    printf("|===========================================================================================================|\n\n");
    printf("Escolha uma das seguintes opções para encontrar o caminhos: \n");
    printf("1 - encontraCaminhoMinMemorization\n"); //TODO: MUDAR NOMEAÇÃO
    printf("2 - encontraCaminhoMinFrocaBruta\n");
    printf("3 - encontraCaminhoMinBacktracking\n");
    printf("\n|===========================================================================================================|\n\n");

}
