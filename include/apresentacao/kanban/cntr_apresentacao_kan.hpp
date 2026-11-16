#ifndef CNTR_APRESENTACAO_KAN_HPP_INCLUDED
#define CNTR_APRESENTACAO_KAN_HPP_INCLUDED

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"
#include "interfaces/servico/interfaces_servico.hpp"

#include "apresentacao/kanban/cntr_apresentacao_qua.hpp"
#include "apresentacao/kanban/cntr_apresentacao_car.hpp"
#include "apresentacao/kanban/cntr_apresentacao_met.hpp"
#include "apresentacao/utilitarios_apresentacao.hpp"

/**
 * @brief Fachada da apresentação do subsistema Kanban.
 *
 * Reúne os menus de quadros, cartões de atividade e métricas.
 */
class CntrApresentacaoKanban : public IApresentacaoKanban {
    private:
        IServicoKanban* cntrServicoKanban;

        CntrApresentacaoQuadro cntrQuadro;
        CntrApresentacaoCartao cntrCartao;
        CntrApresentacaoMetricas cntrMetricas;

    public:
        /** @copydoc IApresentacaoKanban::executar */
        void executar(const EMAIL& email) override;

        /** @copydoc IApresentacaoKanban::setCntrServicoKanban */
        void setCntrServicoKanban(IServicoKanban* servico) override;
};

#endif // CNTR_APRESENTACAO_KAN_HPP_INCLUDED
