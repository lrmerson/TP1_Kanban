#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <vector>

#include "dominio/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

/** @brief Contrato dos serviços de cadastro e autenticação de pessoas. */
class IServicoPessoa {
    public:
        /** @brief Confere as credenciais de uma pessoa cadastrada.
         *  @param email Endereço usado para autenticação.
         *  @param senha Senha apresentada.
         *  @return true se as credenciais forem válidas.
         */
        virtual bool autenticar(const EMAIL& email, const Senha& senha) = 0;
        /** @brief Cadastra uma pessoa.
         *  @param pessoa Dados da pessoa a cadastrar.
         */
        virtual void criar(const Pessoa& pessoa) = 0;
        /** @brief Busca uma pessoa pelo e-mail.
         *  @param email Identificador da pessoa.
         *  @return Dados da pessoa encontrada.
         */
        virtual Pessoa ler(const EMAIL& email) = 0;
        /** @brief Atualiza os dados de uma pessoa existente.
         *  @param pessoa Dados atualizados, identificados pelo e-mail.
         */
        virtual void atualizar(const Pessoa& pessoa) = 0;
        /** @brief Exclui uma pessoa pelo e-mail.
         *  @param email Identificador da pessoa.
         */
        virtual void excluir(const EMAIL& email) = 0;
        /** @brief Lista os e-mails das pessoas cadastradas.
         *  @return Identificadores das pessoas.
         */
        virtual vector<EMAIL> listar() = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IServicoPessoa() {}
};

/** @brief Contrato dos serviços de gerenciamento de projetos. */
class IServicoProjeto {
    public:
        /** @brief Cria um projeto para o gestor informado.
         *  @param projeto Dados do projeto.
         *  @param gestor Pessoa responsável pelo projeto.
         */
        virtual void criar(const Projeto& projeto, const EMAIL& gestor) = 0;
        /** @brief Busca um projeto pelo identificador.
         *  @param identificador Chave do projeto.
         *  @return Dados do projeto encontrado.
         */
        virtual Projeto ler(const Identificador& identificador) = 0;
        /** @brief Atualiza um projeto sob responsabilidade do gestor.
         *  @param projeto Dados atualizados, incluindo o identificador.
         *  @param gestor Pessoa que solicita a atualização.
         */
        virtual void atualizar(const Projeto& projeto, const EMAIL& gestor) = 0;
        /** @brief Exclui um projeto sob responsabilidade do gestor.
         *  @param identificador Chave do projeto.
         *  @param gestor Pessoa que solicita a exclusão.
         */
        virtual void excluir(const Identificador& identificador, const EMAIL& gestor) = 0;
        /** @brief Lista os identificadores dos projetos.
         *  @return Identificadores dos projetos cadastrados.
         */
        virtual vector<Identificador> listar() = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IServicoProjeto() {}
};

/** @brief Contrato dos serviços de gerenciamento de quadros. */
class IServicoQuadro {
    public:
        /** @brief Cria um quadro dentro de um projeto.
         *  @param quadro Dados do quadro.
         *  @param projeto Identificador do projeto pai.
         *  @param gestor Pessoa responsável pelo projeto.
         */
        virtual void criar(const Quadro& quadro, const Identificador& projeto, const EMAIL& gestor) = 0;
        /** @brief Busca um quadro pelo identificador.
         *  @param identificador Chave do quadro.
         *  @return Dados do quadro encontrado.
         */
        virtual Quadro ler(const Identificador& identificador) = 0;
        /** @brief Atualiza um quadro sob responsabilidade do gestor do projeto.
         *  @param quadro Dados atualizados, incluindo o identificador.
         *  @param gestor Pessoa que solicita a atualização.
         */
        virtual void atualizar(const Quadro& quadro, const EMAIL& gestor) = 0;
        /** @brief Exclui um quadro vazio sob responsabilidade do gestor.
         *  @param identificador Chave do quadro.
         *  @param gestor Pessoa que solicita a exclusão.
         */
        virtual void excluir(const Identificador& identificador, const EMAIL& gestor) = 0;
        /** @brief Lista os quadros de um projeto.
         *  @param projeto Identificador do projeto.
         *  @return Identificadores dos quadros associados.
         */
        virtual vector<Identificador> listar(const Identificador& projeto) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IServicoQuadro() {}
};

/** @brief Contrato dos serviços de cartões, movimentações e métricas Kanban. */
class IServicoCartao {
    public:
        /** @brief Cria um cartão no quadro informado.
         *  @param cartao Dados da atividade.
         *  @param quadro Identificador do quadro pai.
         *  @param gestor Pessoa responsável pelo projeto.
         */
        virtual void criar(const CartaoAtividade& cartao, const Identificador& quadro, const EMAIL& gestor) = 0;
        /** @brief Busca um cartão pelo identificador.
         *  @param identificador Chave do cartão.
         *  @return Dados do cartão encontrado.
         */
        virtual CartaoAtividade ler(const Identificador& identificador) = 0;
        /** @brief Atualiza os dados editáveis de um cartão.
         *  @param cartao Dados atualizados, incluindo o identificador.
         *  @param gestor Pessoa responsável pelo projeto.
         */
        virtual void atualizar(const CartaoAtividade& cartao, const EMAIL& gestor) = 0;
        /** @brief Exclui um cartão sob responsabilidade do gestor.
         *  @param identificador Chave do cartão.
         *  @param gestor Pessoa que solicita a exclusão.
         */
        virtual void excluir(const Identificador& identificador, const EMAIL& gestor) = 0;
        /** @brief Lista os cartões de um quadro.
         *  @param quadro Identificador do quadro.
         *  @return Identificadores dos cartões associados.
         */
        virtual vector<Identificador> listar(const Identificador& quadro) = 0;
        /** @brief Avança um cartão para a próxima coluna do fluxo Kanban.
         *  @param identificador Chave do cartão.
         *  @param momento Data e horário da movimentação.
         */
        virtual void mover(const Identificador& identificador, const Timestamp& momento) = 0;
        /** @brief Calcula o tempo de ciclo de um cartão concluído, em minutos.
         *  @param identificador Chave do cartão.
         *  @return Minutos entre FAZENDO e FEITO.
         */
        virtual int lerTempoCiclo(const Identificador& identificador) = 0;
        /** @brief Calcula o tempo de ciclo médio dos cartões concluídos de um quadro.
         *  @param quadro Identificador do quadro.
         *  @return Média em minutos.
         */
        virtual double lerTempoCicloMedio(const Identificador& quadro) = 0;
        /** @brief Calcula o lead time de um cartão concluído, em minutos.
         *  @param identificador Chave do cartão.
         *  @return Minutos entre A FAZER e FEITO.
         */
        virtual int lerLeadTime(const Identificador& identificador) = 0;
        /** @brief Calcula o lead time médio dos cartões concluídos de um quadro.
         *  @param quadro Identificador do quadro.
         *  @return Média em minutos.
         */
        virtual double lerLeadTimeMedio(const Identificador& quadro) = 0;
        /** @brief Conta os cartões que estão na coluna FAZENDO.
         *  @param quadro Identificador do quadro.
         *  @return Quantidade de cartões em andamento.
         */
        virtual int lerWIP(const Identificador& quadro) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IServicoCartao() {}
};

/** @brief Contrato entre o fluxo de entrada e os serviços de pessoas. */
class IApresentacaoPessoa {
    public:
        /** @brief Solicita credenciais e autentica uma pessoa.
         *  @param email Saída com o e-mail autenticado.
         *  @return true se a autenticação for concluída.
         */
        virtual bool autenticar(EMAIL* email) = 0;
        /** @brief Coleta os dados e solicita o cadastro de uma pessoa. */
        virtual void cadastrar() = 0;
        /** @brief Executa o menu de serviços de pessoas.
         *  @param email Pessoa autenticada que usa o menu.
         *  @return false se a execução encerrar a sessão.
         */
        virtual bool executar(const EMAIL& email) = 0;
        /** @brief Injeta a implementação dos serviços de pessoas.
         *  @param servico Interface de serviço utilizada pelo módulo.
         */
        virtual void setCntrServicoPessoa(IServicoPessoa* servico) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IApresentacaoPessoa() {}
};

/** @brief Contrato entre a apresentação e os serviços de projetos. */
class IApresentacaoProjeto {
    public:
        /** @brief Executa o menu de projetos para a pessoa autenticada.
         *  @param email Pessoa autenticada.
         */
        virtual void executar(const EMAIL& email) = 0;
        /** @brief Injeta a implementação dos serviços de projetos.
         *  @param servico Interface de serviço utilizada pelo módulo.
         */
        virtual void setCntrServicoProjeto(IServicoProjeto* servico) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IApresentacaoProjeto() {}
};

/** @brief Contrato entre a apresentação e os serviços de quadros. */
class IApresentacaoQuadro {
    public:
        /** @brief Executa o menu de quadros para a pessoa autenticada.
         *  @param email Pessoa autenticada.
         */
        virtual void executar(const EMAIL& email) = 0;
        /** @brief Injeta a implementação dos serviços de quadros.
         *  @param servico Interface de serviço utilizada pelo módulo.
         */
        virtual void setCntrServicoQuadro(IServicoQuadro* servico) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IApresentacaoQuadro() {}
};

/** @brief Contrato entre a apresentação e os serviços de cartões. */
class IApresentacaoCartao {
    public:
        /** @brief Executa o menu de cartões para a pessoa autenticada.
         *  @param email Pessoa autenticada.
         */
        virtual void executar(const EMAIL& email) = 0;
        /** @brief Injeta a implementação dos serviços de cartões.
         *  @param servico Interface de serviço utilizada pelo módulo.
         */
        virtual void setCntrServicoCartao(IServicoCartao* servico) = 0;
        /** @brief Destrutor virtual da interface. */
        virtual ~IApresentacaoCartao() {}
};

#endif // INTERFACES_HPP_INCLUDED
