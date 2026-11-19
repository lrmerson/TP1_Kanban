#include "apresentacao/inicializacao/cntr_apresentacao_ic.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


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
        SaidaUsuario::titulo("SISTEMA KANBAN", "Gestao de projetos com quadros Kanban");

        SaidaUsuario::item(1, "Entrar");
        SaidaUsuario::item(2, "Criar conta");
        SaidaUsuario::item(0, "Sair");

        SaidaUsuario::separador();

        opcao = EntradaUsuario::lerOpcao();

        if (opcao == 1) {
            EMAIL email;

            if (cntrApresentacaoAutenticacao->autenticar(&email)) {
                SaidaUsuario::sucesso("Autenticacao realizada com sucesso.");
                menuServicos(email);
            }
        }
        else if (opcao == 2) {
            cntrApresentacaoPessoa->cadastrar();
        }
        else if (opcao != 0) {
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }

    cout << endl << "Ate logo!" << endl;
}


void CntrApresentacaoInicializacao::menuServicos(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        SaidaUsuario::titulo("MENU PRINCIPAL", "Conectado como: " + email.getValor());

        SaidaUsuario::item(1, "Pessoas");
        SaidaUsuario::item(2, "Projetos");
        SaidaUsuario::item(3, "Kanban");
        SaidaUsuario::item(0, "Sair da conta");

        SaidaUsuario::separador();

        opcao = EntradaUsuario::lerOpcao();

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
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}
