#pragma once
#include "std.h"

using namespace std;
using namespace Math;

class Grafico;

class Ente {
protected:
	Coordenadaf posicao;
	Coordenadaf tamanho;

public:
	static Grafico* pGrafico;
	sf::RectangleShape corpo;
	sf::Sprite sprite;
	sf::Texture imagem;

	Ente();
	~Ente();
	void setImagem(string arquivo);
	void setPosicao(Coordenadaf posicao);
	Coordenadaf getPosicao();
	void setTamanho(Coordenadaf tamanho);
	Coordenadaf getTamanho();
	void imprimir();
	void setCor(float x, float y, float z);

	
};