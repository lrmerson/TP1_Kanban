#ifndef CNTR_APRESENTACAO_PES_HPP_INCLUDED
#define CNTR_APRESENTACAO_PES_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"
#include "interfaces/servico/interfaces_servico.hpp"

using namespace std;

/**
 * @brief Controla a interface com o usuário para serviços de pessoas.
 */
class CntrApresentacaoPessoa : public IApresentacaoPessoa {
    private:
        IServicoPessoa* cntrServicoPessoa;

        void ler();

        void atualizar(const EMAIL& email);

        bool excluir(const EMAIL& email);

        void listar();

    public:

        /**
         * @copydoc IApresentacaoPessoa::cadastrar
         */
        void cadastrar() override;

        /**
         * @copydoc IApresentacaoPessoa::executar
         */
        bool executar(const EMAIL& email) override;

        /**
         * @copydoc IApresentacaoPessoa::setCntrServicoPessoa
         */
        void setCntrServicoPessoa(IServicoPessoa* servico) override;
};

#endif // CNTR_APRESENTACAO_PES_HPP_INCLUDED
