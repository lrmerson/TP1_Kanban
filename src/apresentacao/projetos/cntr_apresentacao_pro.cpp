#include "apresentacao/projetos/cntr_apresentacao_pro.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


namespace {

const string DICA_NOME = "ate 15 letras, ex: Projeto A";
const string DICA_TEXTO = "ate 30 caracteres, inicia com maiuscula e termina com ponto";
const string DICA_DATA = "DIA-MES-ANO-HH:MM, ex: 01-OUT-2026-09:00";
const string DICA_PROJETO = "3 letras + 3 numeros, ex: PRJ001";

}


void CntrApresentacaoProjeto::setCntrServicoProjeto(IServicoProjeto* servico) {
    cntrServicoProjeto = servico;
}


void CntrApresentacaoProjeto::executar(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        SaidaUsuario::titulo("PROJETOS");

        SaidaUsuario::item(1, "Criar projeto");
        SaidaUsuario::item(2, "Ler projeto");
        SaidaUsuario::item(3, "Atualizar projeto");
        SaidaUsuario::item(4, "Excluir projeto");
        SaidaUsuario::item(5, "Listar projetos");
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


void CntrApresentacaoProjeto::criar(const EMAIL& email) {
    SaidaUsuario::acao("Criar projeto");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    if (!EntradaUsuario::lerCampo("Identificador", DICA_PROJETO, identificador) ||
        !EntradaUsuario::lerCampo("Nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Descricao", DICA_TEXTO, descricao) ||
        !EntradaUsuario::lerCampo("Inicio", DICA_DATA, inicio) ||
        !EntradaUsuario::lerCampo("Termino", DICA_DATA, termino)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Projeto projeto;

        projeto.setIdentificador(identificador);
        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);

        cntrServicoProjeto->criar(projeto, email);

        SaidaUsuario::sucesso("Projeto criado com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::ler() {
    SaidaUsuario::acao("Ler projeto");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do projeto", DICA_PROJETO, identificador)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        Projeto projeto = cntrServicoProjeto->ler(identificador);

        cout << endl;

        SaidaUsuario::saida("Identificador", projeto.getIdentificador().getValor());
        SaidaUsuario::saida("Nome", projeto.getNome().getValor());
        SaidaUsuario::saida("Descricao", projeto.getDescricao().getValor());
        SaidaUsuario::saida("Inicio", projeto.getInicio().getValor());
        SaidaUsuario::saida("Termino", projeto.getTermino().getValor());
        SaidaUsuario::saida("Gestor", projeto.getGestor().getValor());
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::atualizar(const EMAIL& email) {
    SaidaUsuario::acao("Atualizar projeto");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    if (!EntradaUsuario::lerCampo("Identificador do projeto", DICA_PROJETO, identificador) ||
        !EntradaUsuario::lerCampo("Novo nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Nova descricao", DICA_TEXTO, descricao) ||
        !EntradaUsuario::lerCampo("Novo inicio", DICA_DATA, inicio) ||
        !EntradaUsuario::lerCampo("Novo termino", DICA_DATA, termino)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Projeto projeto;

        projeto.setIdentificador(identificador);
        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);

        cntrServicoProjeto->atualizar(projeto, email);

        SaidaUsuario::sucesso("Projeto atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::excluir(const EMAIL& email) {
    SaidaUsuario::acao("Excluir projeto");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do projeto", DICA_PROJETO, identificador)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        cntrServicoProjeto->excluir(identificador, email);

        SaidaUsuario::sucesso("Projeto excluido com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::listar() {
    SaidaUsuario::acao("Projetos cadastrados", false);

    try {
        vector<Identificador> identificadores = cntrServicoProjeto->listar();

        vector<string> itens;

        for (size_t i = 0; i < identificadores.size(); i++) {
            itens.push_back(identificadores[i].getValor());
        }

        SaidaUsuario::listaItens(itens);
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}
