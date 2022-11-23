#pragma once
#include "std.h"
#include "ente.h"
#include "janela.h"

class Grafico {
private:

	Janela* pJanela;
	sf::Clock clock;
	float dt;

	//singleton
	Grafico();
	Grafico(Janela* pJanela);
	static Grafico* instance;

public:

	static Grafico* getInstance();
	void setJanela(Janela* ptr);
	Janela* getJanela();
	~Grafico();
	void imprime(Ente* pEnte);
	void imprimeTexto(sf::Text* ptr);
	void clear();
	void display();
	const float getDt() const;
	float atualizaDt();
	void imprimeBackground();
};