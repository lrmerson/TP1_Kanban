#include "apresentacao/inicializacao/cntr_apresentacao_ic.hpp"

void CntrApresentacaoInicializacao::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr) {
    cntrApresentacaoAutenticacao = cntr;
}

void CntrApresentacaoInicializacao::setCntrApresentacaoPessoa(IApresentacaoPessoa* cntr) {
    cntrApresentacaoPessoa = cntr;
}

void CntrApresentacaoInicializacao::setCntrApresentacaoProjeto(IApresentacaoProjeto* cntr) {
    cntrApresentacaoProjeto = cntr;
}

void CntrApresentacaoInicializacao::setCntrApresentacaoKanban(IApresentacaoKanban* cntr) {
    cntrApresentacaoKanban = cntr;
}

void CntrApresentacaoInicializacao::executar() {
    int opcao = -1;

    while (opcao != 0) {
        titulo("SISTEMA KANBAN", "Gestao de projetos com quadros Kanban");

        item(1, "Entrar");
        item(2, "Criar conta");
        item(0, "Sair");

        opcao = lerOpcao();

        if (opcao == 1) {
            EMAIL email;

            if (cntrApresentacaoAutenticacao->autenticar(&email)) {
                sucesso("Autenticacao realizada com sucesso.");
                menuServicos(email);
            }
        }
        else if (opcao == 2) {
            cntrApresentacaoPessoa->cadastrar();
        }
        else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }

    cout << endl << "Ate logo!" << endl;
}

void CntrApresentacaoInicializacao::menuServicos(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        titulo("MENU PRINCIPAL", "Conectado como: " + email.getValor());

        item(1, "Pessoas");
        item(2, "Projetos");
        item(3, "Kanban");
        item(0, "Sair da conta");

        opcao = lerOpcao();

        if (opcao == 1) {
            if (!cntrApresentacaoPessoa->executar(email)) {
                return;
            }
        }
        else if (opcao == 2) {
            cntrApresentacaoProjeto->executar(email);
        }
        else if (opcao == 3) {
            cntrApresentacaoKanban->executar(email);
        }
        else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}
