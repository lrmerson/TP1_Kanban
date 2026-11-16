#include "apresentacao/pessoas/cntr_apresentacao_pes.hpp"


namespace {

const string DICA_EMAIL = "letras minusculas, ex: ana@unb.br";

const string DICA_NOME = "ate 15 letras, ex: Ana Souza";

const string DICA_SENHA = "5 caracteres com letras e numeros, ex: abc12";

const string DICA_PAPEL = "GESTOR ou DESENVOLVEDOR";

}


void CntrApresentacaoPessoa::setCntrServicoPessoa(IServicoPessoa* servico) {

    cntrServicoPessoa = servico;
}


void CntrApresentacaoPessoa::cadastrar() {

    acao("Criar conta");

    EMAIL email;
    Nome nome;
    Senha senha;
    Papel papel;

    if (!lerCampo("E-mail", DICA_EMAIL, email) || !lerCampo("Nome", DICA_NOME, nome) || !lerCampo("Senha", DICA_SENHA, senha) || !lerCampo("Papel", DICA_PAPEL, papel)) {

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
    catch (runtime_error& excecao) {

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
        }
        else if (opcao == 2) {

            atualizar(email);
        }
        else if (opcao == 3) {

            if (excluir(email)) {

                return false;
            }
        }
        else if (opcao == 4) {

            listar();
        }
        else if (opcao != 0) {

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
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }
}


void CntrApresentacaoPessoa::atualizar(const EMAIL& email) {

    acao("Atualizar minha conta");

    cout << "   E-mail (nao pode ser alterado): " << email.getValor() << endl;

    Nome nome;
    Senha senha;
    Papel papel;

    if (!lerCampo("Novo nome", DICA_NOME, nome) || !lerCampo("Nova senha", DICA_SENHA, senha) || !lerCampo("Novo papel", DICA_PAPEL, papel)) {
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
    catch (runtime_error& excecao) {

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
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }

    return false;
}


void CntrApresentacaoPessoa::listar() {

    acao("Pessoas cadastradas", false);

    try {

        vector<EMAIL> emails = cntrServicoPessoa-> listar();

        vector<string> itens;

        for (size_t i = 0; i < emails.size(); i++) {
            itens.push_back(emails[i].getValor());
        }

        listaItens(itens);
    }
    catch (runtime_error& excecao) {
        erro(excecao.what());
    }
}
