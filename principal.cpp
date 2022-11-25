#include "principal.h"

Grafico* Ente::pGrafico = nullptr;
Grafico* Grafico::instance = nullptr;

Principal::Principal() :
    janela(1080, 720),
    fase1(&janela),
    fase2(&janela),
    menu() {

    grafico = Grafico::getInstance();
    grafico->setJanela(&janela);
    Ente::pGrafico = grafico;

}

Principal::~Principal() {
    delete grafico->getInstance();

}

void Principal::executar() {

    int inicio = menu.executa();

    switch (inicio) {

    case 0:
        fase1.executar();
        break;


    case 1:
        fase2.executar();
        break;

    case 2:
        cout << "em desenvolvimento" << endl;

    }
}

