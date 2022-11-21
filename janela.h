#pragma once
#include "std.h"

class Janela {
private:
	int largura;
	int altura;

public:
	sf::RenderWindow janela;

	Janela(int largura, int altura);
	~Janela();
	int getLargura();
	int getAltura();

};