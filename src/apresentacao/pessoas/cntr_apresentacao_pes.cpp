#include "apresentacao/pessoas/cntr_apresentacao_pes.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


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
    SaidaUsuario::acao("Criar conta");

    EMAIL email;
    Nome nome;
    Senha senha;
    Papel papel;

    if (!EntradaUsuario::lerCampo("E-mail", DICA_EMAIL, email) ||
        !EntradaUsuario::lerCampo("Nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Senha", DICA_SENHA, senha) ||
        !EntradaUsuario::lerCampo("Papel", DICA_PAPEL, papel)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Pessoa pessoa;

        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        cntrServicoPessoa->criar(pessoa);

        SaidaUsuario::sucesso("Conta criada com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


bool CntrApresentacaoPessoa::executar(const EMAIL& email) {
    int opcao = -1;

    while (opcao != 0) {
        SaidaUsuario::titulo("PESSOAS");

        SaidaUsuario::item(1, "Ler pessoa");
        SaidaUsuario::item(2, "Atualizar minha conta");
        SaidaUsuario::item(3, "Excluir minha conta");
        SaidaUsuario::item(4, "Listar pessoas");
        SaidaUsuario::item(0, "Voltar");

        SaidaUsuario::separador();
        opcao = EntradaUsuario::lerOpcao();

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
            SaidaUsuario::aviso("Opcao invalida. Digite um dos numeros do menu.");
        }
    }

    return true;
}


void CntrApresentacaoPessoa::ler() {
    SaidaUsuario::acao("Ler pessoa");

    EMAIL email;

    if (!EntradaUsuario::lerCampo("E-mail da pessoa", DICA_EMAIL, email)) {
        SaidaUsuario::cancelado();
        return;
    }

    try {
        Pessoa pessoa = cntrServicoPessoa->ler(email);

        cout << endl;

        SaidaUsuario::saida("E-mail", pessoa.getEmail().getValor());
        SaidaUsuario::saida("Nome", pessoa.getNome().getValor());
        SaidaUsuario::saida("Papel", pessoa.getPapel().getValor());
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


void CntrApresentacaoPessoa::atualizar(const EMAIL& email) {
    SaidaUsuario::acao("Atualizar minha conta");

    cout << "   E-mail (nao pode ser alterado): " << email.getValor() << endl;

    Nome nome;
    Senha senha;
    Papel papel;

    if (!EntradaUsuario::lerCampo("Novo nome", DICA_NOME, nome) ||
        !EntradaUsuario::lerCampo("Nova senha", DICA_SENHA, senha) ||
        !EntradaUsuario::lerCampo("Novo papel", DICA_PAPEL, papel)) {

        SaidaUsuario::cancelado();
        return;
    }

    try {
        Pessoa pessoa;

        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        cntrServicoPessoa->atualizar(pessoa);

        SaidaUsuario::sucesso("Conta atualizada com sucesso.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}


bool CntrApresentacaoPessoa::excluir(const EMAIL& email) {
    SaidaUsuario::acao("Excluir minha conta", false);

    string resposta = EntradaUsuario::lerLinha("  Tem certeza que deseja excluir sua conta? (S/N): ");

    if (resposta != "S" && resposta != "s") {
        SaidaUsuario::cancelado();
        return false;
    }

    try {
        cntrServicoPessoa->excluir(email);

        SaidaUsuario::sucesso("Conta excluida com sucesso.");

        return true;
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }

    return false;
}


void CntrApresentacaoPessoa::listar() {
    SaidaUsuario::acao("Pessoas cadastradas", false);

    try {
        vector<EMAIL> emails = cntrServicoPessoa->listar();

        vector<string> itens;

        for (size_t i = 0; i < emails.size(); i++) {
            itens.push_back(emails[i].getValor());
        }

        SaidaUsuario::listaItens(itens);
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }
}
