#include "LeituraDados/leitura.h"
#include "Fibonacci/fibonacci.h"

int main(){
    
    int linhas, colunas;

    short encerra = false;

    char nomeArquivo[MAX_BUFFER];

    Matriz matrizFazendaArq;
    FILE *fptr;

    time_t tempo;
    srand((time(&tempo)));

    printf("\n\n|============================ Universidade Federal De Viçosa - Campus Florestal ============================|\n|================ Trabalho prático 1 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ================|\n");
    printf("|======================================= Gerador de arquivos de fazenda =======================================|\n\n");  
    printf("Professor responsável:\n    Daniel Mendes Barbosa\n\nAlunos responsáveis:\n    Thiago Rocha - 4225    \n    Aroldo Simões - 4250    \n    Joao Lobo - 4693\n\n");
    printf("|===========================================================================================================|\n\n");

    do {
        int escolhaGeradorFazenda = 0;
        int* vetorFib = NULL;

        printf("Insira o nome completo do arquivo que será gerado (o arquivo será salvo na mesma pasta que está este executavel - Ex. do nome da entrada esperada: fazenda.txt)\n");
        scanf("%s", nomeArquivo);

        printf("Digite o numero de LINHAS da matriz que será criada: ");
        scanf("%d", &linhas);

        printf("Digite o numero de COLUNAS da matriz que será criada: ");
        scanf("%d", &colunas);

        inicializaMatriz(&matrizFazendaArq, linhas, colunas);
        vetorFibonacci(linhas*colunas, &vetorFib);

        printf("\nEscolha o gerador de fazenda aleatorio que ira utilizar:\n\
    1) - Gerador de fazenda (pode não possuir caminho)\n\
    2) - Gerador de fazenda 2 (sempre possui caminho)\n");
        scanf("%d", &escolhaGeradorFazenda);

        switch (escolhaGeradorFazenda){
            case 1:
                geraFazenda1(linhas, colunas, matrizFazendaArq.matrizDinamica, vetorFib);
            break;

            case 2:
                geraFazenda2(linhas, colunas, matrizFazendaArq.matrizDinamica, vetorFib);
            break;

            default:
                geraFazenda1(linhas, colunas, matrizFazendaArq.matrizDinamica, vetorFib);
            break;
        }

        printf("Matriz que foi preenchida no arquivo:\n");
        printMatriz(matrizFazendaArq);

        fptr = fopen(nomeArquivo, "w");

        fprintf(fptr, "%d %d", linhas, colunas);
        fprintf(fptr, "%c", '\n');

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                if (j != 0){
                    fprintf(fptr, " %d", matrizFazendaArq.matrizDinamica[i][j]);

                } else {
                    fprintf(fptr, "%d", matrizFazendaArq.matrizDinamica[i][j]);

                }
            }

            if (i != linhas - 1){
                fprintf(fptr, "%c", '\n');

            }
        }
                
        fclose(fptr);

        free(matrizFazendaArq.matrizDinamica);
        free(vetorFib);

        printf("\nDeseja encerrar o programa?\n    1) - Sim.\n    0) - Nao.\n");
        scanf("%hu", &encerra);

    } while (encerra == false);

    return 0;
}