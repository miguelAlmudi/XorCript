#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void xorCryptAlternative2(char* entrada, char* saida, char* senha) {
    int tamIn = strlen(entrada);
    int tamSenha = strlen(senha);
    int j = 0;

    for (int i = 0; i < tamIn; i++) {
        if (j == tamSenha) {
            j = 0;
        }

        int bitEntrada = entrada[i] - '0';
        int bitSenha = senha[j] - '0';

        saida[i] = (bitEntrada ^ bitSenha) + '0';
        j++;
    }
    saida[tamIn] = '\0';
}



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
            //strcat(output, " "); // Espaço opcional entre os bytes 
        }
}

void binaryToString(char *input, char *output) {
    int len = strlen(input);
    int outputIndex = 0; // Itera sobre a string de entrada em grupos de 8 bits
    for (int i = 0; i < len; i += 8) {
        char byte[9];
        strncpy(byte, &input[i], 8);
        byte[8] = '\0';

        // Converte o byte binário para um caractere ASCII
        char character = (char) strtol(byte, NULL, 2);
        output[outputIndex++] = character;
        }
        
        // Adiciona o terminador de string
        output[outputIndex] = '\0'; 
}


int main(){

    char input[256]; // Buffer para armazenar a string de entrada    
    char password[256]; // Buffer para armazenar a senha
    char inputBin[2048];
    char passwordBin[2048];
    char outputBin[2048];
    
     printf("Digite uma string: ");
     scanf("%255s", input); // Recebe a string do teclado
     printf("Digite uma senha: ");
     scanf("%255s", password); // Recebe a senha do teclado
     
    
    stringToBinary(input, inputBin);
    stringToBinary(password, passwordBin);

    xorCryptAlternative2(inputBin, outputBin, passwordBin); // Aplica a criptografia

    printf("Binario entrada3:    %s\n", inputBin);
    printf("Binario senha3:      %s\n", passwordBin);
    printf("Saida Xor3:          %s\n", outputBin);

    
    printf("-----------------------\n");


    char decryptedBin[2048];
    char decrypted[256];
    xorCryptAlternative2(outputBin, decryptedBin, passwordBin);
    binaryToString(decryptedBin, decrypted);
    printf("Binario descript:    %s\n", decryptedBin);
    printf("Descript:            %s\n", decrypted);
    


    return 0;
}