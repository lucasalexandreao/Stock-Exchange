#include <iostream>
#include "Date.h"
#include "Color.h"
#include "Text.h"
#include "Stock.h"

// "using namespace std;" n�o foi utilizado para evitar conflito com a struct data

int arredondar(float); // Prot�tipo da fun��o arredondar()

int main()
{
	int quantidade_empresas;

	// ### CARTEIRA DE A��ES ###
	texto_colorido(" Carteira de A��es ", preto, laranja);
	std::cout << std::endl << std::endl;

	// Defini��o da quantidade de empresas
	texto_colorido("Quantidade de empresas [ ]\b\b", bege, preto);
	std::cin >> quantidade_empresas;

	// Cria��o de um vetor din�mico de empresas
	empresa* vetor_empresas = new empresa[quantidade_empresas];
	
	desenhar_linha('-', 27, laranja, preto);
	
	// Realiza o cadastro de cada empresa 
	for (int i = 0; i < quantidade_empresas; i++)
	{
		vetor_empresas[i] = cadastrar_empresa(); // Recebe os dados da empresa
		vetor_empresas[i].vetor_transacoes = new transacao[vetor_empresas[i].quantidade_transacoes]; // Cria um vetor din�mico de transa��es da empresa
	}

	std::cout << std::endl << std::endl;

	// ### TRANSA��ES REALIZADAS ###
	texto_colorido(" Transa��es Realizadas ", preto, laranja);
	std::cout << std::endl << std::endl;

	// Realiza o cadastro de cada transa��o em cada empresa
	for (int i = 0; i < quantidade_empresas; i++)
	{
		texto_colorido(vetor_empresas[i].nome, laranja, preto);
		texto_colorido(" - ", laranja, preto);
		texto_colorido(vetor_empresas[i].codigo, laranja, preto);
		texto_colorido(": ", laranja, preto);
		std::cout << std::endl << std::endl;

		cadastrar_transacoes(vetor_empresas[i].quantidade_transacoes, (vetor_empresas + i));
		std::cout << std::endl;
	}

	// ### RESUMO DA CARTEIRA ###
	double total_investido = resumo_carteira(vetor_empresas, quantidade_empresas); // Exibe o resumo da carteira e retorna o total investido
	std::cout << std::endl;

	// Recebe o valor do aporte anual
	texto_colorido("Aporte anual R$[    ]\b\b\b\b\b", bege, preto);
	double aporte;
	std::cin >> aporte;

	// Recebe o valor do rendimento anual
	texto_colorido("Rendimento anual estimado [  ]%\b\b\b\b", bege, preto);
	float rendimento;
	std::cin >> rendimento;

	const int tamanho_vetor_estatico = 21;

	// Cria��o dos vetores est�ticos
	double vetor_investido[tamanho_vetor_estatico] = { total_investido };
	double vetor_rendimento[tamanho_vetor_estatico] = { 0.00 };
	double vetor_acumulado[tamanho_vetor_estatico] = { total_investido };
	int vetor_grafico[tamanho_vetor_estatico] = {0}; // Corresponde ao vetor normalizado

	// Calcula os valores de investido, rendimento e acumulado, e armazena-os nos vetores
	for (int i = 1; i < tamanho_vetor_estatico; i++)
	{
		vetor_investido[i] = vetor_investido[i - 1] + aporte;
		vetor_rendimento[i] = (vetor_acumulado[i - 1] + aporte) * (rendimento / 100);
		vetor_acumulado[i] = vetor_acumulado[i - 1] + aporte + vetor_rendimento[i];
	}

	// C�lculo de normaliza��o do vetor de acumulado e atribui��o dos valores no vetor do gr�fico
	for (int i = 0; i < tamanho_vetor_estatico; i++) 
	{
		vetor_grafico[i] = arredondar(vetor_acumulado[i] / vetor_acumulado[tamanho_vetor_estatico - 1] * tamanho_vetor_estatico);
	}

	std::cout << std::endl;

	// ### RENTABILIDADE DA CARTEIRA ###
	tabela_rentabilidade(tamanho_vetor_estatico, vetor_investido, vetor_rendimento, vetor_acumulado, vetor_grafico); // Exibe a tabela de rentabilidade com todos os valores e o gr�fico


	// Libera��o de mem�ria alocada dinamicamente
	for (int i = 0; i < quantidade_empresas; i++)
	{
		delete[] vetor_empresas[i].vetor_transacoes;
	}
	delete[] vetor_empresas;

	return 0;
}


/* Na fun��o arrendondar(), caso o n�mero possua parte fracion�ria, 
   � adicionado 1 na parte inteira, e � retornada apenas a parte inteira do n�mero.
   Caso contr�rio, apenas retorna o n�mero como inteiro */

int arredondar(float numero) 
{
	if (numero == int(numero))
		return numero;
	else
		return int(numero) + 1;
}