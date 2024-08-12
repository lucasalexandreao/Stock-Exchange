#include <iostream>
#include "Date.h"
#include "Color.h"
#include "Text.h"
#include "Stock.h"

// "using namespace std;" não foi utilizado para evitar conflito com a struct data

int arredondar(float); // Protótipo da função arredondar()

int main()
{
	int quantidade_empresas;

	// ### CARTEIRA DE AÇÕES ###
	texto_colorido(" Carteira de Ações ", preto, laranja);
	std::cout << std::endl << std::endl;

	// Definição da quantidade de empresas
	texto_colorido("Quantidade de empresas [ ]\b\b", bege, preto);
	std::cin >> quantidade_empresas;

	// Criação de um vetor dinâmico de empresas
	empresa* vetor_empresas = new empresa[quantidade_empresas];
	
	desenhar_linha('-', 27, laranja, preto);
	
	// Realiza o cadastro de cada empresa 
	for (int i = 0; i < quantidade_empresas; i++)
	{
		vetor_empresas[i] = cadastrar_empresa(); // Recebe os dados da empresa
		vetor_empresas[i].vetor_transacoes = new transacao[vetor_empresas[i].quantidade_transacoes]; // Cria um vetor dinâmico de transações da empresa
	}

	std::cout << std::endl << std::endl;

	// ### TRANSAÇÕES REALIZADAS ###
	texto_colorido(" Transações Realizadas ", preto, laranja);
	std::cout << std::endl << std::endl;

	// Realiza o cadastro de cada transação em cada empresa
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

	// Criação dos vetores estáticos
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

	// Cálculo de normalização do vetor de acumulado e atribuição dos valores no vetor do gráfico
	for (int i = 0; i < tamanho_vetor_estatico; i++) 
	{
		vetor_grafico[i] = arredondar(vetor_acumulado[i] / vetor_acumulado[tamanho_vetor_estatico - 1] * tamanho_vetor_estatico);
	}

	std::cout << std::endl;

	// ### RENTABILIDADE DA CARTEIRA ###
	tabela_rentabilidade(tamanho_vetor_estatico, vetor_investido, vetor_rendimento, vetor_acumulado, vetor_grafico); // Exibe a tabela de rentabilidade com todos os valores e o gráfico


	// Liberação de memória alocada dinamicamente
	for (int i = 0; i < quantidade_empresas; i++)
	{
		delete[] vetor_empresas[i].vetor_transacoes;
	}
	delete[] vetor_empresas;

	return 0;
}


/* Na função arrendondar(), caso o número possua parte fracionária, 
   é adicionado 1 na parte inteira, e é retornada apenas a parte inteira do número.
   Caso contrário, apenas retorna o número como inteiro */

int arredondar(float numero) 
{
	if (numero == int(numero))
		return numero;
	else
		return int(numero) + 1;
}