#include "apresentacao/controladoras_apresentacao.hpp"
#include "servico/controladoras_servico.hpp"

int main() {
    CntrServicoPessoa cntrServicoPessoa;
    CntrServicoProjeto cntrServicoProjeto;
    CntrServicoQuadro cntrServicoQuadro;
    CntrServicoCartao cntrServicoCartao;

    CntrApresentacaoPessoa cntrApresentacaoPessoa;
    CntrApresentacaoProjeto cntrApresentacaoProjeto;
    CntrApresentacaoQuadro cntrApresentacaoQuadro;
    CntrApresentacaoCartao cntrApresentacaoCartao;

    cntrApresentacaoPessoa.setCntrServicoPessoa(&cntrServicoPessoa);
    cntrApresentacaoProjeto.setCntrServicoProjeto(&cntrServicoProjeto);
    cntrApresentacaoQuadro.setCntrServicoQuadro(&cntrServicoQuadro);
    cntrApresentacaoCartao.setCntrServicoCartao(&cntrServicoCartao);

    CntrApresentacaoControle cntrApresentacaoControle;
    cntrApresentacaoControle.setCntrApresentacaoPessoa(&cntrApresentacaoPessoa);
    cntrApresentacaoControle.setCntrApresentacaoProjeto(&cntrApresentacaoProjeto);
    cntrApresentacaoControle.setCntrApresentacaoQuadro(&cntrApresentacaoQuadro);
    cntrApresentacaoControle.setCntrApresentacaoCartao(&cntrApresentacaoCartao);

    cntrApresentacaoControle.executar();

    return 0;
}
