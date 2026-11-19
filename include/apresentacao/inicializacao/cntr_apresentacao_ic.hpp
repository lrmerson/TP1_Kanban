#ifndef CNTR_APRESENTACAO_IC_HPP_INCLUDED
#define CNTR_APRESENTACAO_IC_HPP_INCLUDED

#include "interfaces/apresentacao/interfaces_apresentacao.hpp"

/**
 * @brief Controla a inicialização e a navegação principal do sistema.
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
         * @brief Executa o fluxo principal da aplicação.
         */
        void executar();

        /**
         * @brief Define a apresentação responsável pela autenticação.
         */
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr);

        /**
         * @brief Define a apresentação responsável pelos serviços de pessoa.
         */
        void setCntrApresentacaoPessoa(IApresentacaoPessoa* cntr);

        /**
         * @brief Define a apresentação responsável pelos serviços de projeto.
         */
        void setCntrApresentacaoProjeto(IApresentacaoProjeto* cntr);

        /**
         * @brief Define a apresentação responsável pelos serviços Kanban.
         */
        void setCntrApresentacaoKanban(IApresentacaoKanban* cntr);
};

#endif // CNTR_APRESENTACAO_IC_HPP_INCLUDED
