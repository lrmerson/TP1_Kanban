#include "apresentacao/kanban/cntr_apresentacao_car.hpp"


namespace {

const string DICA_NOME = "ate 15 letras, ex: Atividade A";

const string DICA_TEXTO = "ate 30 caracteres, inicia com maiuscula e termina com ponto";

const string DICA_DATA = "DIA-MES-ANO-HH:MM, ex: 01-OUT-2026-09:00";

const string DICA_PRIORIDADE = "ALTA, MEDIA ou BAIXA";

const string DICA_TAMANHO = "GRANDE, MEDIO ou PEQUENO";

const string DICA_QUADRO = "3 letras + 3 numeros, ex: QDR001";

const string DICA_CARTAO = "3 letras + 3 numeros, ex: CRT001";

const string DICA_EMAIL = "letras minusculas, ex: ana@unb.br";

}


void CntrApresentacaoCartao::setCntrServicoKanban(IServicoKanban* servico) {

    cntrServicoKanban = servico;
}


void CntrApresentacaoCartao::executar(const EMAIL& email) {

    int opcao = -1;

    while (opcao != 0) {

        titulo("CARTOES DE ATIVIDADE");

        item(1, "Criar cartao");

        item(2,"Ler cartao");

        item(3, "Atualizar cartao");

        item(4, "Excluir cartao");

        item(5, "Listar cartoes de um quadro");

        item(6, "Mover cartao para a proxima coluna");

        item(0, "Voltar");

        opcao =
            lerOpcao();

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
        else if (opcao == 6) {

            mover();
        }
        else if (opcao != 0) {

            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}


void CntrApresentacaoCartao::criar(const EMAIL& email) {

    acao("Criar cartao");

    Identificador quadro;
    Identificador identificador;

    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;
    Timestamp entrada;
    EMAIL desenvolvedor;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro) || !lerCampo("Identificador do cartao", DICA_CARTAO, identificador) || !lerCampo("Nome", DICA_NOME, nome) || !lerCampo("Descricao", DICA_TEXTO, descricao) || !lerCampo("Prioridade", DICA_PRIORIDADE, prioridade) || !lerCampo("Tamanho", DICA_TAMANHO, tamanho) || !lerCampo("Entrada em A FAZER", DICA_DATA, entrada) || !lerCampo("E-mail do desenvolvedor", DICA_EMAIL,desenvolvedor)) {

        cancelado();

        return;
    }

    try {

        CartaoAtividade cartao;

        cartao.setIdentificador(identificador);

        cartao.setNome(nome);

        cartao.setDescricao(descricao);

        cartao.setPrioridade(prioridade);

        cartao.setTamanho(tamanho);

        cartao.setEntrada(entrada);

        cartao.setDesenvolvedor(desenvolvedor);

        cntrServicoKanban->criarCartao(cartao, quadro, email);

        sucesso("Cartao criado com sucesso na coluna A FAZER.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoCartao::ler() {

    acao("Ler cartao");

    Identificador identificador;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {

        cancelado();

        return;
    }

    try {

        CartaoAtividade cartao = cntrServicoKanban->lerCartao(identificador);

        string inicio = cartao.getInicio().getValor();

        string termino = cartao.getTermino().getValor();

        if (inicio == "") {
            inicio = "-";
        }

        if (termino == "") {
            termino = "-";
        }

        cout << endl;

        saida("Identificador", cartao.getIdentificador().getValor());

        saida("Nome", cartao.getNome().getValor());

        saida("Descricao", cartao.getDescricao().getValor());

        saida(
            "Prioridade",
            cartao.getPrioridade().getValor()
        );

        saida("Estado", cartao.getEstado().getValor());

        saida("Tamanho", cartao.getTamanho().getValor());

        saida("Entrada", cartao.getEntrada().getValor());

        saida("Inicio", inicio);

        saida("Termino", termino);

        saida("Desenvolvedor", cartao.getDesenvolvedor().getValor());

        saida("Quadro", cartao.getQuadro().getValor());
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoCartao::atualizar(const EMAIL& email) {

    acao("Atualizar cartao");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador) || !lerCampo("Novo nome", DICA_NOME, nome) || !lerCampo("Nova descricao", DICA_TEXTO, descricao) || !lerCampo("Nova prioridade", DICA_PRIORIDADE, prioridade) || !lerCampo("Novo tamanho", DICA_TAMANHO, tamanho)) {

        cancelado();

        return;
    }

    try {

        CartaoAtividade cartao;

        cartao.setIdentificador(identificador);

        cartao.setNome(nome);

        cartao.setDescricao(descricao);

        cartao.setPrioridade(prioridade);

        cartao.setTamanho(tamanho);

        cntrServicoKanban->
            atualizarCartao(cartao, email);

        sucesso("Cartao atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoCartao::excluir(const EMAIL& email) {

    acao("Excluir cartao");

    Identificador identificador;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {

        cancelado();

        return;
    }

    try {

        cntrServicoKanban->excluirCartao(identificador, email);

        sucesso("Cartao excluido com sucesso.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoCartao::listar() {

    acao("Cartoes de um quadro");

    Identificador quadro;

    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {

        cancelado();

        return;
    }

    try {

        vector<Identificador> identificadores = cntrServicoKanban->listarCartoes(quadro);

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


void CntrApresentacaoCartao::mover() {

    acao("Mover cartao");

    Identificador identificador;
    Timestamp momento;

    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador) || !lerCampo("Momento da movimentacao", DICA_DATA, momento)) {

        cancelado();

        return;
    }

    try {

        cntrServicoKanban->moverCartao(identificador, momento);

        CartaoAtividade cartao = cntrServicoKanban->lerCartao(identificador);

        sucesso("Cartao movido para " + cartao.getEstado().getValor() + ".");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}
