#pragma once
#include "std.h"
#include "entidade.h"

using namespace std;

class Botao : public Entidade {
private:
	bool selecionado;

public:
	sf::Text texto;

	Botao();
	Botao(string arquivo, string string, int tamanho);
	~Botao();
	void imprime();
	void setFonte(string arquivo);
	void setPosicao(Coordenadaf posicao);
	void setString(string string);
	string getString();

};