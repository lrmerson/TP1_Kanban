#include "apresentacao/kanban/cntr_apresentacao_qua.hpp"


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

        titulo("QUADROS");

        item(1, "Criar quadro");

        item(2, "Ler quadro");

        item(3, "Atualizar quadro");

        item(4, "Excluir quadro");

        item(5, "Listar quadros de um projeto");

        item(0, "Voltar");

        opcao = lerOpcao();

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

            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}


void CntrApresentacaoQuadro::criar(const EMAIL& email) {

    acao("Criar quadro");

    Identificador projeto;
    Identificador identificador;
    Nome nome;
    Limite limite;

    if (!lerCampo("Identificador do projeto", DICA_PROJETO, projeto) || !lerCampo("Identificador do quadro", DICA_QUADRO, identificador) || !lerCampo("Nome", DICA_NOME, nome) || !lerCampo("Limite WIP", DICA_LIMITE, limite)) {

        cancelado();

        return;
    }

    try {

        Quadro quadro;

        quadro.setIdentificador(identificador);

        quadro.setNome(nome);

        quadro.setLimite(limite);

        cntrServicoKanban->criarQuadro(quadro, projeto, email);

        sucesso("Quadro criado com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::ler() {

    acao("Ler quadro");

    Identificador identificador;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, identificador)) {

        cancelado();

        return;
    }

    try {

        Quadro quadro = cntrServicoKanban->lerQuadro(identificador);

        cout << endl;

        saida("Identificador", quadro.getIdentificador().getValor());

        saida("Nome", quadro.getNome().getValor());

        saida("Limite WIP", to_string(quadro.getLimite().getValor()));

        saida("Projeto", quadro.getProjeto().getValor());
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::atualizar(const EMAIL& email) {

    acao("Atualizar quadro");

    Identificador identificador;
    Nome nome;
    Limite limite;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, identificador) || !lerCampo("Novo nome", DICA_NOME, nome) || !lerCampo("Novo limite WIP", DICA_LIMITE, limite)) {

        cancelado();

        return;
    }

    try {

        Quadro quadro;

        quadro.setIdentificador(identificador);

        quadro.setNome(nome);

        quadro.setLimite(limite);

        cntrServicoKanban->atualizarQuadro(quadro, email);

        sucesso("Quadro atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::excluir(const EMAIL& email) {

    acao("Excluir quadro");

    Identificador identificador;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, identificador)) {

        cancelado();

        return;
    }

    try {

        cntrServicoKanban->excluirQuadro(identificador, email);

        sucesso("Quadro excluido com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoQuadro::listar() {

    acao("Quadros de um projeto");

    Identificador projeto;

    if (!lerCampo("Identificador do projeto", DICA_PROJETO, projeto)) {

        cancelado();

        return;
    }

    try {

        vector<Identificador> identificadores = cntrServicoKanban->listarQuadros(projeto);

        vector<string> itens;

        for (size_t i = 0; i < identificadores.size(); i++) {

            itens.push_back(identificadores[i].getValor());
        }

        cout << endl;

        listaItens(itens);
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}
