#include "jogador.h"

using namespace std;

Jogador::Jogador(int id) : Personagem(), pontos() {
	podePular = false;
	pontos = 0;
	vida = 1000;
	aceleracao.y = 1000;
	desaceleracao = 0;
	id = id;

	if (id == 1) {
		teclas[0] = sf::Keyboard::Key::W;
		teclas[1] = sf::Keyboard::Key::A;
		teclas[2] = sf::Keyboard::Key::D;
		teclas[3] = sf::Keyboard::Key::S;

	}
	else if (id == 2) {
		teclas[0] = sf::Keyboard::Key::Up;
		teclas[1] = sf::Keyboard::Key::Left;
		teclas[2] = sf::Keyboard::Key::Right;
		teclas[3] = sf::Keyboard::Key::Down;

	}
}

Jogador::~Jogador() {

}
void Jogador::movimenta() {
	velocidadeMovimento = 275;

	if (desaceleracao > 0.05) {
		desaceleracao -= pGrafico->getDt();
		velocidadeMovimento = 50;
		setPulo(false);

	}

	else {
		velocidadeMovimento = 275;
		desaceleracao = 0;

	}

	velocidade.x = 0;
	aceleracao.y = 3000;
	//velocidade.y = 1000;

	if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)teclas[0]) && podePular == true)){
		velocidade.y += -800;
		podePular = false;
		atualizaPosicao();

	}

	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)teclas[1])){
		velocidade.x = -velocidadeMovimento;

	}

	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)teclas[2])) {
		velocidade.x = velocidadeMovimento;

	}
	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)teclas[3])) {
		velocidade.y = velocidadeMovimento;

	}
}

void Jogador::setPulo(bool pula) {
	podePular = pula;

}

void Jogador::executa() {
	movimenta();
	atualizaPosicao();

}

void Jogador::setPontos(int pontos) {
	pontos = pontos;

}

int Jogador::getPontos() {
	return pontos;

}

void Jogador::pontua() {
	pontos += 100;

}

void Jogador::alteraVelocidade() {
	velocidade.x = 100;


}

void Jogador::salvar() {
	ofstream arquivoJogador("../salvamento/jogador.txt", ofstream::out);
	arquivoJogador << estaVivo << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< pontos << ""
		<< podePular << ""
		<< vida << ""
		<< endl;
	
	arquivoJogador.close();

}