#ifndef CONTAINER_QUA_HPP_INCLUDED
#define CONTAINER_QUA_HPP_INCLUDED

#include <list>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

/**
 * @brief Armazena em memória os quadros cadastrados.
 */
class ContainerQuadro {
    private:
        list<Quadro> container;

        static ContainerQuadro* instancia;

        ContainerQuadro() {}

    public:
        /**
         * @brief Retorna a instância única do container.
         * @return Instância compartilhada de ContainerQuadro.
         */
        static ContainerQuadro* getInstancia();

        /**
         * @brief Inclui um quadro no container.
         * @param quadro Quadro a ser armazenado.
         * @return true se o quadro for incluído e false se já existir.
         */
        bool incluir(const Quadro& quadro);

        /**
         * @brief Remove um quadro pelo identificador.
         * @param identificador Identificador do quadro.
         * @return true se o quadro for removido e false se não existir.
         */
        bool remover(const Identificador& identificador);

        /**
         * @brief Pesquisa um quadro pelo identificador.
         * @param quadro Objeto contendo o identificador pesquisado e que receberá os dados encontrados.
         * @return true se o quadro for encontrado.
         */
        bool pesquisar(Quadro* quadro);

        /**
         * @brief Atualiza os dados de um quadro existente.
         * @param quadro Dados atualizados do quadro.
         * @return true se o quadro for encontrado e atualizado.
         */
        bool atualizar(const Quadro& quadro);

        /**
         * @brief Lista os quadros pertencentes a um projeto.
         * @param projeto Identificador do projeto.
         * @return Quadros associados ao projeto informado.
         */
        vector<Quadro> listar(const Identificador& projeto);
};

#endif // CONTAINER_QUA_HPP_INCLUDED
