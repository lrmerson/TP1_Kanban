#ifndef CNTR_APRESENTACAO_PRO_HPP_INCLUDED
#define CNTR_APRESENTACAO_PRO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"
#include "interfaces/servico/interfaces_servico.hpp"

using namespace std;

/**
 * @brief Controla a interface com o usuário para serviços de projetos.
 */
class CntrApresentacaoProjeto : public IApresentacaoProjeto {

    private:
        IServicoProjeto* cntrServicoProjeto;

        void criar(const EMAIL& email);

        void ler();

        void atualizar(const EMAIL& email);

        void excluir(const EMAIL& email);

        void listar();

    public:

        /**
         * @copydoc IApresentacaoProjeto::executar
         */
        void executar(const EMAIL& email) override;

        /**
         * @copydoc IApresentacaoProjeto::setCntrServicoProjeto
         */
        void setCntrServicoProjeto(IServicoProjeto* servico) override;
};

#endif // CNTR_APRESENTACAO_PRO_HPP_INCLUDED
