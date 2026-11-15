#ifndef CONTAINER_PRO_HPP_INCLUDED
#define CONTAINER_PRO_HPP_INCLUDED

#include <list>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

/**
 * @brief Armazena em memória os projetos cadastrados.
 */
class ContainerProjeto {
    private:
        list<Projeto> container;

        static ContainerProjeto* instancia;

        ContainerProjeto() {}

    public:
        /**
         * @brief Retorna a instância única do container.
         * @return Instância compartilhada de ContainerProjeto.
         */
        static ContainerProjeto* getInstancia();

        /**
         * @brief Inclui um projeto no container.
         * @param projeto Projeto a ser armazenado.
         * @return true se o projeto for incluído e false se já existir.
         */
        bool incluir(const Projeto& projeto);

        /**
         * @brief Remove um projeto pelo identificador.
         * @param identificador Identificador do projeto.
         * @return true se o projeto for removido e false se não existir.
         */
        bool remover(const Identificador& identificador);

        /**
         * @brief Pesquisa um projeto pelo identificador.
         * @param projeto Objeto contendo o identificador pesquisado e que receberá os dados encontrados.
         * @return true se o projeto for encontrado.
         */
        bool pesquisar(Projeto* projeto);

        /**
         * @brief Atualiza os dados de um projeto existente.
         * @param projeto Dados atualizados do projeto.
         * @return true se o projeto for encontrado e atualizado.
         */
        bool atualizar(const Projeto& projeto);

        /**
         * @brief Retorna todos os projetos cadastrados.
         * @return Lista de projetos armazenados.
         */
        vector<Projeto> listar();
};

#endif // CONTAINER_PRO_HPP_INCLUDED
