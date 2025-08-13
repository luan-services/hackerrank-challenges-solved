#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'
#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.
#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


#include <stdarg.h> // necessário ao usar funções variáveis, permite usar os macros

/* 
va_list: Este é um tipo de dado usado para declarar uma variável que irá conter a lista de argumentos. Você pode pensar nela como um ponteiro para o argumento atual que está sendo processado.

va_start: Esta macro inicializa a variável va_list. Você deve chamá-la primeiro para configurar a lista de argumentos. Ela aceita dois argumentos: a variável va_list e o nome do último parâmetro fixo. É assim que a função sabe onde os argumentos variáveis começam.

va_start(va_list args, ultimo_parametro_nomeado);

va_arg: Esta macro recupera o próximo argumento da lista. Ela aceita a variável va_list e o tipo do argumento que você espera ler. Isso é crucial porque va_arg precisa saber o tipo de dado para determinar quantos bytes ler e como interpretá-los.

va_arg(va_list args, tipo);

va_end: Esta macro realiza a limpeza da variável va_list. É importante chamá-la antes que a função retorne para liberar quaisquer recursos que possam ter sido alocados.

va_end(va_list args);
*/




#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
int  sum (int count,...) {
    int sum = 0;
    // declara a variavel que vai receber os argumentos. 
    va_list args;
    
    // inicializa a lista, count e a quantidade de argumentos
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        // pega o proximo arguemnto na lista
        sum += va_arg(args, int);
    }
    
    // limpa a lista
    va_end(args);
    
    return sum;
}

int min(int count,...) {
    int min = MAX_ELEMENT;
    // declara a variavel que vai receber os argumentos. 
    va_list args;
    
    // inicializa a lista, count e a quantidade de argumentos
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        // pega o proximo arguemnto na lista
        int next = va_arg(args, int);
        if (next < min ) {
            min = next;
        };
    };
    
    // limpa a lista
    va_end(args);
    
    return min;
}

int max(int count,...) {
    int max = MIN_ELEMENT;
    // declara a variavel que vai receber os argumentos. 
    va_list args;
    
    // inicializa a lista, count e a quantidade de argumentos
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        // pega o proximo argumento na lista
        int next = va_arg(args, int);
        if (next > max ) {
            max = next;
        };
    };
    
    // limpa a lista
    va_end(args);
    
    return max;
}

int main() {
    int a = 10, b = 20, c = 5, d = 100;

    printf("Sum: %d\n", sum(4, a, b, c, d));
    printf("Min: %d\n", min(4, a, b, d));
    printf("Max: %d\n", max(4, c, d));

    // Teste com outros valores
    printf("Sum: %d\n", sum(3, 7, 2, 9));
    printf("Min: %d\n", min(3, 7, 2, 9));
    printf("Max: %d\n", max(3, 7, 2, 9));

    return 0;
};