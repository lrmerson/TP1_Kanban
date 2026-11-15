#ifndef CNTR_SERVICO_CAR_HPP_INCLUDED
#define CNTR_SERVICO_CAR_HPP_INCLUDED

#include <stdexcept>
#include <vector>

#include "servico/pessoas/container_pes.hpp"
#include "servico/projetos/container_pro.hpp"
#include "servico/kanban/container_qua.hpp"
#include "servico/kanban/container_car.hpp"

using namespace std;

/**
 * @brief Implementa os serviços relacionados aos cartões de atividade.
 */
class CntrServicoCartao {
    private:

        /**
         * @brief Verifica se a pessoa informada é gestora
         * do projeto ao qual o quadro pertence.
         */
        void verificarGestor(
            const Identificador& quadro,
            const EMAIL& gestor
        );

        /**
         * @brief Converte um timestamp para quantidade de minutos.
         *
         * Usado para comparar momentos durante a movimentação.
         */
        int converterMinutos(
            const Timestamp& timestamp
        );

        /**
         * @brief Conta os cartões atualmente na coluna FAZENDO.
         */
        int contarFazendo(
            const Identificador& quadro
        );

    public:

        /**
         * @brief Cria um cartão em um quadro.
         */
        void criar(
            const CartaoAtividade& cartao,
            const Identificador& quadro,
            const EMAIL& gestor
        );

        /**
         * @brief Busca um cartão pelo identificador.
         */
        CartaoAtividade ler(
            const Identificador& identificador
        );

        /**
         * @brief Atualiza os dados editáveis de um cartão.
         */
        void atualizar(
            const CartaoAtividade& cartao,
            const EMAIL& gestor
        );

        /**
         * @brief Exclui um cartão.
         */
        void excluir(
            const Identificador& identificador,
            const EMAIL& gestor
        );

        /**
         * @brief Lista os cartões pertencentes a um quadro.
         */
        vector<Identificador> listar(
            const Identificador& quadro
        );

        /**
         * @brief Move o cartão para a próxima coluna do fluxo Kanban.
         */
        void mover(
            const Identificador& identificador,
            const Timestamp& momento
        );
};

#endif // CNTR_SERVICO_CAR_HPP_INCLUDED
