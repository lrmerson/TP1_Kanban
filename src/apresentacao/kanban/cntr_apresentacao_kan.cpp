#include "apresentacao/kanban/cntr_apresentacao_kan.hpp"

void CntrApresentacaoKanban::setCntrServicoKanban(IServicoKanban* servico) {
    cntrServicoKanban = servico;

    cntrQuadro.setCntrServicoKanban(servico);
    cntrCartao.setCntrServicoKanban(servico);
    cntrMetricas.setCntrServicoKanban(servico);
}

void CntrApresentacaoKanban::executar(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        titulo("KANBAN");

        item(1, "Quadros");
        item(2, "Cartoes de atividade");
        item(3, "Metricas");
        item(0, "Voltar");

        opcao = lerOpcao();

        if (opcao == 1) {
            cntrQuadro.executar(email);
        }
        else if (opcao == 2) {
            cntrCartao.executar(email);
        }
        else if (opcao == 3) {
            cntrMetricas.executar();
        }
        else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}
