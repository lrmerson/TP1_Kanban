#ifndef CNTR_SERVICO_KAN_HPP_INCLUDED
#define CNTR_SERVICO_KAN_HPP_INCLUDED

#include "interfaces/servico/interfaces_servico.hpp"

#include "servico/kanban/cntr_servico_qua.hpp"
#include "servico/kanban/cntr_servico_car.hpp"
#include "servico/kanban/cntr_servico_met.hpp"

/**
 * @brief Fachada dos serviços do subsistema Kanban.
 *
 * Implementa a interface externa IServicoKanban e delega
 * as operações para as controladoras internas de quadro,
 * cartão e métricas.
 */
class CntrServicoKanban : public IServicoKanban {
    private:
        CntrServicoQuadro cntrQuadro;
        CntrServicoCartao cntrCartao;
        CntrServicoMetricas cntrMetricas;

    public:

        /** @copydoc IServicoKanban::criarQuadro */
        void criarQuadro(const Quadro& quadro,const Identificador& projeto,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::lerQuadro */
        Quadro lerQuadro(const Identificador& identificador) override;

        /** @copydoc IServicoKanban::atualizarQuadro */
        void atualizarQuadro(const Quadro& quadro,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::excluirQuadro */
        void excluirQuadro(const Identificador& identificador,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::listarQuadros */
        vector<Identificador> listarQuadros(const Identificador& projeto) override;


        /** @copydoc IServicoKanban::criarCartao */
        void criarCartao(const CartaoAtividade& cartao,const Identificador& quadro,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::lerCartao */
        CartaoAtividade lerCartao(const Identificador& identificador) override;

        /** @copydoc IServicoKanban::atualizarCartao */
        void atualizarCartao(const CartaoAtividade& cartao,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::excluirCartao */
        void excluirCartao(const Identificador& identificador,const EMAIL& gestor) override;

        /** @copydoc IServicoKanban::listarCartoes */
        vector<Identificador> listarCartoes(const Identificador& quadro) override;

        /** @copydoc IServicoKanban::moverCartao */
        void moverCartao(const Identificador& identificador,const Timestamp& momento) override;


        /** @copydoc IServicoKanban::lerTempoCiclo */
        int lerTempoCiclo(const Identificador& identificador) override;

        /** @copydoc IServicoKanban::lerTempoCicloMedio */
        double lerTempoCicloMedio(const Identificador& quadro) override;

        /** @copydoc IServicoKanban::lerLeadTime */
        int lerLeadTime(const Identificador& identificador) override;

        /** @copydoc IServicoKanban::lerLeadTimeMedio */
        double lerLeadTimeMedio(const Identificador& quadro) override;

        /** @copydoc IServicoKanban::lerWIP */
        int lerWIP(const Identificador& quadro) override;
};

#endif // CNTR_SERVICO_KAN_HPP_INCLUDED
