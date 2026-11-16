#include "servico/autenticacao/cntr_servico_aut.hpp"
#include "servico/pessoas/cntr_servico_pes.hpp"
#include "servico/projetos/cntr_servico_pro.hpp"
#include "servico/kanban/cntr_servico_kan.hpp"

#include "apresentacao/autenticacao/cntr_apresentacao_aut.hpp"
#include "apresentacao/pessoas/cntr_apresentacao_pes.hpp"
#include "apresentacao/projetos/cntr_apresentacao_pro.hpp"
#include "apresentacao/kanban/cntr_apresentacao_kan.hpp"
#include "apresentacao/inicializacao/cntr_apresentacao_ic.hpp"

int main() {
    // Controladoras da camada de servico.
    CntrServicoAutenticacao cntrServicoAutenticacao;
    CntrServicoPessoa cntrServicoPessoa;
    CntrServicoProjeto cntrServicoProjeto;
    CntrServicoKanban cntrServicoKanban;

    // Controladoras da camada de apresentacao.
    CntrApresentacaoAutenticacao cntrApresentacaoAutenticacao;
    CntrApresentacaoPessoa cntrApresentacaoPessoa;
    CntrApresentacaoProjeto cntrApresentacaoProjeto;
    CntrApresentacaoKanban cntrApresentacaoKanban;

    // Liga a camada de apresentacao as interfaces da camada de servico.
    cntrApresentacaoAutenticacao.setCntrServicoAutenticacao(&cntrServicoAutenticacao);
    cntrApresentacaoPessoa.setCntrServicoPessoa(&cntrServicoPessoa);
    cntrApresentacaoProjeto.setCntrServicoProjeto(&cntrServicoProjeto);
    cntrApresentacaoKanban.setCntrServicoKanban(&cntrServicoKanban);

    // Controladora responsavel pela inicializacao e navegacao principal.
    CntrApresentacaoInicializacao cntrApresentacaoInicializacao;

    // Liga a inicializacao aos modulos da camada de apresentacao.
    cntrApresentacaoInicializacao.setCntrApresentacaoAutenticacao(&cntrApresentacaoAutenticacao);
    cntrApresentacaoInicializacao.setCntrApresentacaoPessoa(&cntrApresentacaoPessoa);
    cntrApresentacaoInicializacao.setCntrApresentacaoProjeto(&cntrApresentacaoProjeto);
    cntrApresentacaoInicializacao.setCntrApresentacaoKanban(&cntrApresentacaoKanban);

    // Inicia a aplicacao.
    cntrApresentacaoInicializacao.executar();

    return 0;
}
