all:
	clear
	gcc -o Main main.c MatrizDinamica/matriz.c MatrizDinamica/matriz.h LeituraDados/leituraArquivos.h LeituraDados/leituraArquivos.c Interfaces/interfaces.c Interfaces/interfaces.h
	./Main

geraCam:
	clear
	gcc -o GeraCam GeradorCaminhos.c MatrizDinamica/matriz.c MatrizDinamica/matriz.h LeituraDados/leituraArquivos.h LeituraDados/leituraArquivos.c Interfaces/interfaces.c Interfaces/interfaces.h
	./GeraCam

clean:
	rm Main
	rm GeraCam