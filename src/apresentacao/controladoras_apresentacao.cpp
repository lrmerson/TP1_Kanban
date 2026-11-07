#include "apresentacao/controladoras_apresentacao.hpp"
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <vector>

string lerLinha(string rotulo) {
    string texto;
    cout << rotulo;
    if (!getline(cin, texto)) {
        cout << endl;
        exit(0);
    }
    // Remove o retorno de carro quando a entrada vem de arquivo com final de linha do Windows
    if (!texto.empty() && texto[texto.size() - 1] == '\r') {
        texto.erase(texto.size() - 1);
    }
    return texto;
}

namespace {

int converterNumero(const string& texto) {
    if (texto.size() == 0 || texto.size() > 9) {
        return -1;
    }
    for (size_t i = 0; i < texto.size(); i++) {
        if (!isdigit(texto[i])) {
            return -1;
        }
    }
    return stoi(texto);
}

}

int lerNumero(string rotulo) {
    return converterNumero(lerLinha(rotulo));
}

namespace {

const string SEPARADOR = "+" + string(58, '-') + "+";

const string DICA_EMAIL = "letras minusculas, ex: ana@unb.br";
const string DICA_NOME = "ate 15 letras, ex: Ana Souza";
const string DICA_SENHA = "5 caracteres com letras e numeros, ex: abc12";
const string DICA_PAPEL = "GESTOR ou DESENVOLVEDOR";
const string DICA_TEXTO = "ate 30 caracteres, inicia com maiuscula e termina com ponto";
const string DICA_DATA = "DIA-MES-ANO-HH:MM, ex: 01-OUT-2026-09:00";
const string DICA_PRIORIDADE = "ALTA, MEDIA ou BAIXA";
const string DICA_TAMANHO = "GRANDE, MEDIO ou PEQUENO";
const string DICA_LIMITE = "numero de 1 a 25";
const string DICA_PROJETO = "3 letras + 3 numeros, ex: PRJ001";
const string DICA_QUADRO = "3 letras + 3 numeros, ex: QDR001";
const string DICA_CARTAO = "3 letras + 3 numeros, ex: CRT001";

void linha(const string& texto = "") {
    cout << "| " << left << setw(56) << texto << " |" << endl;
}

void titulo(const string& texto, const string& subtitulo = "") {
    cout << endl << SEPARADOR << endl;
    linha("  " + texto);
    if (subtitulo != "") {
        linha("  " + subtitulo);
    }
    cout << SEPARADOR << endl;
}

void secao(const string& texto) {
    linha();
    linha(" " + texto + ":");
}

void item(int numero, const string& texto) {
    linha("   [" + to_string(numero) + "]" + (numero < 10 ? "  " : " ") + texto);
}

int lerOpcao() {
    cout << SEPARADOR << endl;
    return lerNumero("Escolha uma opcao: ");
}

void acao(const string& texto, bool pedeDados = true) {
    cout << endl << ">> " << texto << endl;
    if (pedeDados) {
        cout << "   (Digite 0 ou pressione Enter em branco para voltar)" << endl;
    }
}

void sucesso(const string& mensagem) {
    cout << endl << "[OK] " << mensagem << endl;
}

void erro(const string& mensagem) {
    cout << endl << "[ERRO] " << mensagem << endl;
}

void aviso(const string& mensagem) {
    cout << "  [!] " << mensagem << endl;
}

void cancelado() {
    cout << endl << "[--] Operacao cancelada." << endl;
}

void saida(const string& rotulo, const string& valor) {
    cout << "  " << left << setw(14) << rotulo << ": " << valor << endl;
}

void listaItens(const vector<string>& itens) {
    if (itens.empty()) {
        cout << "  (nenhum registro encontrado)" << endl;
        return;
    }
    for (size_t i = 0; i < itens.size(); i++) {
        cout << "  " << (i + 1) << ". " << itens[i] << endl;
    }
    cout << "  Total: " << itens.size() << endl;
}

template <typename T>
bool lerCampo(const string& rotulo, const string& dica, T& campo) {
    while (true) {
        string texto = lerLinha("  " + rotulo + " (" + dica + "): ");
        if (texto.empty() || texto == "0") {
            return false;
        }
        try {
            campo.setValor(texto);
            return true;
        }
        catch (invalid_argument &excecao) {
            aviso(string(excecao.what()) + " Formato: " + dica + ".");
            aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
        }
    }
}

bool lerCampo(const string& rotulo, const string& dica, Limite& campo) {
    while (true) {
        string texto = lerLinha("  " + rotulo + " (" + dica + "): ");
        if (texto.empty() || texto == "0") {
            return false;
        }
        try {
            campo.setValor(converterNumero(texto));
            return true;
        }
        catch (invalid_argument &excecao) {
            aviso(string(excecao.what()) + " Formato: " + dica + ".");
            aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
        }
    }
}

}

void CntrApresentacaoControle::setCntrApresentacaoPessoa(IApresentacaoPessoa *cntr) {
    cntrApresentacaoPessoa = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoProjeto(IApresentacaoProjeto *cntr) {
    cntrApresentacaoProjeto = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoQuadro(IApresentacaoQuadro *cntr) {
    cntrApresentacaoQuadro = cntr;
}

void CntrApresentacaoControle::setCntrApresentacaoCartao(IApresentacaoCartao *cntr) {
    cntrApresentacaoCartao = cntr;
}

void CntrApresentacaoControle::executar() {
    int opcao = -1;
    while (opcao != 0) {
        titulo("SISTEMA KANBAN", "Gestao de projetos com quadros Kanban");
        item(1, "Entrar");
        item(2, "Criar conta");
        item(0, "Sair");
        opcao = lerOpcao();
        if (opcao == 1) {
            EMAIL email;
            if (cntrApresentacaoPessoa->autenticar(&email)) {
                sucesso("Autenticacao realizada com sucesso.");
                menuServicos(email);
            }
        } else if (opcao == 2) {
            cntrApresentacaoPessoa->cadastrar();
        } else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
    cout << endl << "Ate logo!" << endl;
}

void CntrApresentacaoControle::menuServicos(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        titulo("MENU PRINCIPAL", "Conectado como: " + email.getValor());
        item(1, "Pessoas");
        item(2, "Projetos");
        item(3, "Quadros");
        item(4, "Cartoes de atividade");
        item(0, "Sair da conta");
        opcao = lerOpcao();
        if (opcao == 1) {
            if (!cntrApresentacaoPessoa->executar(email)) {
                return;
            }
        } else if (opcao == 2) {
            cntrApresentacaoProjeto->executar(email);
        } else if (opcao == 3) {
            cntrApresentacaoQuadro->executar(email);
        } else if (opcao == 4) {
            cntrApresentacaoCartao->executar(email);
        } else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
}

void CntrApresentacaoPessoa::setCntrServicoPessoa(IServicoPessoa *cntr) {
    cntrServicoPessoa = cntr;
}

bool CntrApresentacaoPessoa::autenticar(EMAIL *email) {
    acao("Entrar");
    Senha senha;
    if (!lerCampo("E-mail", DICA_EMAIL, *email) || !lerCampo("Senha", DICA_SENHA, senha)) {
        cancelado();
        return false;
    }
    try {
        if (cntrServicoPessoa->autenticar(*email, senha)) {
            return true;
        }
        erro("E-mail ou senha incorretos.");
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
    return false;
}

void CntrApresentacaoPessoa::cadastrar() {
    acao("Criar conta");
    EMAIL email;
    Nome nome;
    Senha senha;
    Papel papel;
    if (!lerCampo("E-mail", DICA_EMAIL, email) ||
        !lerCampo("Nome", DICA_NOME, nome) ||
        !lerCampo("Senha", DICA_SENHA, senha) ||
        !lerCampo("Papel", DICA_PAPEL, papel)) {
        cancelado();
        return;
    }
    try {
        Pessoa pessoa;
        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);
        cntrServicoPessoa->criar(pessoa);
        sucesso("Conta criada com sucesso.");
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

bool CntrApresentacaoPessoa::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        titulo("PESSOAS");
        item(1, "Ler pessoa");
        item(2, "Atualizar minha conta");
        item(3, "Excluir minha conta");
        item(4, "Listar pessoas");
        item(0, "Voltar");
        opcao = lerOpcao();
        if (opcao == 1) {
            ler();
        } else if (opcao == 2) {
            atualizar(email);
        } else if (opcao == 3) {
            if (excluir(email)) {
                return false;
            }
        } else if (opcao == 4) {
            listar();
        } else if (opcao != 0) {
            aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }
    return true;
}

void CntrApresentacaoPessoa::ler() {
    acao("Ler pessoa");
    EMAIL email;
    if (!lerCampo("E-mail da pessoa", DICA_EMAIL, email)) {
        cancelado();
        return;
    }
    try {
        Pessoa pessoa = cntrServicoPessoa->ler(email);
        cout << endl;
        saida("E-mail", pessoa.getEmail().getValor());
        saida("Nome", pessoa.getNome().getValor());
        saida("Papel", pessoa.getPapel().getValor());
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoPessoa::atualizar(const EMAIL& email) {
    acao("Atualizar minha conta");
    cout << "   E-mail (nao pode ser alterado): " << email.getValor() << endl;
    Nome nome;
    Senha senha;
    Papel papel;
    if (!lerCampo("Novo nome", DICA_NOME, nome) ||
        !lerCampo("Nova senha", DICA_SENHA, senha) ||
        !lerCampo("Novo papel", DICA_PAPEL, papel)) {
        cancelado();
        return;
    }
    try {
        Pessoa pessoa;
        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);
        cntrServicoPessoa->atualizar(pessoa);
        sucesso("Conta atualizada com sucesso.");
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

bool CntrApresentacaoPessoa::excluir(const EMAIL& email) {
    acao("Excluir minha conta", false);
    string resposta = lerLinha("  Tem certeza que deseja excluir sua conta? (S/N): ");
    if (resposta != "S" && resposta != "s") {
        cancelado();
        return false;
    }
    try {
        cntrServicoPessoa->excluir(email);
        sucesso("Conta excluida com sucesso.");
        return true;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
    return false;
}

void CntrApresentacaoPessoa::listar() {
    acao("Pessoas cadastradas", false);
    try {
        vector<EMAIL> emails = cntrServicoPessoa->listar();
        vector<string> itens;
        for (size_t i = 0; i < emails.size(); i++) {
            itens.push_back(emails[i].getValor());
        }
        listaItens(itens);
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoProjeto::setCntrServicoProjeto(IServicoProjeto *cntr) {
    cntrServicoProjeto = cntr;
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
        } else if (opcao == 2) {
            ler();
        } else if (opcao == 3) {
            atualizar(email);
        } else if (opcao == 4) {
            excluir(email);
        } else if (opcao == 5) {
            listar();
        } else if (opcao != 0) {
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
    if (!lerCampo("Identificador", DICA_PROJETO, identificador) ||
        !lerCampo("Nome", DICA_NOME, nome) ||
        !lerCampo("Descricao", DICA_TEXTO, descricao) ||
        !lerCampo("Inicio", DICA_DATA, inicio) ||
        !lerCampo("Termino", DICA_DATA, termino)) {
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
    catch (runtime_error &excecao) {
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
    }
    catch (runtime_error &excecao) {
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
    if (!lerCampo("Identificador do projeto", DICA_PROJETO, identificador) ||
        !lerCampo("Novo nome", DICA_NOME, nome) ||
        !lerCampo("Nova descricao", DICA_TEXTO, descricao) ||
        !lerCampo("Novo inicio", DICA_DATA, inicio) ||
        !lerCampo("Novo termino", DICA_DATA, termino)) {
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
    catch (runtime_error &excecao) {
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
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoProjeto::listar() {
    acao("Projetos cadastrados", false);
    try {
        vector<Identificador> identificadores = cntrServicoProjeto->listar();
        vector<string> itens;
        for (size_t i = 0; i < identificadores.size(); i++) {
            itens.push_back(identificadores[i].getValor());
        }
        listaItens(itens);
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoQuadro::setCntrServicoQuadro(IServicoQuadro *cntr) {
    cntrServicoQuadro = cntr;
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
        } else if (opcao == 2) {
            ler();
        } else if (opcao == 3) {
            atualizar(email);
        } else if (opcao == 4) {
            excluir(email);
        } else if (opcao == 5) {
            listar();
        } else if (opcao != 0) {
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
    if (!lerCampo("Identificador do projeto", DICA_PROJETO, projeto) ||
        !lerCampo("Identificador do quadro", DICA_QUADRO, identificador) ||
        !lerCampo("Nome", DICA_NOME, nome) ||
        !lerCampo("Limite WIP", DICA_LIMITE, limite)) {
        cancelado();
        return;
    }
    try {
        Quadro quadro;
        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);
        cntrServicoQuadro->criar(quadro, projeto, email);
        sucesso("Quadro criado com sucesso.");
    }
    catch (runtime_error &excecao) {
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
        Quadro quadro = cntrServicoQuadro->ler(identificador);
        cout << endl;
        saida("Identificador", quadro.getIdentificador().getValor());
        saida("Nome", quadro.getNome().getValor());
        saida("Limite WIP", to_string(quadro.getLimite().getValor()));
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoQuadro::atualizar(const EMAIL& email) {
    acao("Atualizar quadro");
    Identificador identificador;
    Nome nome;
    Limite limite;
    if (!lerCampo("Identificador do quadro", DICA_QUADRO, identificador) ||
        !lerCampo("Novo nome", DICA_NOME, nome) ||
        !lerCampo("Novo limite WIP", DICA_LIMITE, limite)) {
        cancelado();
        return;
    }
    try {
        Quadro quadro;
        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);
        cntrServicoQuadro->atualizar(quadro, email);
        sucesso("Quadro atualizado com sucesso.");
    }
    catch (runtime_error &excecao) {
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
        cntrServicoQuadro->excluir(identificador, email);
        sucesso("Quadro excluido com sucesso.");
    }
    catch (runtime_error &excecao) {
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
        vector<Identificador> identificadores = cntrServicoQuadro->listar(projeto);
        vector<string> itens;
        for (size_t i = 0; i < identificadores.size(); i++) {
            itens.push_back(identificadores[i].getValor());
        }
        cout << endl;
        listaItens(itens);
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::setCntrServicoCartao(IServicoCartao *cntr) {
    cntrServicoCartao = cntr;
}

void CntrApresentacaoCartao::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        titulo("CARTOES DE ATIVIDADE");
        secao("Cartoes");
        item(1, "Criar cartao");
        item(2, "Ler cartao");
        item(3, "Atualizar cartao");
        item(4, "Excluir cartao");
        item(5, "Listar cartoes de um quadro");
        item(6, "Mover cartao para a proxima coluna");
        secao("Metricas");
        item(7, "Tempo de ciclo de um cartao");
        item(8, "Tempo de ciclo medio de um quadro");
        item(9, "Lead time de um cartao");
        item(10, "Lead time medio de um quadro");
        item(11, "WIP de um quadro");
        linha();
        item(0, "Voltar");
        opcao = lerOpcao();
        if (opcao == 1) {
            criar(email);
        } else if (opcao == 2) {
            ler();
        } else if (opcao == 3) {
            atualizar(email);
        } else if (opcao == 4) {
            excluir(email);
        } else if (opcao == 5) {
            listar();
        } else if (opcao == 6) {
            mover();
        } else if (opcao == 7) {
            lerTempoCiclo();
        } else if (opcao == 8) {
            lerTempoCicloMedio();
        } else if (opcao == 9) {
            lerLeadTime();
        } else if (opcao == 10) {
            lerLeadTimeMedio();
        } else if (opcao == 11) {
            lerWIP();
        } else if (opcao != 0) {
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
    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro) ||
        !lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !lerCampo("Nome", DICA_NOME, nome) ||
        !lerCampo("Descricao", DICA_TEXTO, descricao) ||
        !lerCampo("Prioridade", DICA_PRIORIDADE, prioridade) ||
        !lerCampo("Tamanho", DICA_TAMANHO, tamanho) ||
        !lerCampo("Entrada em A FAZER", DICA_DATA, entrada)) {
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
        cntrServicoCartao->criar(cartao, quadro, email);
        sucesso("Cartao criado com sucesso na coluna A FAZER.");
    }
    catch (runtime_error &excecao) {
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
        CartaoAtividade cartao = cntrServicoCartao->ler(identificador);
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
        saida("Prioridade", cartao.getPrioridade().getValor());
        saida("Estado", cartao.getEstado().getValor());
        saida("Tamanho", cartao.getTamanho().getValor());
        saida("Entrada", cartao.getEntrada().getValor());
        saida("Inicio", inicio);
        saida("Termino", termino);
    }
    catch (runtime_error &excecao) {
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
    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !lerCampo("Novo nome", DICA_NOME, nome) ||
        !lerCampo("Nova descricao", DICA_TEXTO, descricao) ||
        !lerCampo("Nova prioridade", DICA_PRIORIDADE, prioridade) ||
        !lerCampo("Novo tamanho", DICA_TAMANHO, tamanho)) {
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
        cntrServicoCartao->atualizar(cartao, email);
        sucesso("Cartao atualizado com sucesso.");
    }
    catch (runtime_error &excecao) {
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
        cntrServicoCartao->excluir(identificador, email);
        sucesso("Cartao excluido com sucesso.");
    }
    catch (runtime_error &excecao) {
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
        vector<Identificador> identificadores = cntrServicoCartao->listar(quadro);
        vector<string> itens;
        for (size_t i = 0; i < identificadores.size(); i++) {
            itens.push_back(identificadores[i].getValor());
        }
        cout << endl;
        listaItens(itens);
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::mover() {
    acao("Mover cartao");
    Identificador identificador;
    Timestamp momento;
    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador) ||
        !lerCampo("Momento da movimentacao", DICA_DATA, momento)) {
        cancelado();
        return;
    }
    try {
        cntrServicoCartao->mover(identificador, momento);
        CartaoAtividade cartao = cntrServicoCartao->ler(identificador);
        sucesso("Cartao movido para " + cartao.getEstado().getValor() + ".");
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::lerTempoCiclo() {
    acao("Tempo de ciclo de um cartao");
    Identificador identificador;
    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        cancelado();
        return;
    }
    try {
        int tempo = cntrServicoCartao->lerTempoCiclo(identificador);
        cout << endl << "  Tempo de ciclo: " << tempo << " minutos." << endl;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::lerTempoCicloMedio() {
    acao("Tempo de ciclo medio de um quadro");
    Identificador quadro;
    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }
    try {
        double tempo = cntrServicoCartao->lerTempoCicloMedio(quadro);
        cout << endl << "  Tempo de ciclo medio: " << tempo << " minutos." << endl;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::lerLeadTime() {
    acao("Lead time de um cartao");
    Identificador identificador;
    if (!lerCampo("Identificador do cartao", DICA_CARTAO, identificador)) {
        cancelado();
        return;
    }
    try {
        int tempo = cntrServicoCartao->lerLeadTime(identificador);
        cout << endl << "  Lead time: " << tempo << " minutos." << endl;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::lerLeadTimeMedio() {
    acao("Lead time medio de um quadro");
    Identificador quadro;
    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }
    try {
        double tempo = cntrServicoCartao->lerLeadTimeMedio(quadro);
        cout << endl << "  Lead time medio: " << tempo << " minutos." << endl;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}

void CntrApresentacaoCartao::lerWIP() {
    acao("WIP de um quadro");
    Identificador quadro;
    if (!lerCampo("Identificador do quadro", DICA_QUADRO, quadro)) {
        cancelado();
        return;
    }
    try {
        int wip = cntrServicoCartao->lerWIP(quadro);
        cout << endl << "  WIP (cartoes em FAZENDO): " << wip << endl;
    }
    catch (runtime_error &excecao) {
        erro(excecao.what());
    }
}
