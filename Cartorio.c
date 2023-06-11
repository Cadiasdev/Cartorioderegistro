#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro() //responsavel por cadastrar os usuários no sistema
{
	// inicio criação de varíaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de varíavel/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo 
	fprintf(file,","); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta os dados do usuário 
	scanf("%s",nome); // "%s" refere-se as string
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo
	fprintf(file,","); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta os dados do usuário 
	scanf("%s",sobrenome); // "%s" refere-se as string
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo
	fprintf(file,sobrenome); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo
	fprintf(file,","); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta os dados do usuário 
	scanf("%s", cargo); // "%s" refere-se as string
	
	file = fopen(arquivo, "a"); // abre e cria o arquivo
	fprintf(file, cargo); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	system("pause"); // pausa a execução do programa
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo o indioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coleta os dados do usuário 
	scanf("%s",cpf); // "%s" refere-se as string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(cpf, "r"); //abre e cria o arquivo
	
	if(file == NULL) //verifica se o arquivo é nulo
	{
		printf("Não foi possivel localizar o arquivo, tente novamente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //ler o arquivo
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa a execução do programa
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que queira deleta: ");
	scanf("%s", cpf);
	
	remove(cpf); //permite remover o arquivo
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //verifica se o arquivo é nulo
	{
		printf("usuario '%s' não se encotra no sistema!\n ", cpf);
		system("pause");
	}
	return 0;
}

int main()
{
	int opcao=0; //Definindo as variaveis
	int x=1;
	
	for(x=1;x=1;) // controle de repetição
	{
		system("cls"); // responsavel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo as linguagens
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Resgistrar nomes\n");	
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n"); 
		printf("\t4 - Fechar programa\n");
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); // Armazenameto e escolha da variavel
	
		system("cls");
		
		switch(opcao) //Inicio de seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
        		printf("Você escolheu a opção fechar programa. Até a proxima.\n\n");
        		return 0;
       	 		break;
			
			default:
			printf("Essa opção não está disponivel tente novamente\n");
			system("pause");
			break;
			//fim da seleçõa
		}
	
	}
}
