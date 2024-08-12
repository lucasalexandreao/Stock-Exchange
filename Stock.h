#pragma once
#include "Date.h"

// Registro transacao
struct transacao
{
	data data_transacao;
	int quantidade_acoes_compradas;
	float preco_por_acao;
};

// Registro empresa
struct empresa
{
	char nome[20];
	char codigo[6]; // Assumi que o código sempre tem 5 caracteres e um '\0'
	int quantidade_transacoes;
	transacao* vetor_transacoes;
};

// Protótipos das funções
empresa cadastrar_empresa();
void cadastrar_transacoes(int, empresa*);
double resumo_carteira(empresa[], int);
void tabela_rentabilidade(int, double[], double[], double[], int[]);