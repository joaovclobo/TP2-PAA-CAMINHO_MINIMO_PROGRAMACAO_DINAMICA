all:
	gcc -o Main main.c MatrizDinamica/matriz.c MatrizDinamica/matriz.h LeituraDados/leituraArquivos.h LeituraDados/leituraArquivos.c Interfaces/interfaces.c Interfaces/interfaces.h

geraCam:
	gcc -o GeraCam GeradorCaminhos.c MatrizDinamica/matriz.c MatrizDinamica/matriz.h LeituraDados/leituraArquivos.h LeituraDados/leituraArquivos.c Interfaces/interfaces.c Interfaces/interfaces.h

clean:
	rm Main
	rm GeraCam