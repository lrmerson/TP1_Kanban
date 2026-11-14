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
    if (antiga.getPapel().getValor() == "GESTOR" && pessoa.getPapel().getValor() != "GESTOR") {
        vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
        for (int i = 0; i < projetos.size(); i++) {
            string id = projetos[i].getIdentificador().getValor();
            if (ContainerProjeto::getInstancia()->getGestor(id) == pessoa.getEmail().getValor()) {
                throw runtime_error("Pessoa e gestora de projeto e nao pode deixar de ser GESTOR.");
            }
        }
    }
    ContainerPessoa::getInstancia()->atualizar(pessoa);
}

void CntrServicoPessoa::excluir(const EMAIL& email) {
    vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
    for (int i = 0; i < projetos.size(); i++) {
        string id = projetos[i].getIdentificador().getValor();
        if (ContainerProjeto::getInstancia()->getGestor(id) == email.getValor()) {
            throw runtime_error("Pessoa e gestora de projeto e nao pode ser excluida.");
        }
    }
    if (!ContainerPessoa::getInstancia()->remover(email.getValor())) {
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
