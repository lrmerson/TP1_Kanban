#ifndef CONTROLADORAS_SERVICO_HPP_INCLUDED
#define CONTROLADORAS_SERVICO_HPP_INCLUDED

#include <stdexcept>

#include "interfaces/interfaces.hpp"
#include "servico/containers.hpp"

using namespace std;

/** @brief Implementa os serviços de autenticação e gerenciamento de pessoas. */
class CntrServicoPessoa : public IServicoPessoa {
    public:
        /** @copydoc IServicoPessoa::autenticar */
        bool autenticar(const EMAIL& email, const Senha& senha) override;
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

/** @brief Implementa os serviços de gerenciamento de projetos. */
class CntrServicoProjeto : public IServicoProjeto {
    private:
        void verificarGestor(const Identificador&, const EMAIL&);

    public:
        /** @copydoc IServicoProjeto::criar */
        void criar(const Projeto& projeto, const EMAIL& gestor) override;
        /** @copydoc IServicoProjeto::ler */
        Projeto ler(const Identificador& identificador) override;
        /** @copydoc IServicoProjeto::atualizar */
        void atualizar(const Projeto& projeto, const EMAIL& gestor) override;
        /** @copydoc IServicoProjeto::excluir */
        void excluir(const Identificador& identificador, const EMAIL& gestor) override;
        /** @copydoc IServicoProjeto::listar */
        vector<Identificador> listar() override;
};

/** @brief Implementa os serviços de gerenciamento de quadros. */
class CntrServicoQuadro : public IServicoQuadro {
    private:
        void verificarGestor(const string&, const EMAIL&);

    public:
        /** @copydoc IServicoQuadro::criar */
        void criar(const Quadro& quadro, const Identificador& projeto, const EMAIL& gestor) override;
        /** @copydoc IServicoQuadro::ler */
        Quadro ler(const Identificador& identificador) override;
        /** @copydoc IServicoQuadro::atualizar */
        void atualizar(const Quadro& quadro, const EMAIL& gestor) override;
        /** @copydoc IServicoQuadro::excluir */
        void excluir(const Identificador& identificador, const EMAIL& gestor) override;
        /** @copydoc IServicoQuadro::listar */
        vector<Identificador> listar(const Identificador& projeto) override;
};

/** @brief Implementa cartões, movimentações e métricas de fluxo Kanban. */
class CntrServicoCartao : public IServicoCartao {
    private:
        void verificarGestor(const string&, const EMAIL&);
        int converterMinutos(const Timestamp&);
        int contarFazendo(const string&);

    public:
        /** @copydoc IServicoCartao::criar */
        void criar(const CartaoAtividade& cartao, const Identificador& quadro, const EMAIL& gestor) override;
        /** @copydoc IServicoCartao::ler */
        CartaoAtividade ler(const Identificador& identificador) override;
        /** @copydoc IServicoCartao::atualizar */
        void atualizar(const CartaoAtividade& cartao, const EMAIL& gestor) override;
        /** @copydoc IServicoCartao::excluir */
        void excluir(const Identificador& identificador, const EMAIL& gestor) override;
        /** @copydoc IServicoCartao::listar */
        vector<Identificador> listar(const Identificador& quadro) override;
        /** @copydoc IServicoCartao::mover */
        void mover(const Identificador& identificador, const Timestamp& momento) override;
        /** @copydoc IServicoCartao::lerTempoCiclo */
        int lerTempoCiclo(const Identificador& identificador) override;
        /** @copydoc IServicoCartao::lerTempoCicloMedio */
        double lerTempoCicloMedio(const Identificador& quadro) override;
        /** @copydoc IServicoCartao::lerLeadTime */
        int lerLeadTime(const Identificador& identificador) override;
        /** @copydoc IServicoCartao::lerLeadTimeMedio */
        double lerLeadTimeMedio(const Identificador& quadro) override;
        /** @copydoc IServicoCartao::lerWIP */
        int lerWIP(const Identificador& quadro) override;
};

#endif // CONTROLADORAS_SERVICO_HPP_INCLUDED
