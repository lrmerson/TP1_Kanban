#include "apresentacao/kanban/cntr_apresentacao_met.hpp"

namespace {

const string DICA_QUADRO = "3 letras + 3 numeros, ex: QDR001";
const string DICA_CARTAO = "3 letras + 3 numeros, ex: CRT001";

}

void CntrApresentacaoMetricas::setCntrServicoKanban(IServicoKanban* servico) {
    cntrServicoKanban = servico;
}

void CntrApresentacaoMetricas::executar() {
    int opcao = -1;

    while (opcao != 0) {
        titulo("METRICAS KANBAN");

        item(1, "Tempo de ciclo de um cartao");
        item(2, "Tempo de ciclo medio de um quadro");
        item(3, "Lead time de um cartao");
        item(4, "Lead time medio de um quadro");
        item(5, "WIP de um quadro");
        item(0, "Voltar");

        opcao = lerOpcao();

        if (opcao == 1) {
            lerTempoCiclo();
        }
        else if (opcao == 2) {
            lerTempoCicloMedio();
        }
        else if (opcao == 3) {
            lerLeadTime();
        }
        else if (opcao == 4) {
            lerLeadTimeMedio();
        }
        else if (opcao == 5) {
            lerWIP();
        }
        else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}

void CntrApresentacaoMetricas::lerTempoCiclo() {
    acao("Tempo de ciclo de um cartao");

    Identificador identificador;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        cancelado();
        return;
    }

    try {
        int tempo = cntrServicoKanban->lerTempoCiclo(identificador);

        cout << endl << "  Tempo de ciclo: " << tempo << " minutos." << endl;
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoMetricas::lerTempoCicloMedio() {
    acao("Tempo de ciclo medio de um quadro");

    Identificador quadro;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }

    try {
        double tempo = cntrServicoKanban->lerTempoCicloMedio(quadro);

        cout << endl << "  Tempo de ciclo medio: " << tempo << " minutos." << endl;
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoMetricas::lerLeadTime() {
    acao("Lead time de um cartao");

    Identificador identificador;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        cancelado();
        return;
    }

    try {
        int tempo = cntrServicoKanban->lerLeadTime(identificador);

        cout << endl << "  Lead time: " << tempo << " minutos." << endl;
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoMetricas::lerLeadTimeMedio() {
    acao("Lead time medio de um quadro");

    Identificador quadro;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }

    try {
        double tempo = cntrServicoKanban->lerLeadTimeMedio(quadro);

        cout << endl << "  Lead time medio: " << tempo << " minutos." << endl;
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoMetricas::lerWIP() {
    acao("WIP de um quadro");

    Identificador quadro;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }

    try {
        int wip = cntrServicoKanban->lerWIP(quadro);

        cout << endl << "  WIP (cartoes em FAZENDO): " << wip << endl;
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}
