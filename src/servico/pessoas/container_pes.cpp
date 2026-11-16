#include "servico/pessoas/container_pes.hpp"

ContainerPessoa* ContainerPessoa::instancia = nullptr;

ContainerPessoa* ContainerPessoa::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerPessoa();
    }

    return instancia;
}

bool ContainerPessoa::incluir(const Pessoa& pessoa) {

    for (list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getEmail().getValor() ==
            pessoa.getEmail().getValor()) {

            return false;
        }
    }

    container.push_back(pessoa);

    return true;
}

bool ContainerPessoa::remover(const EMAIL& email) {

    for (list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getEmail().getValor() ==
            email.getValor()) {

            container.erase(elemento);

            return true;
        }
    }

    return false;
}

bool ContainerPessoa::pesquisar(Pessoa* pessoa) {

    for (list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getEmail().getValor() ==
            pessoa->getEmail().getValor()) {

            *pessoa = *elemento;

            return true;
        }
    }

    return false;
}

bool ContainerPessoa::atualizar(const Pessoa& pessoa) {

    for (list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        if (elemento->getEmail().getValor() ==
            pessoa.getEmail().getValor()) {

            *elemento = pessoa;

            return true;
        }
    }

    return false;
}

vector<Pessoa> ContainerPessoa::listar() {

    vector<Pessoa> pessoas;

    for (list<Pessoa>::iterator elemento = container.begin(); elemento != container.end(); elemento++) {

        pessoas.push_back(*elemento);
    }

    return pessoas;
}
