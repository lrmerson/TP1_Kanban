#include "servico/kanban/container_qua.hpp"

ContainerQuadro* ContainerQuadro::instancia = nullptr;

ContainerQuadro* ContainerQuadro::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerQuadro();
    }

    return instancia;
}

bool ContainerQuadro::incluir(const Quadro& quadro) {

    for (list<Quadro>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            quadro.getIdentificador().getValor()) {

            return false;
        }
    }

    container.push_back(quadro);

    return true;
}

bool ContainerQuadro::remover(const Identificador& identificador) {

    for (list<Quadro>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            identificador.getValor()) {

            container.erase(elemento);

            return true;
        }
    }

    return false;
}

bool ContainerQuadro::pesquisar(Quadro* quadro) {

    for (list<Quadro>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            quadro->getIdentificador().getValor()) {

            *quadro = *elemento;

            return true;
        }
    }

    return false;
}

bool ContainerQuadro::atualizar(const Quadro& quadro) {

    for (list<Quadro>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            quadro.getIdentificador().getValor()) {

            *elemento = quadro;

            return true;
        }
    }

    return false;
}

vector<Quadro> ContainerQuadro::listar(
    const Identificador& projeto
) {

    vector<Quadro> quadros;

    for (list<Quadro>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getProjeto().getValor() ==
            projeto.getValor()) {

            quadros.push_back(*elemento);
        }
    }

    return quadros;
}
