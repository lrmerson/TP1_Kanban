#include "servico/projetos/container_pro.hpp"

ContainerProjeto* ContainerProjeto::instancia = nullptr;

ContainerProjeto* ContainerProjeto::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerProjeto();
    }

    return instancia;
}

bool ContainerProjeto::incluir(const Projeto& projeto) {

    for (list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getIdentificador().getValor() ==
            projeto.getIdentificador().getValor()) {

            return false;
        }
    }

    container.push_back(projeto);

    return true;
}

bool ContainerProjeto::remover(const Identificador& identificador) {

    for (list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getIdentificador().getValor() ==
            identificador.getValor()) {

            container.erase(elemento);

            return true;
        }
    }

    return false;
}

bool ContainerProjeto::pesquisar(Projeto* projeto) {

    for (list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getIdentificador().getValor() ==
            projeto->getIdentificador().getValor()) {

            *projeto = *elemento;

            return true;
        }
    }

    return false;
}

bool ContainerProjeto::atualizar(const Projeto& projeto) {

    for (list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getIdentificador().getValor() ==
            projeto.getIdentificador().getValor()) {

            *elemento = projeto;

            return true;
        }
    }

    return false;
}

vector<Projeto> ContainerProjeto::listar() {

    vector<Projeto> projetos;

    for (list<Projeto>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        projetos.push_back(*elemento);
    }

    return projetos;
}
