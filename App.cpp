#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para o uso de Strings em C
#include <locale.h> // Biblioteca necessária para o uso de caracteres especiais


// Função para realizar o login do usuário
int telalogin(){
	// Declaração das variáveis que receberam o login e a senha do usuário.a
	char user[20], pass[20], linha[100], *result;
	char *login, *senha;
	FILE *arq;
	
	// Recebendo os dados de acesso do usuário (login e senha)
	printf("Digite o nome do usuario: ");
	gets(user);
	printf("Digite a senha do usuario: ");
	gets(pass);
	
	// Recebendo no ponteiro arq o local onde os registros de logins e senhas autorizados estão armazenados
	arq = fopen("arquivos/logins.txt", "rt");
	
	// Verificando se deu erro na abertua do arquivo (retorna NULL se der erro na leitura)
	if (arq == NULL)
	{
	    printf("Problemas na LEITURA do arquivo\n");
	}

	// Correndo todas as linhas do arquivo até que chegue ao final
	while(!feof(arq)){
		
		//fgets(nome do vetor onde salvaremos a String lida, a quantidade de caracteres a ser lidos, de onde será lido)
		fgets(linha, 41, arq);
		
		//a função strtok() é utilizanda para separar Strings
		login = strtok(linha,",");
		senha = strtok(NULL,"\n");
		
		/*
		printf("login lido: %s \n", login);
		printf("senha lida: %s \n", senha);
		*/
		
		// Comparando os dados de login e senha informados pelo usuário com os dados salvos no arquivo logins.txt
		if(strcmp(login, user) == 0 && strcmp(senha, pass) == 0){
			
			printf("Acesso concedido!\n");
			return 1;
		}
		
	}
	printf("Login ou senha invalido!\n");
	return 0;
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


