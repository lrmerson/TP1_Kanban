#include "apresentacao/kanban/cntr_apresentacao_qua.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


namespace {

const string DICA_NOME = "ate 15 letras, ex: Quadro A";
const string DICA_LIMITE = "numero de 1 a 25";
const string DICA_PROJETO = "3 letras + 3 numeros, ex: PRJ001";
const string DICA_QUADRO = "3 letras + 3 numeros, ex: QDR001";

}


void CntrApresentacaoQuadro::setCntrServicoKanban(IServicoKanban* servico) {
    cntrServicoKanban = servico;
}


void CntrApresentacaoQuadro::executar(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        SaidaUsuario::titulo("QUADROS");

        SaidaUsuario::item(1, "Criar quadro");
        SaidaUsuario::item(2, "Ler quadro");
        SaidaUsuario::item(3, "Atualizar quadro");
        SaidaUsuario::item(4, "Excluir quadro");
        SaidaUsuario::item(5, "Listar quadros de um projeto");
        SaidaUsuario::item(0, "Voltar");

        SaidaUsuario::separador();
        opcao = EntradaUsuario::lerOpcao();

        if (opcao == 1) {
            criar(email);
        }
        else if (opcao == 2) {
            ler();
        }
        else if (opcao == 3) {
            atualizar(email);
        }
        else if (opcao == 4) {
            excluir(email);
        }
        else if (opcao == 5) {
            listar();
        }
        else if (opcao != 0) {
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}


void CntrApresentacaoQuadro::criar(const EMAIL& email) {
    SaidaUsuario::acao("Criar quadro");

    Identificador projeto;
    Identificador identificador;
    Nome nome;
    Limite limite;

    if (!EntradaUsuario::lerCampo("Identificador do projeto", DICA_PROJETO, projeto) ||
        !EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, identificador) ||
        !EntradaUsuario::lerCampo("Nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Limite WIP", DICA_LIMITE, limite)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Quadro quadro;

        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);

        cntrServicoKanban->criarQuadro(quadro, projeto, email);

        SaidaUsuario::sucesso("Quadro criado com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::ler() {
    SaidaUsuario::acao("Ler quadro");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, identificador)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        Quadro quadro = cntrServicoKanban->lerQuadro(identificador);

        cout << endl;

        SaidaUsuario::saida("Identificador", quadro.getIdentificador().getValor());
        SaidaUsuario::saida("Nome", quadro.getNome().getValor());
        SaidaUsuario::saida("Limite WIP", to_string(quadro.getLimite().getValor()));
        SaidaUsuario::saida("Projeto", quadro.getProjeto().getValor());
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::atualizar(const EMAIL& email) {
    SaidaUsuario::acao("Atualizar quadro");

    Identificador identificador;
    Nome nome;
    Limite limite;

    if (!EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, identificador) ||
        !EntradaUsuario::lerCampo("Novo nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Novo limite WIP", DICA_LIMITE, limite)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Quadro quadro;

        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);

        cntrServicoKanban->atualizarQuadro(quadro, email);

        SaidaUsuario::sucesso("Quadro atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::excluir(const EMAIL& email) {
    SaidaUsuario::acao("Excluir quadro");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, identificador)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        cntrServicoKanban->excluirQuadro(identificador, email);

        SaidaUsuario::sucesso("Quadro excluido com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::listar() {
    SaidaUsuario::acao("Quadros de um projeto");

    Identificador projeto;

    if (!EntradaUsuario::lerCampo("Identificador do projeto", DICA_PROJETO, projeto)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        vector<Identificador> identificadores = cntrServicoKanban->listarQuadros(projeto);

        vector<string> itens;

        for (size_t i = 0; i < identificadores.size(); i++) {
            itens.push_back(identificadores[i].getValor());
        }

        cout << endl;

        SaidaUsuario::listaItens(itens);
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}
