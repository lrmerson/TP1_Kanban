#include "apresentacao/kanban/cntr_apresentacao_kan.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


void CntrApresentacaoKanban::setCntrServicoKanban(IServicoKanban* servico) {
    cntrServicoKanban = servico;

    cntrQuadro.setCntrServicoKanban(servico);
    cntrCartao.setCntrServicoKanban(servico);
    cntrMetricas.setCntrServicoKanban(servico);
}


void CntrApresentacaoKanban::executar(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        SaidaUsuario::titulo("KANBAN");

        SaidaUsuario::item(1, "Quadros");
        SaidaUsuario::item(2, "Cartoes de atividade");
        SaidaUsuario::item(3, "Metricas");
        SaidaUsuario::item(0, "Voltar");

        SaidaUsuario::separador();
        opcao = EntradaUsuario::lerOpcao();

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
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}
