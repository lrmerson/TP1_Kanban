#ifndef CNTR_APRESENTACAO_MET_HPP_INCLUDED
#define CNTR_APRESENTACAO_MET_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "interfaces/servico/interfaces_servico.hpp"
#include "apresentacao/utilitarios_apresentacao.hpp"

using namespace std;

/**
 * @brief Controla a interface com o usuário para consulta das métricas Kanban.
 */
class CntrApresentacaoMetricas {
    private:
        IServicoKanban* cntrServicoKanban;

        void lerTempoCiclo();
        void lerTempoCicloMedio();
        void lerLeadTime();
        void lerLeadTimeMedio();
        void lerWIP();

    public:
        /**
         * @brief Executa o menu de métricas Kanban.
         */
        void executar();

        /**
         * @brief Define o serviço Kanban utilizado.
         *
         * @param servico Interface da camada de serviço Kanban.
         */
        void setCntrServicoKanban(IServicoKanban* servico);
};

#endif // CNTR_APRESENTACAO_MET_HPP_INCLUDED
