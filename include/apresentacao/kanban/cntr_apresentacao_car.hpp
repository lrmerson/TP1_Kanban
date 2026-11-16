#ifndef CNTR_APRESENTACAO_CAR_HPP_INCLUDED
#define CNTR_APRESENTACAO_CAR_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "interfaces/servico/interfaces_servico.hpp"
#include "apresentacao/utilitarios_apresentacao.hpp"

using namespace std;

/**
 * @brief Controla a interface com o usuário para cartões de atividade.
 */
class CntrApresentacaoCartao {
    private:
        IServicoKanban* cntrServicoKanban;

        void criar(const EMAIL& email);

        void ler();

        void atualizar(const EMAIL& email);

        void excluir(const EMAIL& email);

        void listar();

        void mover();

    public:

        /**
         * @brief Executa o menu de serviços de cartões.
         *
         * @param email Pessoa atualmente autenticada.
         */
        void executar(const EMAIL& email);

        /**
         * @brief Define o serviço Kanban utilizado.
         *
         * @param servico Interface da camada de serviço Kanban.
         */
        void setCntrServicoKanban(IServicoKanban* servico);
};

#endif // CNTR_APRESENTACAO_CAR_HPP_INCLUDED
