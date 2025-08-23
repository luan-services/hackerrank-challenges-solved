#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'
#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.
#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

typedef struct triangle {
	int a;
	int b;
	int c;
} triangle;

double calculateArea(triangle tr) { // O (1) funcao para calcular area do triangulo
        double p = (tr.a + tr.b + tr.c) / 2.0; // precisa ser double pro calculo retornar numero com virgula
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
};

void sort_by_area(triangle* tr, int n) {
    triangle key;
    double keyArea;
    int j;
    
    for (int i = 0; i < n; i++) { // O (n)
        key = *(tr + i); // o struct triangulo i vira key
        keyArea = calculateArea(*(tr + i)); // calcula area dele
        j = i - 1; 
        while (j >= 0 && calculateArea(*(tr + j)) > keyArea) { // O (1->n)
            *(tr + j + 1) = *(tr + j); // o valor do endereço (tr+j+i), vira o valor do endereço (tr+j)
            j = j - 1;
        };
        *(tr + j + 1) = key; // por fim, o ultimo elemento vira key
    };
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
	
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;

}