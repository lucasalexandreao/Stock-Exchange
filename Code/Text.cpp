#include <iostream>
#include <cstring>
#include "Text.h"

// Gera uma linha de caracteres coloridos
void desenhar_linha(char caractere, int tamanho, color cor_texto, color cor_fundo)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	for (int i = 0; i < tamanho; i++) 
	{
		std::cout << caractere;
	}
	std::cout << "\033[m"; // reseta a cor
	std::cout << std::endl;
}

// Torna maiúsculo todos os caracteres de um texto
void maiusculo(char texto[])
{
	for (int i = 0; i < strlen(texto); i++) // percorre cada caractere do texto
	{ 
		if (texto[i] >= 97 && texto[i] <= 122) // verifica se o caractere é uma letra minúscula
			texto[i] = texto[i] - 32; // modifica o caractere para a versão maiúscula da letra
	}
}


// Exibe texto colorido
void texto_colorido(const char texto[], color cor_texto, color cor_fundo)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	std::cout << texto;

	std::cout << "\033[m"; // Reseta a cor padrão
}


// Exibe texto colorido e alinhado
void texto_alinhado_colorido(const char texto[], color cor_texto, color cor_fundo, int espaco)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	std::cout.width(espaco);
	std::cout << texto;

	std::cout << "\033[m"; // Reseta a cor padrão
}

// Exibe um inteiro colorido alinhado
void texto_alinhado_colorido(int numero, color cor_texto, color cor_fundo, int espaco)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	std::cout.width(espaco);
	std::cout << numero;

	std::cout << "\033[m"; // Reseta a cor padrão
}


// Exibe um ponto flutuante float colorido e alinhado
void texto_alinhado_colorido(float numero, color cor_texto, color cor_fundo, int espaco)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	std::cout.width(espaco);
	std::cout << std::fixed; std::cout.precision(2); // Ajusta a exibição para 2 casas decimais
	std::cout << numero;

	std::cout << "\033[m"; // Reseta a cor padrão
}

// Exibe um ponto flutuante double colorido e alinhado
void texto_alinhado_colorido(double numero, color cor_texto, color cor_fundo, int espaco)
{
	std::cout << "\033[38;5;" << cor_texto << "m"; // altera a cor do texto 
	std::cout << "\033[48;5;" << cor_fundo << "m"; // altera a cor do fundo

	std::cout.width(espaco);
	std::cout << std::fixed; std::cout.precision(2); // Ajusta a exibição para 2 cassas decimais
	std::cout << numero;

	std::cout << "\033[m"; // Reseta a cor padrão
}

// Gera uma uma certa quantidade de espaços numa linha
void espacos(int quantidade_caracteres)
{
	for (int i = 0; i < quantidade_caracteres; i++)
		std::cout << ' ';
}