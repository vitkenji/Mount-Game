#include "listaentidade.h"

ListaEntidade::ListaEntidade() :
	lista() {

}

ListaEntidade::~ListaEntidade() {

}

void ListaEntidade::adicionaEntidade(Entidade* pEntidade) {
	lista.push(pEntidade);

}

void ListaEntidade::inicializaEntidades() {

	Elemento<Entidade>* ptr = lista.getPfirst();
	
	for (int i = 0; i < lista.getSize(); i++) {

		if (ptr->getData()->estaVivo) { ptr->getData()->imprimir(); }
		ptr = ptr->getNext();
	}
}

void ListaEntidade::executaEntidades() {

	Grafico* pGrafico = Grafico::getInstance();

	float dt = pGrafico->getDt();
	Elemento<Entidade>* pEntidade = lista.getPfirst();

	for (int i = 0; i < lista.getSize(); i++) {
		if (pEntidade->getData()->estaVivo) {
			pEntidade->getData()->executa();
		}

		pEntidade = pEntidade->getNext();
	}
}

void ListaEntidade::salvaEntidades() {
	
	Elemento<Entidade>* pEntidade = lista.getPfirst();

	for (int i = 0; i < lista.getSize(); i++) {
		pEntidade->getData()->salvar();
		pEntidade = pEntidade->getNext();

	}

}