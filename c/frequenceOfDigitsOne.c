#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int singleCharToInt(char c) {
    return  c - '0'; 
    /* fazer subtracao de chars retorna um int (pega o valor ascii dos chars e 
    subtrai), funciona aqui porque ascii de '0' = 48, ascii de '1' (exemplo) = 49
    '1' - '0' = 1 (int) */
};

int main() {
    int* arr = (int *) calloc(10, sizeof(int));
     
    char s[1001];
    scanf("%[^\n]%*c", s); // le todos os caracteres ate \n e adiciona '\0' no fim
    
    for (int i = 0; s[i] != '\0'; i++) {
        int num = s[i] - '0';
        if (-1 < num && num < 10) {
            arr[num] += 1;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%i ", arr[i]);
    };

    return 0;

}
