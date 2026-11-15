#ifndef CNTR_SERVICO_PRO_HPP_INCLUDED
#define CNTR_SERVICO_PRO_HPP_INCLUDED

#include <stdexcept>
#include <vector>

#include "interfaces/servico/interfaces_servico.hpp"

#include "servico/pessoas/container_pes.hpp"
#include "servico/projetos/container_pro.hpp"
#include "servico/kanban/container_qua.hpp"

using namespace std;

/**
 * @brief Implementa os serviços de gerenciamento de projetos.
 */
class CntrServicoProjeto : public IServicoProjeto {
    private:

        /**
         * @brief Verifica se a pessoa informada é gestora do projeto.
         *
         * @param identificador Identificador do projeto.
         * @param gestor E-mail da pessoa que solicita a operação.
         */
        void verificarGestor(
            const Identificador& identificador,
            const EMAIL& gestor
        );

    public:

        /** @copydoc IServicoProjeto::criar */
        void criar(
            const Projeto& projeto,
            const EMAIL& gestor
        ) override;

        /** @copydoc IServicoProjeto::ler */
        Projeto ler(
            const Identificador& identificador
        ) override;

        /** @copydoc IServicoProjeto::atualizar */
        void atualizar(
            const Projeto& projeto,
            const EMAIL& gestor
        ) override;

        /** @copydoc IServicoProjeto::excluir */
        void excluir(
            const Identificador& identificador,
            const EMAIL& gestor
        ) override;

        /** @copydoc IServicoProjeto::listar */
        vector<Identificador> listar() override;
};

#endif // CNTR_SERVICO_PRO_HPP_INCLUDED
