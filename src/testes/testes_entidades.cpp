#include "testes/testes_entidades.hpp"

const string TUPessoa::EMAIL_VALIDO = "joao.silva@unb.br";
const string TUPessoa::NOME_VALIDO = "Joao Silva";
const string TUPessoa::SENHA_VALIDA = "abc12";
const string TUPessoa::PAPEL_VALIDO = "GESTOR";

void TUPessoa::setUp() {
    pessoa = new Pessoa();
    estado = SUCESSO;
}

void TUPessoa::tearDown() {
    delete pessoa;
}

void TUPessoa::testarCenarioSucesso() {
    EMAIL email;
    email.setValor(EMAIL_VALIDO);
    pessoa->setEmail(email);
    if (pessoa->getEmail().getValor() != EMAIL_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    pessoa->setNome(nome);
    if (pessoa->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.setValor(SENHA_VALIDA);
    pessoa->setSenha(senha);
    if (pessoa->getSenha().getValor() != SENHA_VALIDA)
        estado = FALHA;

    Papel papel;
    papel.setValor(PAPEL_VALIDO);
    pessoa->setPapel(papel);
    if (pessoa->getPapel().getValor() != PAPEL_VALIDO)
        estado = FALHA;
}

int TUPessoa::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

const string TUProjeto::IDENTIFICADOR_VALIDO = "PRJ001";
const string TUProjeto::NOME_VALIDO = "Kanban";
const string TUProjeto::DESCRICAO_VALIDA = "Projeto da disciplina.";
const string TUProjeto::INICIO_VALIDO = "01-SET-2026-08:00";
const string TUProjeto::TERMINO_VALIDO = "15-DEZ-2026-18:00";

void TUProjeto::setUp() {
    projeto = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown() {
    delete projeto;
}

void TUProjeto::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    projeto->setIdentificador(identificador);
    if (projeto->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    projeto->setNome(nome);
    if (projeto->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(DESCRICAO_VALIDA);
    projeto->setDescricao(descricao);
    if (projeto->getDescricao().getValor() != DESCRICAO_VALIDA)
        estado = FALHA;

    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    projeto->setInicio(inicio);
    if (projeto->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;

    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    projeto->setTermino(termino);
    if (projeto->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;
}

int TUProjeto::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

const string TUCartaoAtividade::IDENTIFICADOR_VALIDO = "CRT001";
const string TUCartaoAtividade::NOME_VALIDO = "Criar telas";
const string TUCartaoAtividade::DESCRICAO_VALIDA = "Telas do sistema.";
const string TUCartaoAtividade::PRIORIDADE_VALIDA = "ALTA";
const string TUCartaoAtividade::ESTADO_VALIDO = "A FAZER";
const string TUCartaoAtividade::TAMANHO_VALIDO = "MEDIO";
const string TUCartaoAtividade::ENTRADA_VALIDA = "01-OUT-2026-09:00";
const string TUCartaoAtividade::INICIO_VALIDO = "02-OUT-2026-09:00";
const string TUCartaoAtividade::TERMINO_VALIDO = "05-OUT-2026-17:30";

void TUCartaoAtividade::setUp() {
    cartao = new CartaoAtividade();
    estado = SUCESSO;
}

void TUCartaoAtividade::tearDown() {
    delete cartao;
}

void TUCartaoAtividade::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    cartao->setIdentificador(identificador);
    if (cartao->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    cartao->setNome(nome);
    if (cartao->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Texto descricao;
    descricao.setValor(DESCRICAO_VALIDA);
    cartao->setDescricao(descricao);
    if (cartao->getDescricao().getValor() != DESCRICAO_VALIDA)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(PRIORIDADE_VALIDA);
    cartao->setPrioridade(prioridade);
    if (cartao->getPrioridade().getValor() != PRIORIDADE_VALIDA)
        estado = FALHA;

    Estado estadoCartao;
    estadoCartao.setValor(ESTADO_VALIDO);
    cartao->setEstado(estadoCartao);
    if (cartao->getEstado().getValor() != ESTADO_VALIDO)
        estado = FALHA;

    Tamanho tamanho;
    tamanho.setValor(TAMANHO_VALIDO);
    cartao->setTamanho(tamanho);
    if (cartao->getTamanho().getValor() != TAMANHO_VALIDO)
        estado = FALHA;

    Timestamp entrada;
    entrada.setValor(ENTRADA_VALIDA);
    cartao->setEntrada(entrada);
    if (cartao->getEntrada().getValor() != ENTRADA_VALIDA)
        estado = FALHA;

    Timestamp inicio;
    inicio.setValor(INICIO_VALIDO);
    cartao->setInicio(inicio);
    if (cartao->getInicio().getValor() != INICIO_VALIDO)
        estado = FALHA;

    Timestamp termino;
    termino.setValor(TERMINO_VALIDO);
    cartao->setTermino(termino);
    if (cartao->getTermino().getValor() != TERMINO_VALIDO)
        estado = FALHA;
}

int TUCartaoAtividade::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

const string TUQuadro::IDENTIFICADOR_VALIDO = "QDR001";
const string TUQuadro::NOME_VALIDO = "Sprint Um";

void TUQuadro::setUp() {
    quadro = new Quadro();
    estado = SUCESSO;
}

void TUQuadro::tearDown() {
    delete quadro;
}

void TUQuadro::testarCenarioSucesso() {
    Identificador identificador;
    identificador.setValor(IDENTIFICADOR_VALIDO);
    quadro->setIdentificador(identificador);
    if (quadro->getIdentificador().getValor() != IDENTIFICADOR_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOME_VALIDO);
    quadro->setNome(nome);
    if (quadro->getNome().getValor() != NOME_VALIDO)
        estado = FALHA;

    Limite limite;
    limite.setValor(LIMITE_VALIDO);
    quadro->setLimite(limite);
    if (quadro->getLimite().getValor() != LIMITE_VALIDO)
        estado = FALHA;
}

int TUQuadro::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
