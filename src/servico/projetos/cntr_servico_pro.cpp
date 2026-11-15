#include "servico/projetos/cntr_servico_pro.hpp"


void CntrServicoProjeto::verificarGestor(
    const Identificador& identificador,
    const EMAIL& gestor
) {

    Projeto projeto;

    projeto.setIdentificador(identificador);

    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)) {
        throw runtime_error("Projeto nao encontrado.");
    }

    if (projeto.getGestor().getValor() != gestor.getValor()) {
        throw runtime_error(
            "Apenas o gestor do projeto pode realizar esta operacao."
        );
    }
}


void CntrServicoProjeto::criar(
    const Projeto& projeto,
    const EMAIL& gestor
) {

    Pessoa pessoa;

    pessoa.setEmail(gestor);

    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)) {
        throw runtime_error("Pessoa nao encontrada.");
    }

    if (pessoa.getPapel().getValor() != "GESTOR") {
        throw runtime_error("Apenas GESTOR pode criar projeto.");
    }

    Projeto novo = projeto;

    novo.setGestor(gestor);

    if (!ContainerProjeto::getInstancia()->incluir(novo)) {
        throw runtime_error(
            "Ja existe projeto com este identificador."
        );
    }
}


Projeto CntrServicoProjeto::ler(
    const Identificador& identificador
) {

    Projeto projeto;

    projeto.setIdentificador(identificador);

    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)) {
        throw runtime_error("Projeto nao encontrado.");
    }

    return projeto;
}


void CntrServicoProjeto::atualizar(
    const Projeto& projeto,
    const EMAIL& gestor
) {

    verificarGestor(
        projeto.getIdentificador(),
        gestor
    );

    Projeto atual = projeto;

    // Preserva a FK do gestor original.
    Projeto armazenado;

    armazenado.setIdentificador(
        projeto.getIdentificador()
    );

    ContainerProjeto::getInstancia()->pesquisar(
        &armazenado
    );

    atual.setGestor(
        armazenado.getGestor()
    );

    ContainerProjeto::getInstancia()->atualizar(
        atual
    );
}


void CntrServicoProjeto::excluir(
    const Identificador& identificador,
    const EMAIL& gestor
) {

    verificarGestor(
        identificador,
        gestor
    );

    vector<Quadro> quadros =
        ContainerQuadro::getInstancia()->listar(
            identificador
        );

    if (quadros.size() > 0) {
        throw runtime_error(
            "Projeto possui quadros e nao pode ser excluido."
        );
    }

    if (!ContainerProjeto::getInstancia()->remover(
            identificador)) {

        throw runtime_error(
            "Projeto nao encontrado."
        );
    }
}


vector<Identificador> CntrServicoProjeto::listar() {

    vector<Identificador> identificadores;

    vector<Projeto> projetos =
        ContainerProjeto::getInstancia()->listar();

    for (int i = 0; i < projetos.size(); i++) {

        identificadores.push_back(
            projetos[i].getIdentificador()
        );
    }

    return identificadores;
}
