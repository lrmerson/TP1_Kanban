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
        /**
         * @brief Retorna a instância única do container.
         * @return Instância compartilhada de ContainerPessoa.
         */
        static ContainerPessoa* getInstancia();

        /**
         * @brief Inclui uma pessoa no container.
         * @param pessoa Pessoa a ser armazenada.
         * @return true se a pessoa for incluída e false se já existir.
         */
        bool incluir(const Pessoa& pessoa);

        /**
         * @brief Remove uma pessoa pelo e-mail.
         * @param email E-mail que identifica a pessoa.
         * @return true se a pessoa for removida e false se não existir.
         */
        bool remover(const EMAIL& email);

        /**
         * @brief Pesquisa uma pessoa pelo e-mail.
         * @param pessoa Objeto contendo o e-mail pesquisado e que receberá os dados encontrados.
         * @return true se a pessoa for encontrada.
         */
        bool pesquisar(Pessoa* pessoa);

        /**
         * @brief Atualiza os dados de uma pessoa existente.
         * @param pessoa Dados atualizados da pessoa.
         * @return true se a pessoa for encontrada e atualizada.
         */
        bool atualizar(const Pessoa& pessoa);

        /**
         * @brief Retorna todas as pessoas cadastradas.
         * @return Lista de pessoas armazenadas.
         */
        vector<Pessoa> listar();
};

#endif // CONTAINER_PES_HPP_INCLUDED
