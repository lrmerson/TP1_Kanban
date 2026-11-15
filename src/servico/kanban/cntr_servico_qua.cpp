#include "servico/kanban/cntr_servico_qua.hpp"


void CntrServicoQuadro::verificarGestor(
    const Identificador& projeto,
    const EMAIL& gestor
) {

    Projeto projetoEncontrado;

    projetoEncontrado.setIdentificador(projeto);

    if (!ContainerProjeto::getInstancia()->pesquisar(
            &projetoEncontrado)) {

        throw runtime_error("Projeto nao encontrado.");
    }

    if (projetoEncontrado.getGestor().getValor() !=
        gestor.getValor()) {

        throw runtime_error(
            "Apenas o gestor do projeto pode realizar esta operacao."
        );
    }
}


void CntrServicoQuadro::criar(
    const Quadro& quadro,
    const Identificador& projeto,
    const EMAIL& gestor
) {

    // Confere se o projeto existe e se o usuario e seu gestor.
    verificarGestor(projeto, gestor);

    // A FK projeto passa a fazer parte do proprio Quadro.
    Quadro novo = quadro;

    novo.setProjeto(projeto);

    if (!ContainerQuadro::getInstancia()->incluir(novo)) {
        throw runtime_error(
            "Ja existe quadro com este identificador."
        );
    }
}


Quadro CntrServicoQuadro::ler(
    const Identificador& identificador
) {

    Quadro quadro;

    quadro.setIdentificador(identificador);

    if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)) {
        throw runtime_error("Quadro nao encontrado.");
    }

    return quadro;
}


void CntrServicoQuadro::atualizar(
    const Quadro& quadro,
    const EMAIL& gestor
) {

    // Recupera a versao armazenada.
    Quadro armazenado = ler(
        quadro.getIdentificador()
    );

    // Verifica o gestor utilizando a FK original.
    verificarGestor(
        armazenado.getProjeto(),
        gestor
    );

    // Conta quantos cartoes estao atualmente em FAZENDO.
    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(
            quadro.getIdentificador()
        );

    int wip = 0;

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getEstado().getValor() == "FAZENDO") {
            wip++;
        }
    }

    // O novo limite nao pode ser menor que o WIP atual.
    if (quadro.getLimite().getValor() < wip) {
        throw runtime_error(
            "Limite menor que o numero de cartoes em FAZENDO."
        );
    }

    Quadro atualizado = quadro;

    // Preserva a FK. Alterar o quadro nao deve mudar
    // o projeto ao qual ele pertence.
    atualizado.setProjeto(
        armazenado.getProjeto()
    );

    ContainerQuadro::getInstancia()->atualizar(
        atualizado
    );
}


void CntrServicoQuadro::excluir(
    const Identificador& identificador,
    const EMAIL& gestor
) {

    Quadro quadro = ler(identificador);

    verificarGestor(
        quadro.getProjeto(),
        gestor
    );

    // Um quadro com cartoes associados nao pode ser excluido.
    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(
            identificador
        );

    if (cartoes.size() > 0) {
        throw runtime_error(
            "Quadro possui cartoes e nao pode ser excluido."
        );
    }

    if (!ContainerQuadro::getInstancia()->remover(
            identificador)) {

        throw runtime_error("Quadro nao encontrado.");
    }
}


vector<Identificador> CntrServicoQuadro::listar(
    const Identificador& projeto
) {

    // Primeiro verifica se o projeto existe.
    Projeto projetoEncontrado;

    projetoEncontrado.setIdentificador(projeto);

    if (!ContainerProjeto::getInstancia()->pesquisar(
            &projetoEncontrado)) {

        throw runtime_error("Projeto nao encontrado.");
    }

    vector<Identificador> identificadores;

    vector<Quadro> quadros =
        ContainerQuadro::getInstancia()->listar(
            projeto
        );

    for (int i = 0; i < quadros.size(); i++) {

        identificadores.push_back(
            quadros[i].getIdentificador()
        );
    }

    return identificadores;
}
