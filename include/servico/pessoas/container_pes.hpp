#ifndef CONTAINER_PES_HPP_INCLUDED
#define CONTAINER_PES_HPP_INCLUDED

#include <list>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

/**
 * @brief Armazena em memória as pessoas cadastradas.
 */
class ContainerPessoa {
    private:
        list<Pessoa> container;
        static ContainerPessoa* instancia;
        ContainerPessoa() {}

    public:
        static ContainerPessoa* getInstancia();
        bool incluir(const Pessoa& pessoa);
        bool remover(const EMAIL& email);
        bool pesquisar(Pessoa* pessoa);
        bool atualizar(const Pessoa& pessoa);
        vector<Pessoa> listar();
};

#endif
