#ifndef CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
#define CONTROLADORAS_APRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "interfaces/interfaces.hpp"

using namespace std;

/** @brief Lê uma linha de texto exibindo o rótulo informado.
 *  @param rotulo Prompt apresentado antes da leitura.
 *  @return Linha digitada pelo usuário.
 */
string lerLinha(string rotulo);
/** @brief Lê um número inteiro não negativo a partir de uma linha.
 *  @param rotulo Prompt apresentado antes da leitura.
 *  @return Número digitado ou -1 se a entrada não for numérica.
 */
int lerNumero(string rotulo);

/** @brief Controla autenticação, navegação principal e injeção dos módulos. */
class CntrApresentacaoControle {
    private:
        IApresentacaoPessoa *cntrApresentacaoPessoa;
        IApresentacaoProjeto *cntrApresentacaoProjeto;
        IApresentacaoQuadro *cntrApresentacaoQuadro;
        IApresentacaoCartao *cntrApresentacaoCartao;
        void menuServicos(const EMAIL&);

    public:
        /** @brief Executa o fluxo principal da aplicação. */
        void executar();
        /** @brief Define o módulo de apresentação de pessoas.
         *  @param cntr Controladora de apresentação injetada.
         */
        void setCntrApresentacaoPessoa(IApresentacaoPessoa* cntr);
        /** @brief Define o módulo de apresentação de projetos.
         *  @param cntr Controladora de apresentação injetada.
         */
        void setCntrApresentacaoProjeto(IApresentacaoProjeto* cntr);
        /** @brief Define o módulo de apresentação de quadros.
         *  @param cntr Controladora de apresentação injetada.
         */
        void setCntrApresentacaoQuadro(IApresentacaoQuadro* cntr);
        /** @brief Define o módulo de apresentação de cartões.
         *  @param cntr Controladora de apresentação injetada.
         */
        void setCntrApresentacaoCartao(IApresentacaoCartao* cntr);
};

/** @brief Controla a interface com o usuário para serviços de pessoas. */
class CntrApresentacaoPessoa : public IApresentacaoPessoa {
    private:
        IServicoPessoa *cntrServicoPessoa;
        void ler();
        void atualizar(const EMAIL&);
        bool excluir(const EMAIL&);
        void listar();

    public:
        /** @copydoc IApresentacaoPessoa::autenticar */
        bool autenticar(EMAIL* email) override;
        /** @copydoc IApresentacaoPessoa::cadastrar */
        void cadastrar() override;
        /** @copydoc IApresentacaoPessoa::executar */
        bool executar(const EMAIL& email) override;
        /** @copydoc IApresentacaoPessoa::setCntrServicoPessoa */
        void setCntrServicoPessoa(IServicoPessoa* servico) override;
};

/** @brief Controla a interface com o usuário para serviços de projetos. */
class CntrApresentacaoProjeto : public IApresentacaoProjeto {
    private:
        IServicoProjeto *cntrServicoProjeto;
        void criar(const EMAIL&);
        void ler();
        void atualizar(const EMAIL&);
        void excluir(const EMAIL&);
        void listar();

    public:
        /** @copydoc IApresentacaoProjeto::executar */
        void executar(const EMAIL& email) override;
        /** @copydoc IApresentacaoProjeto::setCntrServicoProjeto */
        void setCntrServicoProjeto(IServicoProjeto* servico) override;
};

/** @brief Controla a interface com o usuário para serviços de quadros. */
class CntrApresentacaoQuadro : public IApresentacaoQuadro {
    private:
        IServicoQuadro *cntrServicoQuadro;
        void criar(const EMAIL&);
        void ler();
        void atualizar(const EMAIL&);
        void excluir(const EMAIL&);
        void listar();

    public:
        /** @copydoc IApresentacaoQuadro::executar */
        void executar(const EMAIL& email) override;
        /** @copydoc IApresentacaoQuadro::setCntrServicoQuadro */
        void setCntrServicoQuadro(IServicoQuadro* servico) override;
};

/** @brief Controla a interface com o usuário para serviços de cartões e métricas. */
class CntrApresentacaoCartao : public IApresentacaoCartao {
    private:
        IServicoCartao *cntrServicoCartao;
        void criar(const EMAIL&);
        void ler();
        void atualizar(const EMAIL&);
        void excluir(const EMAIL&);
        void listar();
        void mover();
        void lerTempoCiclo();
        void lerTempoCicloMedio();
        void lerLeadTime();
        void lerLeadTimeMedio();
        void lerWIP();

    public:
        /** @copydoc IApresentacaoCartao::executar */
        void executar(const EMAIL& email) override;
        /** @copydoc IApresentacaoCartao::setCntrServicoCartao */
        void setCntrServicoCartao(IServicoCartao* servico) override;
};

#endif // CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
