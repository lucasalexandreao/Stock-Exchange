#pragma once
#include <iostream>

// registro data
struct data
{
	int dia;
	int mes;
	int ano;
};

// protótipos das funções que permitem o cout e o cin funcionarem com o tipo data
std::istream& operator>>(std::istream&, data&);
std::ostream& operator<<(std::ostream&, data&);