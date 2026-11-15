#ifndef CNTR_SERVICO_PES_HPP_INCLUDED
#define CNTR_SERVICO_PES_HPP_INCLUDED

#include <stdexcept>
#include <vector>

#include "interfaces/servico/interfaces_servico.hpp"

#include "servico/pessoas/container_pes.hpp"
#include "servico/projetos/container_pro.hpp"
#include "servico/kanban/container_car.hpp"

using namespace std;

/**
 * @brief Implementa os serviços de gerenciamento de pessoas.
 */
class CntrServicoPessoa : public IServicoPessoa {
    public:

        /** @copydoc IServicoPessoa::criar */
        void criar(const Pessoa& pessoa) override;

        /** @copydoc IServicoPessoa::ler */
        Pessoa ler(const EMAIL& email) override;

        /** @copydoc IServicoPessoa::atualizar */
        void atualizar(const Pessoa& pessoa) override;

        /** @copydoc IServicoPessoa::excluir */
        void excluir(const EMAIL& email) override;

        /** @copydoc IServicoPessoa::listar */
        vector<EMAIL> listar() override;
};

#endif // CNTR_SERVICO_PES_HPP_INCLUDED
