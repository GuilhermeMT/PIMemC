#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para o uso de Strings em C
#include <locale.h> // Biblioteca necessária para o uso de caracteres especiais


// Função para realizar o login do usuário
int telalogin(){
	// Declaração das variáveis que receberam o login e a senha do usuário.a
	char user[20], pass[20];
	
	printf("Digite o nome do usuário: ");
	gets(user);
	printf("Digite a senha do usuário: ");
	gets(pass);
	
	// A função strcmp() compara duas Strings, retornar 0 quando elas são identicas e -1 quando são diferentes
	if(strcmp("admin", user) != 0){
		// Vericar se o login inserido é "admin"
		printf("Usuário não encontrado!\n");
	    return 0;
	}
	else if(strcmp("admin", pass) != 0){
		// Vericar se a senha inserida é "admin"
		printf("\nUsuário não encontrado!\n");
		return 0;
	}
	else{
		printf("\nAcesso concedido!");
	}
	
	return 1;
}

// Função para a tela principal



// Função principal
int main(void){
	// Permite o uso de caracteres especiais
	setlocale(LC_ALL, "PT-BR");
	int validar = 0;
	
	// Laço que repete a solicitação de login e senha até que dados válidos sejam inseridos
	do{
		validar = telalogin();
	}while(validar == 0);
	
	
	system("pause");
	return 0;
}


