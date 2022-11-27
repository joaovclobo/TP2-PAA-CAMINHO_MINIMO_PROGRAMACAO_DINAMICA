#include "interfaces.h"

/**
 * Implementação do header 'interfaces.h' e funcionalidades relacionadas a interface visível para o Usuário.
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @Nome do arquivo interfaces.c
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

 /**FunçãocabecalhoMain -  
 * @author x
 * @since 11/2022 xx:xx
 */

void cabecalhoMain(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|======================================== Viagem com custo mínimo ==========================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

/**Função cabecalhoGerador -  
 * @author @João Vitor Chagas Lobo
 * @since 11/2022 xx:xx
 */

void cabecalhoGerador(){
    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|==================================== Gerador de campos de asteroides ======================================|\n\n");
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");
}

/**Função opcoesEncontraCaminho -  Função que mostra opções para o usuário escolher a função para escolher o caminho;
 * @author @Aroldo Augusto Barbosa Simões
 * @author @João Vitor Chagas Lobo
 * @since 21/11/2022 19:00
 */

int opcoesEncontraCaminho(){

    int escolhaUsuario;

    printf("\nEscolha uma das seguintes opções para encontrar o caminhos:\n\n\
    1) - Utilizando uma função que usa \"Memorization\";\n\
    2) - Utilizando uma função que usa Backtracking;\n\
    3) - Utilizando uma função que usa Froça Bruta;\n\
    4) - Encontrar e mostrar os caminhos (utilizando função que usa \"Memorization\");\n\
    5) - Encontrar a numero de caminhos divisiveis por k (utilizando função que usa Força Bruta).\n");

    scanf("%d", &escolhaUsuario);
    return escolhaUsuario;
}

int opcoesImprimirCaminho(){
    int option = 0;

    printf("\nEscolha uma das seguintes opções para visualizar os caminhos mínimos:\n\n\
    1) - Matriz caminho colorida\n\
    2) - Matriz caminho representada com emojis\n\
    3) - Forma tradicional: Coordenadas\n\
    4) - Matriz de pesos colorida\n");
    

    scanf("%d", &option);

    return option;


}
