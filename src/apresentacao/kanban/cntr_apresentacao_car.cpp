#include "apresentacao/kanban/cntr_apresentacao_car.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


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
        SaidaUsuario::titulo("CARTOES DE ATIVIDADE");

        SaidaUsuario::item(1, "Criar cartao");
        SaidaUsuario::item(2, "Ler cartao");
        SaidaUsuario::item(3, "Atualizar cartao");
        SaidaUsuario::item(4, "Excluir cartao");
        SaidaUsuario::item(5, "Listar cartoes de um quadro");
        SaidaUsuario::item(6, "Mover cartao para a proxima coluna");
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
        else if (opcao == 6) {
            mover();
        }
        else if (opcao != 0) {
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}


void CntrApresentacaoCartao::criar(const EMAIL& email) {
    SaidaUsuario::acao("Criar cartao");

    Identificador quadro;
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;
    Timestamp entrada;
    EMAIL desenvolvedor;

    if (!EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, quadro) ||
        !EntradaUsuario::lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !EntradaUsuario::lerCampo("Nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Descricao", DICA_TEXTO, descricao) ||
        !EntradaUsuario::lerCampo("Prioridade", DICA_PRIORIDADE, prioridade) ||
        !EntradaUsuario::lerCampo("Tamanho", DICA_TAMANHO, tamanho) ||
        !EntradaUsuario::lerCampo("Entrada em A FAZER", DICA_DATA, entrada) ||
        !EntradaUsuario::lerCampo("E-mail do desenvolvedor", DICA_EMAIL, desenvolvedor)) {

        SaidaUsuario::cancelado();
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

        SaidaUsuario::sucesso("Cartao criado com sucesso na coluna A FAZER.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoCartao::ler() {
    SaidaUsuario::acao("Ler cartao");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        SaidaUsuario::cancelado();
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

        SaidaUsuario::saida("Identificador", cartao.getIdentificador().getValor());
        SaidaUsuario::saida("Nome", cartao.getNome().getValor());
        SaidaUsuario::saida("Descricao", cartao.getDescricao().getValor());
        SaidaUsuario::saida("Prioridade", cartao.getPrioridade().getValor());
        SaidaUsuario::saida("Estado", cartao.getEstado().getValor());
        SaidaUsuario::saida("Tamanho", cartao.getTamanho().getValor());
        SaidaUsuario::saida("Entrada", cartao.getEntrada().getValor());
        SaidaUsuario::saida("Inicio", inicio);
        SaidaUsuario::saida("Termino", termino);
        SaidaUsuario::saida("Desenvolvedor", cartao.getDesenvolvedor().getValor());
        SaidaUsuario::saida("Quadro", cartao.getQuadro().getValor());
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoCartao::atualizar(const EMAIL& email) {
    SaidaUsuario::acao("Atualizar cartao");

    Identificador identificador;
    Nome nome;
    Texto descricao;
    Prioridade prioridade;
    Tamanho tamanho;

    if (!EntradaUsuario::lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !EntradaUsuario::lerCampo("Novo nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Nova descricao", DICA_TEXTO, descricao) ||
        !EntradaUsuario::lerCampo("Nova prioridade", DICA_PRIORIDADE, prioridade) ||
        !EntradaUsuario::lerCampo("Novo tamanho", DICA_TAMANHO, tamanho)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        CartaoAtividade cartao;

        cartao.setIdentificador(identificador);
        cartao.setNome(nome);
        cartao.setDescricao(descricao);
        cartao.setPrioridade(prioridade);
        cartao.setTamanho(tamanho);

        cntrServicoKanban->atualizarCartao(cartao, email);

        SaidaUsuario::sucesso("Cartao atualizado com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoCartao::excluir(const EMAIL& email) {
    SaidaUsuario::acao("Excluir cartao");

    Identificador identificador;

    if (!EntradaUsuario::lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        cntrServicoKanban->excluirCartao(identificador, email);

        SaidaUsuario::sucesso("Cartao excluido com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoCartao::listar() {
    SaidaUsuario::acao("Cartoes de um quadro");

    Identificador quadro;

    if (!EntradaUsuario::lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        vector<Identificador> identificadores = cntrServicoKanban->listarCartoes(quadro);

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


void CntrApresentacaoCartao::mover() {
    SaidaUsuario::acao("Mover cartao");

    Identificador identificador;
    Timestamp momento;

    if (!EntradaUsuario::lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !EntradaUsuario::lerCampo("Momento da movimentacao", DICA_DATA, momento)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        cntrServicoKanban->moverCartao(identificador, momento);

        CartaoAtividade cartao = cntrServicoKanban->lerCartao(identificador);

        SaidaUsuario::sucesso("Cartao movido para " + cartao.getEstado().getValor() + ".");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}
