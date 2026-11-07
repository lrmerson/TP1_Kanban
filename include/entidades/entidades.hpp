#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominio/dominios.hpp"

/** @brief Dados de uma pessoa cadastrada e autenticável no sistema. */
class Pessoa {
    private:
        EMAIL email;
        Nome nome;
        Senha senha;
        Papel papel;

    public:
        /** @brief Define o e-mail que identifica a pessoa.
         *  @param email Endereço de e-mail validado.
         */
        void setEmail(const EMAIL& email);
        /** @brief Retorna o e-mail da pessoa.
         *  @return E-mail usado como identificador.
         */
        EMAIL getEmail() const;

        /** @brief Define o nome da pessoa.
         *  @param nome Nome validado.
         */
        void setNome(const Nome& nome);
        /** @brief Retorna o nome da pessoa.
         *  @return Nome da pessoa.
         */
        Nome getNome() const;

        /** @brief Define a senha de autenticação.
         *  @param senha Senha validada.
         */
        void setSenha(const Senha& senha);
        /** @brief Retorna a senha armazenada.
         *  @return Senha da pessoa.
         */
        Senha getSenha() const;

        /** @brief Define o papel da pessoa no sistema.
         *  @param papel Papel validado.
         */
        void setPapel(const Papel& papel);
        /** @brief Retorna o papel da pessoa.
         *  @return Papel atribuído.
         */
        Papel getPapel() const;
};

/** @brief Dados e período de execução de um projeto. */
class Projeto {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;

    public:
        /** @brief Define o identificador imutável do projeto.
         *  @param identificador Identificador validado.
         */
        void setIdentificador(const Identificador& identificador);
        /** @brief Retorna o identificador do projeto.
         *  @return Chave do projeto.
         */
        Identificador getIdentificador() const;

        /** @brief Define o nome do projeto.
         *  @param nome Nome validado.
         */
        void setNome(const Nome& nome);
        /** @brief Retorna o nome do projeto.
         *  @return Nome do projeto.
         */
        Nome getNome() const;

        /** @brief Define a descrição do projeto.
         *  @param descricao Texto validado.
         */
        void setDescricao(const Texto& descricao);
        /** @brief Retorna a descrição do projeto.
         *  @return Descrição do projeto.
         */
        Texto getDescricao() const;

        /** @brief Define a data de início do projeto.
         *  @param inicio Data e horário válidos.
         */
        void setInicio(const Timestamp& inicio);
        /** @brief Retorna a data de início do projeto.
         *  @return Data e horário de início.
         */
        Timestamp getInicio() const;

        /** @brief Define a data de término do projeto.
         *  @param termino Data e horário válidos.
         */
        void setTermino(const Timestamp& termino);
        /** @brief Retorna a data de término do projeto.
         *  @return Data e horário de término.
         */
        Timestamp getTermino() const;
};

/** @brief Dados, estado e tempos registrados de uma atividade Kanban. */
class CartaoAtividade {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Prioridade prioridade;
        Estado estado;
        Tamanho tamanho;
        Timestamp entrada;
        Timestamp inicio;
        Timestamp termino;

    public:
        /** @brief Define o identificador imutável do cartão.
         *  @param identificador Identificador validado.
         */
        void setIdentificador(const Identificador& identificador);
        /** @brief Retorna o identificador do cartão.
         *  @return Chave do cartão.
         */
        Identificador getIdentificador() const;

        /** @brief Define o nome da atividade.
         *  @param nome Nome validado.
         */
        void setNome(const Nome& nome);
        /** @brief Retorna o nome da atividade.
         *  @return Nome da atividade.
         */
        Nome getNome() const;

        /** @brief Define a descrição da atividade.
         *  @param descricao Texto validado.
         */
        void setDescricao(const Texto& descricao);
        /** @brief Retorna a descrição da atividade.
         *  @return Descrição da atividade.
         */
        Texto getDescricao() const;

        /** @brief Define a prioridade da atividade.
         *  @param prioridade Prioridade válida.
         */
        void setPrioridade(const Prioridade& prioridade);
        /** @brief Retorna a prioridade da atividade.
         *  @return Prioridade da atividade.
         */
        Prioridade getPrioridade() const;

        /** @brief Define a coluna atual do cartão.
         *  @param estado Estado válido do fluxo Kanban.
         */
        void setEstado(const Estado& estado);
        /** @brief Retorna a coluna atual do cartão.
         *  @return Estado atual do fluxo Kanban.
         */
        Estado getEstado() const;

        /** @brief Define o tamanho da atividade.
         *  @param tamanho Classificação de tamanho válida.
         */
        void setTamanho(const Tamanho& tamanho);
        /** @brief Retorna o tamanho da atividade.
         *  @return Classificação da atividade.
         */
        Tamanho getTamanho() const;

        /** @brief Define o momento de entrada na coluna A FAZER.
         *  @param entrada Data e horário válidos.
         */
        void setEntrada(const Timestamp& entrada);
        /** @brief Retorna o momento de entrada na coluna A FAZER.
         *  @return Data e horário de entrada.
         */
        Timestamp getEntrada() const;

        /** @brief Define o momento de entrada na coluna FAZENDO.
         *  @param inicio Data e horário válidos.
         */
        void setInicio(const Timestamp& inicio);
        /** @brief Retorna o momento de entrada na coluna FAZENDO.
         *  @return Data e horário de início do trabalho.
         */
        Timestamp getInicio() const;

        /** @brief Define o momento de entrada na coluna FEITO.
         *  @param termino Data e horário válidos.
         */
        void setTermino(const Timestamp& termino);
        /** @brief Retorna o momento de entrada na coluna FEITO.
         *  @return Data e horário de conclusão.
         */
        Timestamp getTermino() const;
};

/** @brief Quadro Kanban de um projeto e seu limite WIP. */
class Quadro {
    private:
        Identificador identificador;
        Nome nome;
        Limite limite;

    public:
        /** @brief Define o identificador imutável do quadro.
         *  @param identificador Identificador validado.
         */
        void setIdentificador(const Identificador& identificador);
        /** @brief Retorna o identificador do quadro.
         *  @return Chave do quadro.
         */
        Identificador getIdentificador() const;

        /** @brief Define o nome do quadro.
         *  @param nome Nome validado.
         */
        void setNome(const Nome& nome);
        /** @brief Retorna o nome do quadro.
         *  @return Nome do quadro.
         */
        Nome getNome() const;

        /** @brief Define o limite de atividades na coluna FAZENDO.
         *  @param limite Limite válido entre 1 e 25.
         */
        void setLimite(const Limite& limite);
        /** @brief Retorna o limite WIP do quadro.
         *  @return Quantidade máxima de cartões em andamento.
         */
        Limite getLimite() const;
};




#endif // ENTIDADES_HPP_INCLUDED
