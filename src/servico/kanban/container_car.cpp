#include "servico/kanban/container_car.hpp"

ContainerCartao* ContainerCartao::instancia = nullptr;

ContainerCartao* ContainerCartao::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerCartao();
    }

    return instancia;
}

bool ContainerCartao::incluir(const CartaoAtividade& cartao) {

    for (list<CartaoAtividade>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            cartao.getIdentificador().getValor()) {

            return false;
        }
    }

    container.push_back(cartao);

    return true;
}

bool ContainerCartao::remover(
    const Identificador& identificador
) {

    for (list<CartaoAtividade>::iterator elemento = container.begin();
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

bool ContainerCartao::pesquisar(CartaoAtividade* cartao) {

    for (list<CartaoAtividade>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            cartao->getIdentificador().getValor()) {

            *cartao = *elemento;

            return true;
        }
    }

    return false;
}

bool ContainerCartao::atualizar(
    const CartaoAtividade& cartao
) {

    for (list<CartaoAtividade>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getIdentificador().getValor() ==
            cartao.getIdentificador().getValor()) {

            *elemento = cartao;

            return true;
        }
    }

    return false;
}

vector<CartaoAtividade> ContainerCartao::listar(
    const Identificador& quadro
) {

    vector<CartaoAtividade> cartoes;

    for (list<CartaoAtividade>::iterator elemento = container.begin();
         elemento != container.end();
         elemento++) {

        if (elemento->getQuadro().getValor() ==
            quadro.getValor()) {

            cartoes.push_back(*elemento);
        }
    }

    return cartoes;
}
