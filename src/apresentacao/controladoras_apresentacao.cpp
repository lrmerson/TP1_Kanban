#include "apresentacao/controladoras_apresentacao.hpp"
#include <cstdlib>
#include <cctype>

string lerLinha(string rotulo) {
    string texto;
    cout << rotulo;
    if (!getline(cin, texto)) {
        cout << endl;
        exit(0);
    }
    return texto;
}

int lerNumero(string rotulo) {
    string texto = lerLinha(rotulo);
    if (texto.size() == 0 || texto.size() > 9) {
        return -1;
    }
    for (int i = 0; i < texto.size(); i++) {
        if (!isdigit(texto[i])) {
            return -1;
        }
    }
    return stoi(texto);
}

///////////////////////////////////////////////////////////////////////////////

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
        cout << endl << "===== SISTEMA KANBAN =====" << endl;
        cout << "1 - Autenticar" << endl;
        cout << "2 - Criar conta" << endl;
        cout << "0 - Sair" << endl;
        opcao = lerNumero("Opcao: ");
        if (opcao == 1) {
            EMAIL email;
            if (cntrApresentacaoPessoa->autenticar(&email)) {
                cout << "Autenticacao realizada com sucesso." << endl;
                menuServicos(email);
            } else {
                cout << "Falha na autenticacao." << endl;
            }
        } else if (opcao == 2) {
            cntrApresentacaoPessoa->cadastrar();
        } else if (opcao != 0) {
            cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoControle::menuServicos(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        cout << endl << "===== MENU PRINCIPAL (" << email.getValor() << ") =====" << endl;
        cout << "1 - Pessoas" << endl;
        cout << "2 - Projetos" << endl;
        cout << "3 - Quadros" << endl;
        cout << "4 - Cartoes de atividade" << endl;
        cout << "0 - Sair da conta" << endl;
        opcao = lerNumero("Opcao: ");
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
            cout << "Opcao invalida." << endl;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

void CntrApresentacaoPessoa::setCntrServicoPessoa(IServicoPessoa *cntr) {
    cntrServicoPessoa = cntr;
}

bool CntrApresentacaoPessoa::autenticar(EMAIL *email) {
    cout << endl << "===== AUTENTICACAO =====" << endl;
    try {
        Senha senha;
        email->setValor(lerLinha("Email: "));
        senha.setValor(lerLinha("Senha: "));
        return cntrServicoPessoa->autenticar(*email, senha);
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    return false;
}

void CntrApresentacaoPessoa::cadastrar() {
    cout << endl << "===== CRIAR CONTA =====" << endl;
    try {
        EMAIL email;
        Nome nome;
        Senha senha;
        Papel papel;
        email.setValor(lerLinha("Email: "));
        nome.setValor(lerLinha("Nome: "));
        senha.setValor(lerLinha("Senha: "));
        papel.setValor(lerLinha("Papel (GESTOR ou DESENVOLVEDOR): "));
        Pessoa pessoa;
        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);
        cntrServicoPessoa->criar(pessoa);
        cout << "Conta criada com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

bool CntrApresentacaoPessoa::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        cout << endl << "===== PESSOAS =====" << endl;
        cout << "1 - Ler pessoa" << endl;
        cout << "2 - Atualizar minha conta" << endl;
        cout << "3 - Excluir minha conta" << endl;
        cout << "4 - Listar pessoas" << endl;
        cout << "0 - Voltar" << endl;
        opcao = lerNumero("Opcao: ");
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
            cout << "Opcao invalida." << endl;
        }
    }
    return true;
}

void CntrApresentacaoPessoa::ler() {
    try {
        EMAIL email;
        email.setValor(lerLinha("Email da pessoa: "));
        Pessoa pessoa = cntrServicoPessoa->ler(email);
        cout << "Email: " << pessoa.getEmail().getValor() << endl;
        cout << "Nome: " << pessoa.getNome().getValor() << endl;
        cout << "Papel: " << pessoa.getPapel().getValor() << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoPessoa::atualizar(const EMAIL& email) {
    try {
        Nome nome;
        Senha senha;
        Papel papel;
        cout << "Email (nao pode ser alterado): " << email.getValor() << endl;
        nome.setValor(lerLinha("Novo nome: "));
        senha.setValor(lerLinha("Nova senha: "));
        papel.setValor(lerLinha("Novo papel (GESTOR ou DESENVOLVEDOR): "));
        Pessoa pessoa;
        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);
        cntrServicoPessoa->atualizar(pessoa);
        cout << "Conta atualizada com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

bool CntrApresentacaoPessoa::excluir(const EMAIL& email) {
    string resposta = lerLinha("Confirma exclusao da conta? (S/N): ");
    if (resposta != "S" && resposta != "s") {
        return false;
    }
    try {
        cntrServicoPessoa->excluir(email);
        cout << "Conta excluida com sucesso." << endl;
        return true;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
    return false;
}

void CntrApresentacaoPessoa::listar() {
    vector<EMAIL> emails = cntrServicoPessoa->listar();
    cout << "Pessoas cadastradas:" << endl;
    for (int i = 0; i < emails.size(); i++) {
        cout << "- " << emails[i].getValor() << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////

void CntrApresentacaoProjeto::setCntrServicoProjeto(IServicoProjeto *cntr) {
    cntrServicoProjeto = cntr;
}

void CntrApresentacaoProjeto::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        cout << endl << "===== PROJETOS =====" << endl;
        cout << "1 - Criar projeto" << endl;
        cout << "2 - Ler projeto" << endl;
        cout << "3 - Atualizar projeto" << endl;
        cout << "4 - Excluir projeto" << endl;
        cout << "5 - Listar projetos" << endl;
        cout << "0 - Voltar" << endl;
        opcao = lerNumero("Opcao: ");
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
            cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoProjeto::criar(const EMAIL& email) {
    try {
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
        identificador.setValor(lerLinha("Identificador (ex: PRJ001): "));
        nome.setValor(lerLinha("Nome: "));
        descricao.setValor(lerLinha("Descricao: "));
        inicio.setValor(lerLinha("Inicio (DIA-MES-ANO-HH:MM): "));
        termino.setValor(lerLinha("Termino (DIA-MES-ANO-HH:MM): "));
        Projeto projeto;
        projeto.setIdentificador(identificador);
        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
        cntrServicoProjeto->criar(projeto, email);
        cout << "Projeto criado com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoProjeto::ler() {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do projeto: "));
        Projeto projeto = cntrServicoProjeto->ler(identificador);
        cout << "Identificador: " << projeto.getIdentificador().getValor() << endl;
        cout << "Nome: " << projeto.getNome().getValor() << endl;
        cout << "Descricao: " << projeto.getDescricao().getValor() << endl;
        cout << "Inicio: " << projeto.getInicio().getValor() << endl;
        cout << "Termino: " << projeto.getTermino().getValor() << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoProjeto::atualizar(const EMAIL& email) {
    try {
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
        identificador.setValor(lerLinha("Identificador do projeto (nao pode ser alterado): "));
        nome.setValor(lerLinha("Novo nome: "));
        descricao.setValor(lerLinha("Nova descricao: "));
        inicio.setValor(lerLinha("Novo inicio (DIA-MES-ANO-HH:MM): "));
        termino.setValor(lerLinha("Novo termino (DIA-MES-ANO-HH:MM): "));
        Projeto projeto;
        projeto.setIdentificador(identificador);
        projeto.setNome(nome);
        projeto.setDescricao(descricao);
        projeto.setInicio(inicio);
        projeto.setTermino(termino);
        cntrServicoProjeto->atualizar(projeto, email);
        cout << "Projeto atualizado com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoProjeto::excluir(const EMAIL& email) {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do projeto: "));
        cntrServicoProjeto->excluir(identificador, email);
        cout << "Projeto excluido com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoProjeto::listar() {
    vector<Identificador> identificadores = cntrServicoProjeto->listar();
    cout << "Projetos cadastrados:" << endl;
    for (int i = 0; i < identificadores.size(); i++) {
        cout << "- " << identificadores[i].getValor() << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////

void CntrApresentacaoQuadro::setCntrServicoQuadro(IServicoQuadro *cntr) {
    cntrServicoQuadro = cntr;
}

void CntrApresentacaoQuadro::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        cout << endl << "===== QUADROS =====" << endl;
        cout << "1 - Criar quadro" << endl;
        cout << "2 - Ler quadro" << endl;
        cout << "3 - Atualizar quadro" << endl;
        cout << "4 - Excluir quadro" << endl;
        cout << "5 - Listar quadros de um projeto" << endl;
        cout << "0 - Voltar" << endl;
        opcao = lerNumero("Opcao: ");
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
            cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoQuadro::criar(const EMAIL& email) {
    try {
        Identificador projeto;
        Identificador identificador;
        Nome nome;
        Limite limite;
        projeto.setValor(lerLinha("Identificador do projeto: "));
        identificador.setValor(lerLinha("Identificador do quadro (ex: QDR001): "));
        nome.setValor(lerLinha("Nome: "));
        limite.setValor(lerNumero("Limite WIP (1 a 25): "));
        Quadro quadro;
        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);
        cntrServicoQuadro->criar(quadro, projeto, email);
        cout << "Quadro criado com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoQuadro::ler() {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do quadro: "));
        Quadro quadro = cntrServicoQuadro->ler(identificador);
        cout << "Identificador: " << quadro.getIdentificador().getValor() << endl;
        cout << "Nome: " << quadro.getNome().getValor() << endl;
        cout << "Limite WIP: " << quadro.getLimite().getValor() << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoQuadro::atualizar(const EMAIL& email) {
    try {
        Identificador identificador;
        Nome nome;
        Limite limite;
        identificador.setValor(lerLinha("Identificador do quadro (nao pode ser alterado): "));
        nome.setValor(lerLinha("Novo nome: "));
        limite.setValor(lerNumero("Novo limite WIP (1 a 25): "));
        Quadro quadro;
        quadro.setIdentificador(identificador);
        quadro.setNome(nome);
        quadro.setLimite(limite);
        cntrServicoQuadro->atualizar(quadro, email);
        cout << "Quadro atualizado com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoQuadro::excluir(const EMAIL& email) {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do quadro: "));
        cntrServicoQuadro->excluir(identificador, email);
        cout << "Quadro excluido com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoQuadro::listar() {
    try {
        Identificador projeto;
        projeto.setValor(lerLinha("Identificador do projeto: "));
        vector<Identificador> identificadores = cntrServicoQuadro->listar(projeto);
        cout << "Quadros do projeto:" << endl;
        for (int i = 0; i < identificadores.size(); i++) {
            cout << "- " << identificadores[i].getValor() << endl;
        }
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////

void CntrApresentacaoCartao::setCntrServicoCartao(IServicoCartao *cntr) {
    cntrServicoCartao = cntr;
}

void CntrApresentacaoCartao::executar(const EMAIL& email) {
    int opcao = -1;
    while (opcao != 0) {
        cout << endl << "===== CARTOES DE ATIVIDADE =====" << endl;
        cout << "1 - Criar cartao" << endl;
        cout << "2 - Ler cartao" << endl;
        cout << "3 - Atualizar cartao" << endl;
        cout << "4 - Excluir cartao" << endl;
        cout << "5 - Listar cartoes de um quadro" << endl;
        cout << "6 - Mover cartao" << endl;
        cout << "7 - Ler tempo de ciclo" << endl;
        cout << "8 - Ler tempo de ciclo medio" << endl;
        cout << "9 - Ler lead time" << endl;
        cout << "10 - Ler lead time medio" << endl;
        cout << "11 - Ler WIP" << endl;
        cout << "0 - Voltar" << endl;
        opcao = lerNumero("Opcao: ");
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
            cout << "Opcao invalida." << endl;
        }
    }
}

void CntrApresentacaoCartao::criar(const EMAIL& email) {
    try {
        Identificador quadro;
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Tamanho tamanho;
        Timestamp entrada;
        quadro.setValor(lerLinha("Identificador do quadro: "));
        identificador.setValor(lerLinha("Identificador do cartao (ex: CRT001): "));
        nome.setValor(lerLinha("Nome: "));
        descricao.setValor(lerLinha("Descricao: "));
        prioridade.setValor(lerLinha("Prioridade (ALTA, MEDIA ou BAIXA): "));
        tamanho.setValor(lerLinha("Tamanho (GRANDE, MEDIO ou PEQUENO): "));
        entrada.setValor(lerLinha("Entrada em A FAZER (DIA-MES-ANO-HH:MM): "));
        CartaoAtividade cartao;
        cartao.setIdentificador(identificador);
        cartao.setNome(nome);
        cartao.setDescricao(descricao);
        cartao.setPrioridade(prioridade);
        cartao.setTamanho(tamanho);
        cartao.setEntrada(entrada);
        cntrServicoCartao->criar(cartao, quadro, email);
        cout << "Cartao criado com sucesso na coluna A FAZER." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::ler() {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do cartao: "));
        CartaoAtividade cartao = cntrServicoCartao->ler(identificador);
        string inicio = cartao.getInicio().getValor();
        string termino = cartao.getTermino().getValor();
        if (inicio == "") {
            inicio = "-";
        }
        if (termino == "") {
            termino = "-";
        }
        cout << "Identificador: " << cartao.getIdentificador().getValor() << endl;
        cout << "Nome: " << cartao.getNome().getValor() << endl;
        cout << "Descricao: " << cartao.getDescricao().getValor() << endl;
        cout << "Prioridade: " << cartao.getPrioridade().getValor() << endl;
        cout << "Estado: " << cartao.getEstado().getValor() << endl;
        cout << "Tamanho: " << cartao.getTamanho().getValor() << endl;
        cout << "Entrada: " << cartao.getEntrada().getValor() << endl;
        cout << "Inicio: " << inicio << endl;
        cout << "Termino: " << termino << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::atualizar(const EMAIL& email) {
    try {
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Tamanho tamanho;
        identificador.setValor(lerLinha("Identificador do cartao (nao pode ser alterado): "));
        nome.setValor(lerLinha("Novo nome: "));
        descricao.setValor(lerLinha("Nova descricao: "));
        prioridade.setValor(lerLinha("Nova prioridade (ALTA, MEDIA ou BAIXA): "));
        tamanho.setValor(lerLinha("Novo tamanho (GRANDE, MEDIO ou PEQUENO): "));
        CartaoAtividade cartao;
        cartao.setIdentificador(identificador);
        cartao.setNome(nome);
        cartao.setDescricao(descricao);
        cartao.setPrioridade(prioridade);
        cartao.setTamanho(tamanho);
        cntrServicoCartao->atualizar(cartao, email);
        cout << "Cartao atualizado com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::excluir(const EMAIL& email) {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do cartao: "));
        cntrServicoCartao->excluir(identificador, email);
        cout << "Cartao excluido com sucesso." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::listar() {
    try {
        Identificador quadro;
        quadro.setValor(lerLinha("Identificador do quadro: "));
        vector<Identificador> identificadores = cntrServicoCartao->listar(quadro);
        cout << "Cartoes do quadro:" << endl;
        for (int i = 0; i < identificadores.size(); i++) {
            cout << "- " << identificadores[i].getValor() << endl;
        }
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::mover() {
    try {
        Identificador identificador;
        Timestamp momento;
        identificador.setValor(lerLinha("Identificador do cartao: "));
        momento.setValor(lerLinha("Momento da movimentacao (DIA-MES-ANO-HH:MM): "));
        cntrServicoCartao->mover(identificador, momento);
        CartaoAtividade cartao = cntrServicoCartao->ler(identificador);
        cout << "Cartao movido para " << cartao.getEstado().getValor() << "." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::lerTempoCiclo() {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do cartao: "));
        int tempo = cntrServicoCartao->lerTempoCiclo(identificador);
        cout << "Tempo de ciclo: " << tempo << " minutos." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::lerTempoCicloMedio() {
    try {
        Identificador quadro;
        quadro.setValor(lerLinha("Identificador do quadro: "));
        double tempo = cntrServicoCartao->lerTempoCicloMedio(quadro);
        cout << "Tempo de ciclo medio: " << tempo << " minutos." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::lerLeadTime() {
    try {
        Identificador identificador;
        identificador.setValor(lerLinha("Identificador do cartao: "));
        int tempo = cntrServicoCartao->lerLeadTime(identificador);
        cout << "Lead time: " << tempo << " minutos." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::lerLeadTimeMedio() {
    try {
        Identificador quadro;
        quadro.setValor(lerLinha("Identificador do quadro: "));
        double tempo = cntrServicoCartao->lerLeadTimeMedio(quadro);
        cout << "Lead time medio: " << tempo << " minutos." << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}

void CntrApresentacaoCartao::lerWIP() {
    try {
        Identificador quadro;
        quadro.setValor(lerLinha("Identificador do quadro: "));
        int wip = cntrServicoCartao->lerWIP(quadro);
        cout << "WIP (cartoes em FAZENDO): " << wip << endl;
    }
    catch (invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << endl;
    }
    catch (runtime_error &excecao) {
        cout << "Erro: " << excecao.what() << endl;
    }
}
