#ifndef CNTR_APRESENTACAO_IC_HPP_INCLUDED
#define CNTR_APRESENTACAO_IC_HPP_INCLUDED

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"

/**
 * @brief Controla a inicialização e a navegação do sistema.
 */
class CntrApresentacaoInicializacao {
    private:
        IApresentacaoAutenticacao* cntrApresentacaoAutenticacao;
        IApresentacaoPessoa* cntrApresentacaoPessoa;
        IApresentacaoProjeto* cntrApresentacaoProjeto;
        IApresentacaoKanban* cntrApresentacaoKanban;

        void menuServicos(const EMAIL& email);

    public:
        /**
         * @brief Inicia a aplicação e exibe o menu principal.
         */
        void executar();

        /**
         * @brief Define a controladora de autenticação.
         * @param cntr Controladora de autenticação.
         */
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr);

        /**
         * @brief Define a controladora de pessoas.
         * @param cntr Controladora de pessoas.
         */
        void setCntrApresentacaoPessoa(IApresentacaoPessoa* cntr);

        /**
         * @brief Define a controladora de projetos.
         * @param cntr Controladora de projetos.
         */
        void setCntrApresentacaoProjeto(IApresentacaoProjeto* cntr);

        /**
         * @brief Define a controladora Kanban.
         * @param cntr Controladora do subsistema Kanban.
         */
        void setCntrApresentacaoKanban(IApresentacaoKanban* cntr);
};

#endif // CNTR_APRESENTACAO_IC_HPP_INCLUDED
