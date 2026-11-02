#include <iostream>

#include "testes/testes_dominios.hpp"
#include "testes/testes_entidades.hpp"

static bool exibir(const string &nome, int resultado) {
    bool passou = resultado == 0;
    cout << nome << ": " << (passou ? "SUCESSO" : "FALHA") << endl;
    return passou;
}

int main() {
    bool tudoPassou = true;

    TUEMAIL testeEmail;
    tudoPassou &= exibir("EMAIL", testeEmail.run());

    TUEstado testeEstado;
    tudoPassou &= exibir("Estado", testeEstado.run());

    TUIdentificador testeIdentificador;
    tudoPassou &= exibir("Identificador", testeIdentificador.run());

    TULimite testeLimite;
    tudoPassou &= exibir("Limite", testeLimite.run());

    TUNome testeNome;
    tudoPassou &= exibir("Nome", testeNome.run());

    TUPapel testePapel;
    tudoPassou &= exibir("Papel", testePapel.run());

    TUPrioridade testePrioridade;
    tudoPassou &= exibir("Prioridade", testePrioridade.run());

    TUSenha testeSenha;
    tudoPassou &= exibir("Senha", testeSenha.run());

    TUTamanho testeTamanho;
    tudoPassou &= exibir("Tamanho", testeTamanho.run());

    TUTexto testeTexto;
    tudoPassou &= exibir("Texto", testeTexto.run());

    TUTimestamp testeTimestamp;
    tudoPassou &= exibir("Timestamp", testeTimestamp.run());

    TUPessoa testePessoa;
    tudoPassou &= exibir("Pessoa", testePessoa.run());

    TUProjeto testeProjeto;
    tudoPassou &= exibir("Projeto", testeProjeto.run());

    TUCartaoAtividade testeCartao;
    tudoPassou &= exibir("CartaoAtividade", testeCartao.run());

    TUQuadro testeQuadro;
    tudoPassou &= exibir("Quadro", testeQuadro.run());

    return tudoPassou ? 0 : 1;
}
