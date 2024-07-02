/*
	Name: contaDeBanco.c
	Author: Gustavo Silva Souza
	Date: 20/03/24 10:32
	Description: programa que acessa a conta de um banco. Ap�s esse acesso, o usu�rio passa a ter acesso a seu saldo, dep�sitos, saques e trocas de senha
*/



//se��o de bibliotecas
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>



//se��o de structs
typedef struct
{
	char  login[20];
	char  password[10];
	float balance;
} User;

User user;



//se��o de prototipa��o
void receberLogin(User *);
void verificarLogin(User *);
void receberSenha(User *);
void verificarSenha(User *);
void telaDeLogin(User *);
void verSaldo(User *);
void sacar(User *);
void depositar(User *);
void trocarSenha(User *);



//se��o de vari�veis globais
char login[12]    = "a@gmail.com";
char password[10] = "123456789";  



//fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	puts("SISTEMA DE LOGIN\n\n");
	receberLogin(&user);
}



//se��o de fun��es
void receberLogin(User *user)
{
	printf("Login: ");
	scanf(" %s", user -> login);
	verificarLogin(user);
}

void verificarLogin(User *user)
{
	if(strcmp(user -> login, login) == 0)
		receberSenha(user);
	else
	{
		puts("\n-----------------------------");
		puts("Login inv�lido");
		puts("-----------------------------\n\n");
		receberLogin(user);
	}
}

void receberSenha(User *user)
{
	printf("Senha: ");
	scanf(" %s", user -> password);
	verificarSenha(user);
}

void verificarSenha(User *user)
{
	if(strcmp(user -> password, password) == 0)
		telaDeLogin(user);
	else
	{
		puts("\n-----------------------------");
		puts("Senha inv�lida");
		puts("-----------------------------\n\n");
		receberSenha(user);
	}
}

void telaDeLogin(User *user)
{	
	unsigned short opcao = 0;
	
	while(true)
	{
		system("cls");
		
		printf("C:\\user\\%s\n\n", user -> login);
		
		puts("(1) Ver saldo");
		puts("(2) Sacar");
		puts("(3) Depositar");
		puts("(4) Trocar senha");
		puts("(5) Sair\n");
		
		printf("Op��o: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				verSaldo(user);
				break;
				
			case 2:
				sacar(user);
				break;
				
			case 3:
				depositar(user);
				break;
				
			case 4:
				trocarSenha(user);
				break;
			
			case 5:
				strcpy(user -> login, "");
				strcpy(user -> password, "");
				user -> balance = 0.00;
				
				puts("\nVoc� ser� desconectado");
				system("pause");
				
				system("cls");
				main();
				break;
				
			default:
				puts("\nOp��o inv�lida");
				system("pause");
				break;
		}
	}
}

void verSaldo(User *user)
{
	printf("\nSaldo: %.2f\n", user -> balance);
	system("pause");
//	telaDeLogin(user);
}

void sacar(User *user)
{
	float saque = 0.00;
	
	printf("\nValor: ");
	scanf("%f", &saque);
	
	if(saque > user -> balance)
	{
		puts("Voc� n�o tem saldo o suficiente para fazer esse saque!");
	}
	else if(saque <= 0)
		puts("Valor inv�lido!");
	else
	{
		user -> balance -= saque;
		puts("Saque efetuado com sucesso!");
	}
	
	system("pause");
//	telaDeLogin(user);
}

void depositar(User *user)
{
	float deposito = 0.00;
	
	printf("\nValor: ");
	scanf("%f", &deposito);
	
	if(deposito <= 0)
		puts("Valor inv�lido!");
	else
	{
		user -> balance += deposito;
		puts("Dep�sito efetuado com sucesso!");	
	}
	
	system("pause");
//	telaDeLogin(user);
}

void trocarSenha(User *user)
{
	char  senha1[20];
	char  senha2[20];
	short opcao = 0;
	
	printf("\nDigite sua senha atual: ");
	scanf(" %s", senha1);
	
	if(strcmp(senha1, user -> password) != 0)
	{
		puts("Acesso negado!");
		system("pause");
		telaDeLogin(user);	
	}
	else
	{
		printf("\nNova senha: ");
		scanf(" %s", senha1);
		
		printf("\nDigite sua nova senha novamente: ");
		scanf(" %s", senha2);
		
		if(strcmp(senha1, senha2) == 0)
		{
			strcpy(user -> password, senha1);
			puts("Senha alterada com sucesso!\n");
			system("pause");
			telaDeLogin(user);
		}
		else
		{
			puts("\nAs senhas digitadas s�o diferentes! Escolha uma das op��es abaixo:\n");
			
			while(true)
			{
				puts("(1) Tentar novamente");
				puts("(2) Desistir");
				
				printf("\nOp��o: ");
				scanf("%d", &opcao);
				
				switch(opcao)
				{
					case 1:
						puts("\n-----------------------------\n");
						trocarSenha(user);
						break;
						
					case 2:
						telaDeLogin(user);
						break;
						
					default:
						puts("Valor inv�lido!\n");
						system("pause");
						break;
				}	
			}
		}
	}
}
