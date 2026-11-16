#include "apresentacao/projetos/cntr_apresentacao_pro.hpp"


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

        titulo("PROJETOS");

        item(1, "Criar projeto");

        item(2, "Ler projeto");

        item(3, "Atualizar projeto");

        item(4, "Excluir projeto");

        item(5, "Listar projetos");

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


void CntrApresentacaoProjeto::criar(const EMAIL& email) {

    acao("Criar projeto");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    if (!lerCampo("Identificador", DICA_PROJETO, identificador) || !lerCampo("Nome", DICA_NOME, nome) || !lerCampo("Descricao", DICA_TEXTO, descricao) || !lerCampo("Inicio", DICA_DATA, inicio) || !lerCampo("Termino", DICA_DATA, termino)) {

        cancelado();

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

        sucesso("Projeto criado com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::ler() {

    acao("Ler projeto");

    Identificador identificador;

    if (!lerCampo("Identificador do projeto", DICA_PROJETO, identificador)) {

        cancelado();

        return;
    }

    try {

        Projeto projeto = cntrServicoProjeto->ler(identificador);

        cout << endl;

        saida("Identificador", projeto.getIdentificador().getValor());

        saida("Nome", projeto.getNome().getValor());

        saida("Descricao", projeto.getDescricao().getValor());

        saida("Inicio", projeto.getInicio().getValor());

        saida("Termino", projeto.getTermino().getValor());

        saida("Gestor", projeto.getGestor().getValor());
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::atualizar(const EMAIL& email) {

    acao("Atualizar projeto");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;

    if (!lerCampo("Identificador do projeto", DICA_PROJETO, identificador) || !lerCampo("Novo nome", DICA_NOME, nome) || !lerCampo("Nova descricao", DICA_TEXTO, descricao) || !lerCampo("Novo inicio", DICA_DATA, inicio) || !lerCampo("Novo termino", DICA_DATA, termino)) {

        cancelado();

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

        sucesso("Projeto atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::excluir(const EMAIL& email) {

    acao("Excluir projeto");

    Identificador identificador;

    if (!lerCampo("Identificador do projeto", DICA_PROJETO, identificador)) {

        cancelado();

        return;
    }

    try {

        cntrServicoProjeto->excluir(identificador, email);

        sucesso("Projeto excluido com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoProjeto::listar() {

    acao("Projetos cadastrados",false);

    try {

        vector<Identificador> identificadores = cntrServicoProjeto->listar();

        vector<string> itens;

        for (size_t i = 0; i < identificadores.size(); i++) {

            itens.push_back(identificadores[i].getValor());
        }

        listaItens(itens);
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}
