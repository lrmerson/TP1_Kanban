#ifndef INTERFACES_SERVICO_HPP_INCLUDED
#define INTERFACES_SERVICO_HPP_INCLUDED

#include <vector>

#include "dominio/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;


/**
 * @brief Interface dos serviços de autenticação.
 *
 * Define os serviços necessários para autenticar uma pessoa
 * cadastrada no sistema.
 */
class IServicoAutenticacao {
    public:

        /**
         * @brief Confere as credenciais de uma pessoa cadastrada.
         *
         * @param email Endereço usado para autenticação.
         * @param senha Senha apresentada.
         * @return true se as credenciais forem válidas.
         */
        virtual bool autenticar(
            const EMAIL& email,
            const Senha& senha
        ) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IServicoAutenticacao() {}
};


/**
 * @brief Interface dos serviços de gerenciamento de pessoas.
 *
 * Define as operações de criação, leitura, atualização,
 * exclusão e listagem de pessoas.
 */
class IServicoPessoa {
    public:

        /**
         * @brief Cadastra uma pessoa.
         *
         * @param pessoa Dados da pessoa a cadastrar.
         */
        virtual void criar(
            const Pessoa& pessoa
        ) = 0;

        /**
         * @brief Busca uma pessoa pelo e-mail.
         *
         * @param email Identificador da pessoa.
         * @return Dados da pessoa encontrada.
         */
        virtual Pessoa ler(
            const EMAIL& email
        ) = 0;

        /**
         * @brief Atualiza os dados de uma pessoa existente.
         *
         * @param pessoa Dados atualizados da pessoa.
         */
        virtual void atualizar(
            const Pessoa& pessoa
        ) = 0;

        /**
         * @brief Exclui uma pessoa pelo e-mail.
         *
         * @param email Identificador da pessoa.
         */
        virtual void excluir(
            const EMAIL& email
        ) = 0;

        /**
         * @brief Lista as pessoas cadastradas.
         *
         * @return E-mails que identificam as pessoas cadastradas.
         */
        virtual vector<EMAIL> listar() = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IServicoPessoa() {}
};


/**
 * @brief Interface dos serviços de gerenciamento de projetos.
 *
 * Define as operações de criação, leitura, atualização,
 * exclusão e listagem de projetos.
 */
class IServicoProjeto {
    public:

        /**
         * @brief Cria um projeto para o gestor informado.
         *
         * @param projeto Dados do projeto.
         * @param gestor Pessoa responsável pelo projeto.
         */
        virtual void criar(
            const Projeto& projeto,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Busca um projeto pelo identificador.
         *
         * @param identificador Identificador do projeto.
         * @return Dados do projeto encontrado.
         */
        virtual Projeto ler(
            const Identificador& identificador
        ) = 0;

        /**
         * @brief Atualiza um projeto.
         *
         * @param projeto Dados atualizados do projeto.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void atualizar(
            const Projeto& projeto,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Exclui um projeto.
         *
         * @param identificador Identificador do projeto.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void excluir(
            const Identificador& identificador,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Lista os projetos cadastrados.
         *
         * @return Identificadores dos projetos.
         */
        virtual vector<Identificador> listar() = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IServicoProjeto() {}
};


/**
 * @brief Interface dos serviços do subsistema Kanban.
 *
 * Define os serviços relacionados a quadros, cartões de atividade
 * e métricas Kanban.
 */
class IServicoKanban {
    public:

        // =====================================================
        // QUADROS
        // =====================================================

        /**
         * @brief Cria um quadro dentro de um projeto.
         *
         * @param quadro Dados do quadro.
         * @param projeto Identificador do projeto.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void criarQuadro(
            const Quadro& quadro,
            const Identificador& projeto,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Busca um quadro pelo identificador.
         *
         * @param identificador Identificador do quadro.
         * @return Dados do quadro encontrado.
         */
        virtual Quadro lerQuadro(
            const Identificador& identificador
        ) = 0;

        /**
         * @brief Atualiza um quadro.
         *
         * @param quadro Dados atualizados do quadro.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void atualizarQuadro(
            const Quadro& quadro,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Exclui um quadro.
         *
         * @param identificador Identificador do quadro.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void excluirQuadro(
            const Identificador& identificador,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Lista os quadros associados a um projeto.
         *
         * @param projeto Identificador do projeto.
         * @return Identificadores dos quadros.
         */
        virtual vector<Identificador> listarQuadros(
            const Identificador& projeto
        ) = 0;


        // =====================================================
        // CARTÕES DE ATIVIDADE
        // =====================================================

        /**
         * @brief Cria um cartão de atividade em um quadro.
         *
         * @param cartao Dados do cartão.
         * @param quadro Identificador do quadro.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void criarCartao(
            const CartaoAtividade& cartao,
            const Identificador& quadro,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Busca um cartão pelo identificador.
         *
         * @param identificador Identificador do cartão.
         * @return Dados do cartão encontrado.
         */
        virtual CartaoAtividade lerCartao(
            const Identificador& identificador
        ) = 0;

        /**
         * @brief Atualiza um cartão de atividade.
         *
         * @param cartao Dados atualizados do cartão.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void atualizarCartao(
            const CartaoAtividade& cartao,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Exclui um cartão de atividade.
         *
         * @param identificador Identificador do cartão.
         * @param gestor Gestor responsável pelo projeto.
         */
        virtual void excluirCartao(
            const Identificador& identificador,
            const EMAIL& gestor
        ) = 0;

        /**
         * @brief Lista os cartões associados a um quadro.
         *
         * @param quadro Identificador do quadro.
         * @return Identificadores dos cartões.
         */
        virtual vector<Identificador> listarCartoes(
            const Identificador& quadro
        ) = 0;

        /**
         * @brief Move um cartão para a próxima coluna do fluxo Kanban.
         *
         * @param identificador Identificador do cartão.
         * @param momento Data e horário da movimentação.
         */
        virtual void moverCartao(
            const Identificador& identificador,
            const Timestamp& momento
        ) = 0;


        // =====================================================
        // MÉTRICAS
        // =====================================================

        /**
         * @brief Calcula o tempo de ciclo de um cartão.
         *
         * @param identificador Identificador do cartão.
         * @return Tempo de ciclo em minutos.
         */
        virtual int lerTempoCiclo(
            const Identificador& identificador
        ) = 0;

        /**
         * @brief Calcula o tempo de ciclo médio de um quadro.
         *
         * @param quadro Identificador do quadro.
         * @return Tempo de ciclo médio em minutos.
         */
        virtual double lerTempoCicloMedio(
            const Identificador& quadro
        ) = 0;

        /**
         * @brief Calcula o lead time de um cartão.
         *
         * @param identificador Identificador do cartão.
         * @return Lead time em minutos.
         */
        virtual int lerLeadTime(
            const Identificador& identificador
        ) = 0;

        /**
         * @brief Calcula o lead time médio de um quadro.
         *
         * @param quadro Identificador do quadro.
         * @return Lead time médio em minutos.
         */
        virtual double lerLeadTimeMedio(
            const Identificador& quadro
        ) = 0;

        /**
         * @brief Calcula o WIP atual de um quadro.
         *
         * @param quadro Identificador do quadro.
         * @return Número de cartões na coluna FAZENDO.
         */
        virtual int lerWIP(
            const Identificador& quadro
        ) = 0;

        /**
         * @brief Destrutor virtual da interface.
         */
        virtual ~IServicoKanban() {}
};

#endif // INTERFACES_SERVICO_HPP_INCLUDED
