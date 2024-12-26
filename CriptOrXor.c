#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void orCriptAlternative(char* entrada, char* saida, char* senha) {
    int tamIn = strlen(entrada);
    int tamSenha = strlen(senha);

    for(int i = 0; i < tamIn; i++) {
        saida[i] = entrada[i] | senha[i % tamSenha];
    } saida[tamIn] = '\0'; // Adiciona terminador de string

}



void orCript(char* entrada, char* saida, char* senha){

    int tamIn = strlen(entrada);
    int tamSenha = strlen(senha);
    int j = 0;

    for(int i = 0; i < tamIn; i++) {
        if(j == tamSenha) {
            j = 0;
        }
        saida[i] = entrada[i] | senha[j];
        j++;          
    } 
    saida[tamIn] = '\0'; // Adiciona terminador de string

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


int main(){

    char input[256]; // Buffer para armazenar a string de entrada
    char output[2048]; // Certifique-se de que o tamanho seja suficiente
    char encrypted[256]; // Buffer para armazenar a string criptografada
    char password[256]; // Buffer para armazenar a senha
    
     printf("Digite uma string: ");
     scanf("%255s", input); // Recebe a string do teclado
     printf("Digite uma senha: ");
     scanf("%255s", password); // Recebe a senha do teclado
     
     orCript(input, encrypted, password); // Aplica a criptografia
     stringToBinary(encrypted, output); // Converte a string criptografada para binário
     
     printf("String: %s\n", input);
     printf("Senha: %s\n", password);
     printf("Criptografado: %s\n", encrypted);
     printf("Binário: %s\n", output);   


    return 0;
}