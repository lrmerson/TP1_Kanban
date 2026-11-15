#include "servico/pessoas/cntr_servico_pes.hpp"

void CntrServicoPessoa::criar(const Pessoa& pessoa) {

    if (!ContainerPessoa::getInstancia()->incluir(pessoa)) {
        throw runtime_error("Ja existe pessoa com este email.");
    }
}


Pessoa CntrServicoPessoa::ler(const EMAIL& email) {

    Pessoa pessoa;

    pessoa.setEmail(email);

    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)) {
        throw runtime_error("Pessoa nao encontrada.");
    }

    return pessoa;
}


void CntrServicoPessoa::atualizar(const Pessoa& pessoa) {

    Pessoa antiga;

    antiga.setEmail(pessoa.getEmail());

    if (!ContainerPessoa::getInstancia()->pesquisar(&antiga)) {
        throw runtime_error("Pessoa nao encontrada.");
    }

    // Verifica se um gestor possui projetos associados.
    if (antiga.getPapel().getValor() == "GESTOR" && pessoa.getPapel().getValor() != "GESTOR") {
        vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();

        for (int i = 0; i < projetos.size(); i++) {

            if (projetos[i].getGestor().getValor() == pessoa.getEmail().getValor()) {

                throw runtime_error("Pessoa é gestora de projeto e não pode deixar de ser GESTOR.");
            }
        }
    }

    if (antiga.getPapel().getValor() == "DESENVOLVEDOR" && pessoa.getPapel().getValor() != "DESENVOLVEDOR") {

    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar();

        for (int i = 0; i < cartoes.size(); i++) {
    
            if (cartoes[i].getDesenvolvedor().getValor() == pessoa.getEmail().getValor()) {
    
                throw runtime_error("Pessoa e desenvolvedora de cartao e nao pode deixar de ser DESENVOLVEDOR.");
            }
        }
    }

    ContainerPessoa::getInstancia()->atualizar(pessoa);
}


void CntrServicoPessoa::excluir(const EMAIL& email) {

    vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();

    for (int i = 0; i < projetos.size(); i++) {

        if (projetos[i].getGestor().getValor() == email.getValor()) {

            throw runtime_error("Pessoa e gestora de projeto e nao pode ser excluida.");
        }
    }

    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar();

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getDesenvolvedor().getValor() == email.getValor()) {

            throw runtime_error("Pessoa e desenvolvedora de cartao e nao pode ser excluida.");
        }
    }

    if (!ContainerPessoa::getInstancia()->remover(email)) {
        throw runtime_error("Pessoa nao encontrada.");
    }
}


vector<EMAIL> CntrServicoPessoa::listar() {

    vector<EMAIL> emails;

    vector<Pessoa> pessoas = ContainerPessoa::getInstancia()->listar();

    for (int i = 0; i < pessoas.size(); i++) {
        emails.push_back(pessoas[i].getEmail());
    }

    return emails;
}
