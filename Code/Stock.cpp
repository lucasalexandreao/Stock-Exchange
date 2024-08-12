#include <iostream>
#include "Text.h"
#include "Stock.h"

// Lê os dados de cadastro da empresa
empresa cadastrar_empresa()
{
	std::cin.get();
	empresa emp;

	// Recebe o nome da empresa
	texto_alinhado_colorido("Empresa: ", bege, preto, 9);
	std::cin.getline(emp.nome, 20);

	// Recebe o código da empresa
	std::cout << std::left;
	texto_alinhado_colorido("Ticker: ", bege, preto, 9);
	std::cin >> emp.codigo;
	maiusculo(emp.codigo);
	std::cout << std::right;

	// Recebe a quantidade de transações na empresa
	texto_colorido("Transações: ", bege, preto);
	std::cin >> emp.quantidade_transacoes;
	
	desenhar_linha('-', 27, laranja, preto);

	return emp;
}

// Lê os dados de transações da empresa
void cadastrar_transacoes(int quantidade_transacoes, empresa* emp)
{
	for (int i = 0; i < quantidade_transacoes; i++)
	{
		// Recebe a data da transação
		texto_colorido("Data: ", bege, preto);
		std::cin >> emp->vetor_transacoes[i].data_transacao;

		// Recebe a quantidade de ações compradas
		texto_colorido("Quantidade: ", bege, preto);
		std::cin >> emp->vetor_transacoes[i].quantidade_acoes_compradas;

		// Recebe o preço por ação
		texto_colorido("Preço: ", bege, preto);
		std::cin >> emp->vetor_transacoes[i].preco_por_acao;

		std::cout << std::endl;
	}
}

// Exibe o resumo da carteira e retorna o valor total investido
double resumo_carteira(empresa vetor_empresas[], int quantidade_empresas)
{
	// Centraliza o título
	texto_alinhado_colorido("Resumo d", preto, laranja, 34);
	std::cout << std::left;
	texto_alinhado_colorido("a Carteira", preto, laranja, 34);
	std::cout << std::right;
	std::cout << std::endl;

	desenhar_linha('-', 68, laranja, preto);

	// Linha de títulos dos campos da tabela
	texto_colorido(" Empresa ", preto, laranja);
	espacos(8);

	texto_colorido(" Ticker ", preto, laranja);
	espacos(5);

	texto_colorido(" Qtd. ", preto, laranja);
	espacos(4);

	texto_colorido(" Preço Médio ", preto, laranja);
	espacos(4);

	texto_colorido(" Investido ", preto, laranja);

	std::cout << std::endl;

	
	int quantidade_acoes_total;
	float preco_medio;
	double valor_investido;
	double total_investido = 0;

	for (int i = 0; i < quantidade_empresas; i++) // Permite acessar cada empresa
	{
		std::cout << std::left;
		texto_alinhado_colorido(vetor_empresas[i].nome, branco, preto, 17);
		std::cout << std::right;
		texto_alinhado_colorido(vetor_empresas[i].codigo, branco, preto, 6);

		quantidade_acoes_total = 0;
		preco_medio = 0;
		valor_investido = 0;

		for (int j = 0; j < vetor_empresas[i].quantidade_transacoes; j++) // Permite acessar cada transação da empresa
		{
			// Calcula a quantidade total de ações na empresa
			quantidade_acoes_total = quantidade_acoes_total + vetor_empresas[i].vetor_transacoes[j].quantidade_acoes_compradas;
			// Calcula o valor investido na empresa
			valor_investido = valor_investido + (vetor_empresas[i].vetor_transacoes[j].quantidade_acoes_compradas * vetor_empresas[i].vetor_transacoes[j].preco_por_acao);
		}
		
		preco_medio = valor_investido / quantidade_acoes_total; // Calcula o preço médio de ações na empresa

		total_investido = total_investido + valor_investido; // Calcula o valor total investido

		texto_alinhado_colorido(quantidade_acoes_total, branco, preto, 12);
		texto_alinhado_colorido(preco_medio, branco, preto, 14);
		texto_alinhado_colorido(valor_investido, branco, preto, 19);
		std::cout << std::endl;
	}

	// Linha final
	desenhar_linha('-', 68, laranja, preto);
	std::cout << std::left;
	texto_alinhado_colorido("Total Investido:", preto, laranja, 60);
	std::cout << std::right;
	texto_alinhado_colorido(total_investido, preto, laranja, 8);
	std::cout << std::endl;

	return total_investido; // Retorna o valor total investido
}

// Exibe a tabela de rentabilidade da carteira com os valores e o gráfico
void tabela_rentabilidade(int quantidade_anos, double investido[], double rendimento[], double acumulado[], int grafico[])
{
	// Centraliza o título
	texto_alinhado_colorido("Rentabilidade d", preto, laranja, 44);
	std::cout << std::left;
	texto_alinhado_colorido("a Carteira", preto, laranja, 45);
	std::cout << std::right;
	std::cout << std::endl;

	desenhar_linha('-', 89, laranja, preto);

	// Linha de títulos dos campos da tabela
	std::cout << std::right;
	texto_alinhado_colorido("Ano", preto, laranja, 4);
	texto_alinhado_colorido("Investido", preto, laranja, 11);
	texto_alinhado_colorido("Rendimento", preto, laranja, 12);
	texto_alinhado_colorido("Acumulado", preto, laranja, 12);
	texto_alinhado_colorido("Gráfico", preto, laranja, 32);
	desenhar_linha(' ', 18, preto, laranja);

	for (int i = 0; i < quantidade_anos; i++) // Percorre os anos e permite acessar os valores dos vetores estáticos
	{
		texto_alinhado_colorido(i, preto, laranja, 3);
		texto_colorido(" ", preto, laranja);
		texto_alinhado_colorido(investido[i], branco, preto, 11); // Exibe o valor de investido do ano
		texto_alinhado_colorido(rendimento[i], branco, preto, 12); // Exibe o valor de rendimento do ano
		texto_alinhado_colorido(acumulado[i], branco, preto, 12); // Exibe o valor de acumulado do ano
		espacos(8);
		
		// Cria uma linha do gráfico
		for (int j = 0; j < quantidade_anos; j++)
		{
			if (grafico[j] >= ((quantidade_anos)-i))
				texto_colorido("\376 ", laranja, preto);
			else
				std::cout << "  ";
		}
		
		std::cout << std::endl;
	}
	desenhar_linha('-', 89, laranja, preto);
}





