#include "selecaofase.h"

SelecaoFase::SelecaoFase() :Menu() {
	Ente::pGrafico = Grafico::getInstance();
	opcao = 0;
	totalOpcoes = 2;
	Botao* pBotao = nullptr;

	for (int i = 0; i < totalOpcoes; i++) {

		pBotao = new Botao("m5x7.ttf", "botao" + to_string(i), 50);
		pBotao->setPosicao(Coordenadaf(500, 200 + 100 * i));
		pBotao->setTamanho(Coordenadaf(250, 62.5));
		pBotao->corpo.setFillColor(sf::Color::Cyan); // nao selecionado
		if (i == opcao) {
			pBotao->corpo.setFillColor(sf::Color::Red); // selecionado
			pBotao->texto.setFillColor(sf::Color::White);

		}
		botoes.push_back(pBotao);

	}
	botoes[0]->setString("1 Jogador");
	botoes[1]->setString("2 Jogadores");
	
}

SelecaoFase::~SelecaoFase() {

}

int::SelecaoFase::executa() {

	sf::Event evento;
	imprime();
	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))) {
		while (pGrafico->getJanela()->janela.pollEvent(evento)) {


			if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::S && opcao <= totalOpcoes - 1) {
					opcao++;
					botoes[opcao]->corpo.setFillColor(sf::Color::Red);
					botoes[opcao - 1]->corpo.setFillColor(sf::Color::Cyan);
					imprime();

				}

				else if (evento.key.code == sf::Keyboard::W && opcao >= 0) {
					opcao--;
					botoes[opcao]->corpo.setFillColor(sf::Color::Red);
					botoes[opcao + 1]->corpo.setFillColor(sf::Color::Cyan);
					imprime();

				}
			}
		}
	}
	return opcao;
}

void SelecaoFase::imprime() {


}