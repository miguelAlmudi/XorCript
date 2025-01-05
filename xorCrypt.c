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

	int TAM1 = 4096;
	int TAM2 = 32767;
    char input[TAM1]; // Buffer para armazenar a string de entrada    
    char password[TAM1]; // Buffer para armazenar a senha
    char inputBin[TAM2];
    char passwordBin[TAM2];
    char outputBin[TAM2];
    char decryptedBin[TAM2];
    char decrypted[TAM1];
    int selec = 1; 

    	
	 while(selec == 1 || selec == 2){
	 
		 printf("Selecione um modo: 1 - Criptografar; 2 - Descriptografar \n");
		 
		 scanf("%d", &selec);
		 printf("\n");
		 
		 if(selec == 1){
			 printf("Digite uma string: ");
			 scanf("%255s", input); // Recebe a string do teclado
			 printf("Digite uma senha: ");
			 scanf("%255s", password); // Recebe a senha do teclado
			 
			 stringToBinary(input, inputBin);
			 stringToBinary(password, passwordBin);

			xorCryptAlternative2(inputBin, outputBin, passwordBin); // Aplica a criptografia
			
			printf("---------------------------------------------------\n");
			printf("Binario entrada:\n");
			printf("%s\n", inputBin);
			printf("---------------------------------------------------\n");
			printf("Binario senha:\n");
			printf("%s\n", passwordBin);
			printf("---------------------------------------------------\n");
			printf("Saida Xor:\n");
			printf("---------------------------------------------------\n");
			printf("%s\n", outputBin);			
			printf("---------------------------------------------------\n");
		 }
		 
		 if(selec == 2){
			 
			 printf("Digite o Binario: ");
			 scanf("%4095s", inputBin); // Recebe a string do teclado sempre igual a TAM1-1
			 printf("Digite sua senha: ");
			 scanf("%4095s", password); // Recebe a senha do teclado
			 			 
			 stringToBinary(password, passwordBin);
			 
			xorCryptAlternative2(inputBin, decryptedBin, passwordBin);
			binaryToString(decryptedBin, decrypted);
			printf("---------------------------------------------------\n");
			printf("Binario descript:\n");
			printf("%s\n", decryptedBin);
			printf("---------------------------------------------------\n");
			printf("Descript:\n");
			printf("%s\n", decrypted);
			printf("---------------------------------------------------\n");
			
		 }
	 
	}

    return 0;
}
	 