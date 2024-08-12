#include "Date.h"

// Permite que o cin leia algo do tipo data
std::istream& operator>>(std::istream& is, data& d)
{
	is >> d.dia;
	is.ignore();
	is >> d.mes;
	is.ignore();
	is >> d.ano;

	return is;
}

// Permite que o cout exiba algo do tipo data
std::ostream& operator<<(std::ostream& os, data& d)
{
	os << d.dia;
	os << '/';
	os << d.mes;
	os << '/';
	os << d.ano;

	return os;
}