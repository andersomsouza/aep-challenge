/*
------- Marvelous Maze
------- Problema I : Algoritmos e Programação
------- Developer : Anderson Souza
*/


#include <stdio.h>
#include <stdlib.h>

char isANumber(char c);
int fimDeLinha(char c);

int main(int argc, char **argv) {
	FILE *f;
	//verifico o contador de argumentos para saber
	//se o arquivo foi informado, realizo a abertura do descritor
	if (argc < 2) {
		printf("É necessário um arquivo de entrada.\nSintaxe: %s <arquivo>\n", argv[0]);
		exit(EXIT_FAILURE);
	} else {
		f = fopen(argv[1], "r");
		if (f == NULL) {
			printf("Não foi possível abrir o arquivo.\n");
			exit(EXIT_FAILURE);
		}
	}
	//variavel para contagem de caracteres da linha
	//max 132 caracteres.
	int countLinha = 0;
	//inicializo variavel de leitura
	char pont = fgetc(f);
	//enquanto a variavel for diferente de NULL ou fim do arquivo
	//fica no laço de while
	while ((pont != 0) && (pont != EOF)) {
		if (isANumber(pont)) {
			//se o caracter for um numero
			//vai somando, até aparecer um caracter diferente
			char numero = 0;
			while (isANumber(pont)) {
				numero += pont - '0'; // diminui '0' do caracter para passar o numero para inteiro
				pont = fgetc(f);
				countLinha++;
			}
			//o caracter a ser impresso já esta na variavel count
			char caracter = pont;
			if (caracter == 'b') {caracter = ' ';} // caracter b igual a space
			while (numero--) {printf("%c", caracter);}
			pont = fgetc(f);
			countLinha++;
		} else if (fimDeLinha(pont)) {
			//se for fim de linha (\n , retorno do feed (\r*), ou '!' imprime uma linha)
			//e zera a variavel de controle de caracteres por linha
			pont = fgetc(f);
			countLinha = 0;
			printf("\n");
		} else {
			err(EXIT_FAILURE, "Erro de Sintaxe! %d", pont);
		}

		if (countLinha > 132) {
			err(EXIT_FAILURE, "Superou quantidade máxima de caracteres!");
		}
	};
	exit(EXIT_SUCCESS);
}

char isANumber(char c) {
	if ((c >= '0') && (c <= '9')) {return 1;}
	return 0;
}

int fimDeLinha(char c) {
	if (c == '!') return 1;
	if (c == '\r')  return 1;
	if (c == '\n')  return 1;
	return 0;
}



