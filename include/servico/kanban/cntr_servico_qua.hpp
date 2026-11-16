#ifndef CNTR_SERVICO_QUA_HPP_INCLUDED
#define CNTR_SERVICO_QUA_HPP_INCLUDED

#include <stdexcept>
#include <vector>

#include "servico/projetos/container_pro.hpp"
#include "servico/kanban/container_qua.hpp"
#include "servico/kanban/container_car.hpp"

using namespace std;

/**
 * @brief Implementa os serviços relacionados aos quadros Kanban.
 */
class CntrServicoQuadro {
    private:

        /**
         * @brief Verifica se a pessoa informada é gestora
         * do projeto ao qual o quadro pertence.
         *
         * @param projeto Identificador do projeto.
         * @param gestor E-mail da pessoa que solicita a operação.
         */
        void verificarGestor(const Identificador& projeto,const EMAIL& gestor);

    public:

        /**
         * @brief Cria um quadro dentro de um projeto.
         */
        void criar(const Quadro& quadro,const Identificador& projeto,const EMAIL& gestor);

        /**
         * @brief Busca um quadro pelo identificador.
         */
        Quadro ler(const Identificador& identificador);

        /**
         * @brief Atualiza os dados de um quadro.
         */
        void atualizar(const Quadro& quadro,const EMAIL& gestor);

        /**
         * @brief Exclui um quadro.
         */
        void excluir(const Identificador& identificador,const EMAIL& gestor);

        /**
         * @brief Lista os quadros pertencentes a um projeto.
         */
        vector<Identificador> listar(const Identificador& projeto);
};

#endif // CNTR_SERVICO_QUA_HPP_INCLUDED
