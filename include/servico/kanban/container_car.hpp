#ifndef CONTAINER_CAR_HPP_INCLUDED
#define CONTAINER_CAR_HPP_INCLUDED

#include <list>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

/**
 * @brief Armazena em memória os cartões de atividade cadastrados.
 */
class ContainerCartao {
    private:
        list<CartaoAtividade> container;

        static ContainerCartao* instancia;

        ContainerCartao() {}

    public:
        /**
         * @brief Retorna a instância única do container.
         * @return Instância compartilhada de ContainerCartao.
         */
        static ContainerCartao* getInstancia();

        /**
         * @brief Inclui um cartão no container.
         * @param cartao Cartão a ser armazenado.
         * @return true se o cartão for incluído e false se já existir.
         */
        bool incluir(const CartaoAtividade& cartao);

        /**
         * @brief Remove um cartão pelo identificador.
         * @param identificador Identificador do cartão.
         * @return true se o cartão for removido e false se não existir.
         */
        bool remover(const Identificador& identificador);

        /**
         * @brief Pesquisa um cartão pelo identificador.
         * @param cartao Objeto contendo o identificador pesquisado e que receberá os dados encontrados.
         * @return true se o cartão for encontrado.
         */
        bool pesquisar(CartaoAtividade* cartao);

        /**
         * @brief Atualiza os dados de um cartão existente.
         * @param cartao Dados atualizados do cartão.
         * @return true se o cartão for encontrado e atualizado.
         */
        bool atualizar(const CartaoAtividade& cartao);

        /**
         * @brief Lista todos os cartões do sistema.
         * @return Cartões pertencentes a qualquer quadro.
         */
        vector<CartaoAtividade> listar();

        /**
         * @brief Lista os cartões pertencentes a um quadro.
         * @param quadro Identificador do quadro.
         * @return Cartões associados ao quadro informado.
         */
        vector<CartaoAtividade> listar(const Identificador& quadro);
};

#endif // CONTAINER_CAR_HPP_INCLUDED
