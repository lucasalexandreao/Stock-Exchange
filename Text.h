#pragma once
#include "Color.h"

// Protótipos das funções de texto
void desenhar_linha(char, int, color, color);
void maiusculo(char[]);
void texto_colorido(const char[], color, color);
void texto_alinhado_colorido(const char[], color, color, int);
void texto_alinhado_colorido(int, color, color, int);
void texto_alinhado_colorido(float, color, color, int);
void texto_alinhado_colorido(double, color, color, int);
void espacos(int);