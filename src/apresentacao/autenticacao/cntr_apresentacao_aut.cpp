#include "apresentacao/autenticacao/cntr_apresentacao_aut.hpp"
#include "apresentacao/utilitarios_apresentacao.hpp"


void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao* servico) {
    cntrServicoAutenticacao = servico;
}


bool CntrApresentacaoAutenticacao::autenticar(EMAIL* email) {

    const string DICA_EMAIL = "letras minusculas, ex: ana@unb.br";

    const string DICA_SENHA = "5 caracteres com letras e numeros, ex: abc12";

    acao("Entrar");

    Senha senha;

    if (!lerCampo("E-mail", DICA_EMAIL, *email) || !lerCampo("Senha", DICA_SENHA, senha)) {

        cancelado();

        return false;
    }

    try {

        if (cntrServicoAutenticacao->autenticar(*email, senha)) {

            return true;
        }

        erro("E-mail ou senha incorretos.");
    }
    catch (runtime_error& excecao) {

        erro(excecao.what());
    }

    return false;
}
