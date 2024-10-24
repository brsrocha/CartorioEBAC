#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�oo em mem�ria
#include <locale.h> //biblioteca de aloca��s de texto por regi�o
#include <string.h> //biblioteca de strings

// programa criado por brsrochapi

int registro() //Fun��o de registro dos usuarios no sistema
{
	
	//in�cio cria��o de vari�veis
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];  
	//final da cria��o de vari�veis 
    
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" = escrever
	fprintf(file,cpf); //salvo o valor da variavel dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file =fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n" );
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}

	system("pause");
	fclose(file);
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");	
	}
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	int opcao=0; //definindo as variaveis
	
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("###Cart�rio da EBAC### \n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
		
			system("cls"); //respons�vel por limpar a tela
	
			printf("###Cart�rio da EBAC### \n\n");
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Fechar Programa\n\n");
			printf("Op��o:\n"); //fim do menu
		
			scanf("%d", &opcao); //armazenamento da escolha do usu�rio
	
			system("cls");
		
			switch(opcao) //inicio do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				system("pause");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel\n");
				system("pause");
				break;
			}
		}
	}
	else
	printf("Senha incorreta!\n");
	system("pause");
	
}
	

