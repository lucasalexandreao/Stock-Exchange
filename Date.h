#pragma once
#include <iostream>

// registro data
struct data
{
	int dia;
	int mes;
	int ano;
};

// prot�tipos das fun��es que permitem o cout e o cin funcionarem com o tipo data
std::istream& operator>>(std::istream&, data&);
std::ostream& operator<<(std::ostream&, data&);