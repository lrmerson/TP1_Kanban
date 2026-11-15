#ifndef CNTR_APRESENTACAO_AUT_HPP_INCLUDED
#define CNTR_APRESENTACAO_AUT_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"
#include "interfaces/servico/interfaces_servico.hpp"

using namespace std;

/**
 * @brief Controla a interface com o usuário para autenticação.
 */
class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao* cntrServicoAutenticacao;
    public:

        /**
         * @copydoc IApresentacaoAutenticacao::autenticar
         */
        bool autenticar(EMAIL* email) override;

        /**
         * @copydoc IApresentacaoAutenticacao::setCntrServicoAutenticacao
         */
        void setCntrServicoAutenticacao(IServicoAutenticacao* servico) override;
};

#endif // CNTR_APRESENTACAO_AUT_HPP_INCLUDED
