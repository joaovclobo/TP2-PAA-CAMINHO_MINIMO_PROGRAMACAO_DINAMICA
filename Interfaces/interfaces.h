#include <stdio.h>
#include "../LeituraDados/leituraArquivos.h"

#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

/**
 * @brief HeraderFile 
 * 
 * @authors @João Vitor Chagas Lobo; @Thiago Cândido; @Aroldo Augusto Barbosa Simões
 * 
 * @since 11/2022 xx:xx
 * 
 * @version 1.0
 * 
 */

/** Funções de interface*/
void cabecalhoMain();
void cabecalhoGerador();
int opcoesEncontraCaminho(); //Opções para o usuário escolher a função para escolher o caminho;
