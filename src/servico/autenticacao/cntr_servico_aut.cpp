#include "servico/autenticacao/cntr_servico_aut.hpp"

bool CntrServicoAutenticacao::autenticar(
    const EMAIL& email,
    const Senha& senha
) {
    Pessoa pessoa;

    pessoa.setEmail(email);

    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)) {
        return false;
    }

    if (pessoa.getSenha().getValor() != senha.getValor()) {
        return false;
    }

    return true;
}
