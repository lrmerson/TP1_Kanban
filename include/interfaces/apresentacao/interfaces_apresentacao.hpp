#ifndef INTERFACES_APRESENTACAO_HPP_INCLUDED
#define INTERFACES_APRESENTACAO_HPP_INCLUDED

#include "dominio/dominios.hpp"

class IServicoAutenticacao;
class IServicoPessoa;
class IServicoProjeto;
class IServicoKanban;


/**
 * @brief Interface da apresentação de autenticação.
 */
class IApresentacaoAutenticacao {
    public:

        /**
         * @brief Executa o processo de autenticação.
         *
         * @param email Recebe o e-mail da pessoa autenticada.
         * @return true se a autenticação for realizada.
         */
        virtual bool autenticar(EMAIL* email) = 0;

        /**
         * @brief Define o serviço de autenticação utilizado.
         */
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao* servico) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IApresentacaoAutenticacao() {}
};


/**
 * @brief Interface da apresentação de pessoas.
 */
class IApresentacaoPessoa {
    public:

        /**
         * @brief Executa o cadastro de uma nova pessoa.
         */
        virtual void cadastrar() = 0;

        /**
         * @brief Executa o menu de serviços de pessoa.
         *
         * @param email Pessoa atualmente autenticada.
         * @return false quando a própria conta for excluída.
         */
        virtual bool executar(const EMAIL& email) = 0;

        /**
         * @brief Define o serviço de pessoas utilizado.
         */
        virtual void setCntrServicoPessoa(IServicoPessoa* servico) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IApresentacaoPessoa() {}
};


/**
 * @brief Interface da apresentação de projetos.
 */
class IApresentacaoProjeto {
    public:

        /**
         * @brief Executa o menu de serviços de projeto.
         */
        virtual void executar(const EMAIL& email) = 0;

        /**
         * @brief Define o serviço de projetos utilizado.
         */
        virtual void setCntrServicoProjeto(IServicoProjeto* servico) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IApresentacaoProjeto() {}
};


/**
 * @brief Interface da apresentação do subsistema Kanban.
 */
class IApresentacaoKanban {
    public:

        /**
         * @brief Executa o menu do subsistema Kanban.
         */
        virtual void executar(const EMAIL& email) = 0;

        /**
         * @brief Define o serviço Kanban utilizado.
         */
        virtual void setCntrServicoKanban(IServicoKanban* servico) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IApresentacaoKanban() {}
};

#endif // INTERFACES_APRESENTACAO_HPP_INCLUDED
