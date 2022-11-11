#include "../MatrizDinamica/matriz.h"
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER 100

FILE* abreArquivo();
void leituraLinhasColunas(FILE *fp, int* linha, int* coluna);
void copiaMatrizFILE(FILE *fp, int linha, int coluna, int **matriz);
