#include "apresentacao/autenticacao/cntr_apresentacao_aut.hpp"

#include "apresentacao/entrada_usuario.hpp"
#include "apresentacao/saida_usuario.hpp"


void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao* servico) {
    cntrServicoAutenticacao = servico;
}


bool CntrApresentacaoAutenticacao::autenticar(EMAIL* email) {
    const string DICA_EMAIL = "letras minusculas, ex: ana@unb.br";
    const string DICA_SENHA = "5 caracteres com letras e numeros, ex: abc12";

    SaidaUsuario::acao("Entrar");

    Senha senha;

    if (!EntradaUsuario::lerCampo("E-mail", DICA_EMAIL, *email) ||
        !EntradaUsuario::lerCampo("Senha", DICA_SENHA, senha)) {

        SaidaUsuario::cancelado();
        return false;
    }

    try {
        if (cntrServicoAutenticacao->autenticar(*email, senha)) {
            return true;
        }

        SaidaUsuario::erro("E-mail ou senha incorretos.");
    }
    catch (runtime_error& excecao) {
        SaidaUsuario::erro(excecao.what());
    }

    return false;
}
