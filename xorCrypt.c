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

void binToHex(char *bin, char *hex) {
	int len = strlen(bin);
	int value = 0;
	for (int i = 0; i < len; i++) {
		value = (value << 1) + (bin[i] - '0');
			if ((i + 1) % 4 == 0) {
				snprintf(hex + (i / 4), 2, "%X", value);
				value = 0; 
			}
	} hex[len / 4] = '\0';
}

void hexToBin(char *hex, char *bin) {
	char *lookup[] = {"0000", "0001", "0010", "0011",
					  "0100", "0101", "0110", "0111",
					  "1000", "1001", "1010", "1011",
					  "1100", "1101", "1110", "1111"};
  
    int len = strlen(hex);
	bin[0] = '\0'; // Inicializa a string binária como vazia
	
	for (int i = 0; i < len; i++) {
		
		if (hex[i] >= '0' && hex[i] <= '9') {
			strcat(bin, lookup[hex[i] - '0']);
		} 
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			strcat(bin, lookup[hex[i] - 'A' + 10]);
		} 
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			strcat(bin, lookup[hex[i] - 'a' + 10]);
		} 
		else { 
		// Caractere inválido 
		printf("Caractere hexadecimal inválido: %c\n", hex[i]);
		return;
		}
	} 
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

	int TAM1 = 8191;
	int TAM2 = 65535;
    char input[TAM1]; // Buffer para armazenar a string de entrada    
    char password[TAM1]; // Buffer para armazenar a senha
    char inputBin[TAM2];
    char passwordBin[TAM2];
    char outputBin[TAM2];
    char decryptedBin[TAM2];
    char decrypted[TAM1];
    int selec = 1; 
	char stringHex[TAM2];
	char stringBin[TAM2];
	char stringNote[TAM2];
	
	    	
	 while(selec == 1 || selec == 2 || selec == 3 || selec == 4 || selec == 5 || selec == 6){
	 
		 printf("Selecione um modo: 1 - Criptografar; 2 - Descriptografar; 3 - BinToHex Converter; 4 - HexToBin Converter; 5 - Anotar String \n");
		 
		 scanf("%d", &selec);
		 printf("\n");
		 
		 if(selec == 1){
			 printf("Digite uma string: ");
			 scanf("%8190s", input); // Recebe a string do teclado
			 printf("Digite uma senha: ");
			 scanf("%8190s", password); // Recebe a senha do teclado
			 
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
			 scanf("%8190s", inputBin); // Recebe a string do teclado sempre igual a TAM1-1
			 printf("Digite sua senha: ");
			 scanf("%8190s", password); // Recebe a senha do teclado
			 			 
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
		 
		 if(selec == 3){
			 printf("---------------------------------------------------\n");
			 printf("Binario Para Hexa: \n");
			 printf("Insira o codigo Binario: \n");
			 scanf("%8190s", stringBin);
			 printf("---------------------------------------------------\n");
			 binToHex(stringBin, stringHex);
			 printf("%s\n", stringHex);
			 printf("---------------------------------------------------\n");
		 }
		 
		 if(selec == 4){
			 printf("---------------------------------------------------\n");
			 printf("Hexa Para Binario: \n");
			 printf("Insira o codigo Hexa: \n");
			 scanf("%8190s", stringHex);
			 printf("---------------------------------------------------\n");
			 hexToBin(stringHex, stringBin);
			 printf("%s\n", stringBin);
			 printf("---------------------------------------------------\n");
		 }
		 
		 if(selec == 5){
			 printf("---------------------------------------------------\n");
			 printf("Insira o binario ou hexa para anotar: \n");
			 scanf("%8190s", stringNote);
			 printf("---------------------------------------------------\n");
			 int tam = strlen(stringNote);
			 int j = 0;
			 for(int i = 0; i < tam; i++){
				j++;
				printf("%c", stringNote[i]);
				if(j == 4){
					printf("\n");
					j = 0;
				}
			 }
			 printf("\n");
		 }
		 if(selec == 6){system("cls");}
	 
	}

    return 0;
}
	 