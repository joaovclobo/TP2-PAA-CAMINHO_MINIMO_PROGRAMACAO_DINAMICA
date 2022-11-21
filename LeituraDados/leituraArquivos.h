#include "../MatrizDinamica/matriz.h"
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER 100

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

FILE* abreArquivo();
void leituraLinhasColunas(FILE *fp, int* linha, int* coluna);
void copiaMatrizFILE(FILE *fp, int linha, int coluna, int **matriz);
