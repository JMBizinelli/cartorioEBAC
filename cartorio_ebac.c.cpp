#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h> //biblioteco responsavel por cuidar do string
					// string é conjunto de variaveis

int registrar() //função responsavel pro registrqr os usuários no sistema
{
	//inico da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//inico da criação de variáveis/string
	
	printf("Digite o CPF que deseja cadastrar: \n");
	scanf("%s", cpf); //%s refere-se a string/rmazena na string
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo no banco de dados 
	file = fopen(arquivo, "w");  // cria o arquivo no banco de dados // "W" = write
	fprintf(file,"CPF:");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file);  // fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNOME:");
	fclose(file);
	
	printf("Digite o nome que deseja cadastrar: \n");
	scanf("%s",nome); //"%s" usado para armazenar na string "nome"
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME:");
	fclose(file);
	
	printf("Digite o sobrenome que deseja cadastrar: \n");
	scanf("%s",sobrenome); //"%s" usado para armazenar na string "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCARGO:");
	fclose(file);
	
	printf("Digite o cargo que deseja cadastrar: \n");
	scanf("%s", cargo); //"%s" usado para armazenar na string "cargo"
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, "\n");
	fclose(file);
	
	system("pause");

}

int consultar()
{	
	setlocale(LC_ALL, "Portuguese");  //definição de linguagem
	
	char cpf[40];   //char = variavel
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar:");
	scanf("%s",cpf);  //"%s" usado para armazenar na string "cpf"
	
	system("cls"); //limpa atela do usuário 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo for igual a nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");	
	}
	
	printf("\nEssas são as informações do usuário:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto arquivo for diferente de nulo 
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	fclose(file); //ficha o arquivo 
}


int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	
	char cpf[40];
	
	printf("Digite o CPF do Usuário a ser deletado: ");
	scanf("%s",cpf); //scanf salva o valor na variavel
	
	
	FILE *file;   //FILE = biblioteca //file = arquivo "puxado" da biblioteca
	file = fopen(cpf,"r");  //fopem abre a pasta e procura o arquivo // r de read
	fclose(file);
	
	system("cls");
	
	if(file == NULL)  // = se o arquivo for igual a nulo 
	{
		printf("O usuário não foi encontrado no sistema! \n");
		system("pause");
	}
	
	if(file != NULL) //se o arquivo for diferente de nulo
	{
		remove(cpf);
		printf("Usuário deletado com sucesso! \n");
		system("pause");
	}
}

	


int main()
	{
		
	int opcao=0;   //definição de variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");  //definição de linguagem
	
		printf("### cartório da EBAC ###\n\n");    //inicio do menu 
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes.\n");
		printf("\t2 - Consultar nomes.\n");
		printf("\t3 - Deletar nomes.\n");    //final do menu 
		printf("Opção:");
		
		scanf("%d", &opcao);   //armazendo a escolha do usuario 
	
		system("cls");  //cls serve para limpar a tela apos a escolha
		
		switch(opcao)   //inicio da seleção
		{
			case 1:
			registrar(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;   //final da seleção 
			               
		}
	
	}
}
