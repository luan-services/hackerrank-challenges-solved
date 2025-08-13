#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'
#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.
#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


int calculateMaxDistance(int i, int j, int center) {
    i = abs(i - center);
    j = abs(j - center);
    
    if (i > j) {
        return i + 1;
    } else {
        return j + 1;
    };
};

void printPattern(int n) {
    int center = n - 1;
    for (int i = 0; i < (n * 2) - 1; i++) {
        for (int j = 0; j < (n * 2) - 1; j++) {
            printf("%i ", calculateMaxDistance(i, j, center));
        }
        printf("\n");
    };
};


// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
	
    int n;
    scanf("%d", &n);
    printPattern(n);
    return 0;

}