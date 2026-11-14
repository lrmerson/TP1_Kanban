#ifndef CNTR_SERVICO_AUT_HPP_INCLUDED
#define CNTR_SERVICO_AUT_HPP_INCLUDED

#include "interfaces/servico/interfaces_servico.hpp"
#include "servico/pessoas/container_pes.hpp"

/**
 * @brief Implementa os serviços de autenticação de usuários.
 */
class CntrServicoAutenticacao : public IServicoAutenticacao {
    public:

        /**
         * @copydoc IServicoAutenticacao::autenticar
         */
        bool autenticar(
            const EMAIL& email,
            const Senha& senha
        ) override;
};

#endif // CNTR_SERVICO_AUT_HPP_INCLUDED
