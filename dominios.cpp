#include "dominios.hpp"


void Limite::setValor(int valor) {
    if (valor < 1 || valor > 25) {
        throw invalid_argument("Limite invalido.");
    }

    this->valor = valor;
}

int Limite::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Prioridade::setValor(string valor) {
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw invalid_argument("Prioridade invalida.");
    }

    this->valor = valor;
}

string Prioridade::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Estado::setValor(string valor) {
    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO") {
        throw invalid_argument("Estado invalido.");
    }

    this->valor = valor;
}

string Estado::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Papel::setValor(string valor) {
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR") {
        throw invalid_argument("Papel invalido.");
    }

    this->valor = valor;
}

string Papel::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Tamanho::setValor(string valor) {
    if (valor != "GRANDE" && valor != "MÉDIO" && valor != "PEQUENO") {
        throw invalid_argument("Tamanho invalido.");
    }

    this->valor = valor;
}

string Tamanho::getValor() const {
    return valor;
}
