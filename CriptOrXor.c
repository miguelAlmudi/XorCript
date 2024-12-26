#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringToBinary(char *input, char *output) {
    
    int i, j; 
    char bin[9];
    output[0] = '\0'; // Inicializa a string de saída
        for(i = 0; i < strlen(input); i++) {
            unsigned char ch = input[i];
            for(j = 7; j >= 0; j--) {
                bin[7-j] = (ch & (1 << j)) ? '1' : '0';
            } 
            bin[8] = '\0';
            strcat(output, bin);
            strcat(output, " "); // Espaço opcional entre os bytes 
        }
}


int main(){

    char input[256]; // Buffer para armazenar a string de entrada
    char output[2048]; // Certifique-se de que o tamanho seja suficiente

    printf("Digite uma string: ");    
    scanf("%255s", input); // Recebe a string do teclado 

    stringToBinary(input, output);

    printf("String: %s\n", input);
    printf("Binário: %s\n", output);


    return 0;
}