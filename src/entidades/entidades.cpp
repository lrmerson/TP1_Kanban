#include "entidades.hpp"

//metodos da entidade Pessoa

void Pessoa::setEmail(const EMAIL& email) {
    this->email = email;
}
EMAIL Pessoa::getEmail() const {
    return email;
}

void Pessoa::setNome(const Nome& nome) {
    this->nome = nome;
}
Nome Pessoa::getNome() const {
    return nome;
}

void Pessoa::setSenha(const Senha& senha) {
    this->senha = senha;
}
Senha Pessoa::getSenha() const {
    return senha;
}

void Pessoa::setPapel(const Papel& papel) {
    this->papel = papel;
}
Papel Pessoa::getPapel() const {
    return papel;
}

///////////////////////////////////////////////////////////////////////////////
//metodos da entidade Projeto

void Projeto::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}
Identificador Projeto::getIdentificador() const {
    return identificador;
}

void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}
Nome Projeto::getNome() const {
    return nome;
}

void Projeto::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}
Texto Projeto::getDescricao() const {
    return descricao;
}

void Projeto::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}
Timestamp Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(const Timestamp& termino) {
    this->termino = termino;
}
Timestamp Projeto::getTermino() const {
    return termino;
}


///////////////////////////////////////////////////////////////////////////////
//metodos da entidade CartaoAtividade

void CartaoAtividade::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}
Identificador CartaoAtividade::getIdentificador() const {
    return identificador;
}

void CartaoAtividade::setNome(const Nome& nome) {
    this->nome = nome;
}
Nome CartaoAtividade::getNome() const {
    return nome;
}

void CartaoAtividade::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}
Texto CartaoAtividade::getDescricao() const {
    return descricao;
}

void CartaoAtividade::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}
Prioridade CartaoAtividade::getPrioridade() const {
    return prioridade;
}

void CartaoAtividade::setEstado(const Estado& estado) {
    this->estado = estado;
}
Estado CartaoAtividade::getEstado() const {
    return estado;
}

void CartaoAtividade::setTamanho(const Tamanho& tamanho) {
    this->tamanho = tamanho;
}
Tamanho CartaoAtividade::getTamanho() const {
    return tamanho;
}

void CartaoAtividade::setEntrada(const Timestamp& entrada) {
    this->entrada = entrada;
}
Timestamp CartaoAtividade::getEntrada() const {
    return entrada;
}

void CartaoAtividade::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}
Timestamp CartaoAtividade::getInicio() const {
    return inicio;
}

void CartaoAtividade::setTermino(const Timestamp& termino) {
    this->termino = termino;
}
Timestamp CartaoAtividade::getTermino() const {
    return termino;
}



///////////////////////////////////////////////////////////////////////////////
//metodos da entidade Quadro

void Quadro::setIdentificador(const Identificador& identificador) {
    this->identificador = identificador;
}
Identificador Quadro::getIdentificador() const {
    return identificador;
}

void Quadro::setNome(const Nome& nome) {
    this->nome = nome;
}
Nome Quadro::getNome() const {
    return nome;
}

void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}
Limite Quadro::getLimite() const {
    return limite;
}

