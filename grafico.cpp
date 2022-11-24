#include "grafico.h"

Grafico::Grafico() {
	pJanela = nullptr;
	dt = 0;

}

Grafico::Grafico(Janela* pj) {
	pJanela = pj;
	dt = 0;

}

Grafico::~Grafico() {
	pJanela = nullptr;

}

void Grafico::setJanela(Janela* ptr) {
	pJanela = ptr;

}

Janela* Grafico::getJanela() {
	return pJanela;

}

void Grafico::imprime(Ente* pEnte) {
	pJanela->janela.draw(pEnte->corpo);

}

void Grafico::imprimeTexto(sf::Text *ptr) {
	pJanela->janela.draw(*ptr);

}

void Grafico::clear() {
	pJanela->janela.clear(sf::Color::Black);

}

void Grafico::display() {
	pJanela->janela.display();

}

Grafico* Grafico::getInstance() {
	if (Grafico::instance == NULL) {

		instance = new Grafico;
	}
	return instance;

}

float Grafico::atualizaDt() {

	dt = (float)clock.restart().asSeconds();
	if (dt > 0.01) { dt = 0.01; }
	return dt;

}

const float Grafico::getDt() const {
	return dt;

}

void Grafico::imprimeBackground(sf::RectangleShape* background) {
	pJanela->janela.draw(*background);


}