#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

/** @brief Armazenamento em memória das pessoas indexadas por e-mail. */
class ContainerPessoa {
    private:
        map<string, Pessoa> container;
        static ContainerPessoa *instancia;
        ContainerPessoa() {}

    public:
        /** @brief Retorna a instância única do contêiner.
         *  @return Instância compartilhada de armazenamento.
         */
        static ContainerPessoa* getInstancia();
        /** @brief Inclui uma pessoa se o e-mail ainda não estiver cadastrado.
         *  @param pessoa Pessoa a armazenar.
         *  @return true se a inclusão for realizada.
         */
        bool incluir(const Pessoa& pessoa);
        /** @brief Remove uma pessoa pelo e-mail.
         *  @param chave E-mail usado como chave.
         *  @return true se uma pessoa for removida.
         */
        bool remover(const string& chave);
        /** @brief Busca a pessoa identificada pelo e-mail do objeto.
         *  @param pessoa Objeto cuja chave é consultada; recebe os dados encontrados.
         *  @return true se a pessoa existir.
         */
        bool pesquisar(Pessoa* pessoa);
        /** @brief Substitui os dados da pessoa identificada pelo e-mail.
         *  @param pessoa Dados atualizados.
         *  @return true se a pessoa existir.
         */
        bool atualizar(const Pessoa& pessoa);
        /** @brief Retorna todas as pessoas armazenadas.
         *  @return Pessoas cadastradas.
         */
        vector<Pessoa> listar();
};

/** @brief Armazenamento em memória dos projetos e de seus gestores. */
class ContainerProjeto {
    private:
        map<string, Projeto> container;
        map<string, string> gestores;
        static ContainerProjeto *instancia;
        ContainerProjeto() {}

    public:
        /** @brief Retorna a instância única do contêiner.
         *  @return Instância compartilhada de armazenamento.
         */
        static ContainerProjeto* getInstancia();
        /** @brief Inclui um projeto e registra seu gestor.
         *  @param projeto Projeto a armazenar.
         *  @param gestor E-mail do gestor responsável.
         *  @return true se o identificador ainda não estiver cadastrado.
         */
        bool incluir(const Projeto& projeto, const string& gestor);
        /** @brief Remove um projeto e sua associação com o gestor.
         *  @param chave Identificador do projeto.
         *  @return true se o projeto existir.
         */
        bool remover(const string& chave);
        /** @brief Busca o projeto identificado pelo objeto recebido.
         *  @param projeto Objeto cuja chave é consultada; recebe os dados encontrados.
         *  @return true se o projeto existir.
         */
        bool pesquisar(Projeto* projeto);
        /** @brief Atualiza os dados de um projeto existente.
         *  @param projeto Dados atualizados.
         *  @return true se o projeto existir.
         */
        bool atualizar(const Projeto& projeto);
        /** @brief Retorna o e-mail do gestor responsável por um projeto.
         *  @param chave Identificador do projeto.
         *  @return E-mail do gestor ou texto vazio se não houver associação.
         */
        string getGestor(const string& chave);
        /** @brief Retorna todos os projetos armazenados.
         *  @return Projetos cadastrados.
         */
        vector<Projeto> listar();
};

/** @brief Armazenamento em memória dos quadros e de seus projetos. */
class ContainerQuadro {
    private:
        map<string, Quadro> container;
        map<string, string> projetos;
        static ContainerQuadro *instancia;
        ContainerQuadro() {}

    public:
        /** @brief Retorna a instância única do contêiner.
         *  @return Instância compartilhada de armazenamento.
         */
        static ContainerQuadro* getInstancia();
        /** @brief Inclui um quadro e registra seu projeto pai.
         *  @param quadro Quadro a armazenar.
         *  @param projeto Identificador do projeto pai.
         *  @return true se o identificador ainda não estiver cadastrado.
         */
        bool incluir(const Quadro& quadro, const string& projeto);
        /** @brief Remove um quadro e sua associação com o projeto.
         *  @param chave Identificador do quadro.
         *  @return true se o quadro existir.
         */
        bool remover(const string& chave);
        /** @brief Busca o quadro identificado pelo objeto recebido.
         *  @param quadro Objeto cuja chave é consultada; recebe os dados encontrados.
         *  @return true se o quadro existir.
         */
        bool pesquisar(Quadro* quadro);
        /** @brief Atualiza os dados de um quadro existente.
         *  @param quadro Dados atualizados.
         *  @return true se o quadro existir.
         */
        bool atualizar(const Quadro& quadro);
        /** @brief Retorna o projeto que contém um quadro.
         *  @param chave Identificador do quadro.
         *  @return Identificador do projeto ou texto vazio se não houver associação.
         */
        string getProjeto(const string& chave);
        /** @brief Lista os quadros associados a um projeto.
         *  @param projeto Identificador do projeto.
         *  @return Quadros do projeto.
         */
        vector<Quadro> listar(const string& projeto);
};

/** @brief Armazenamento em memória dos cartões e de seus quadros. */
class ContainerCartao {
    private:
        map<string, CartaoAtividade> container;
        map<string, string> quadros;
        static ContainerCartao *instancia;
        ContainerCartao() {}

    public:
        /** @brief Retorna a instância única do contêiner.
         *  @return Instância compartilhada de armazenamento.
         */
        static ContainerCartao* getInstancia();
        /** @brief Inclui um cartão e registra seu quadro pai.
         *  @param cartao Cartão a armazenar.
         *  @param quadro Identificador do quadro pai.
         *  @return true se o identificador ainda não estiver cadastrado.
         */
        bool incluir(const CartaoAtividade& cartao, const string& quadro);
        /** @brief Remove um cartão e sua associação com o quadro.
         *  @param chave Identificador do cartão.
         *  @return true se o cartão existir.
         */
        bool remover(const string& chave);
        /** @brief Busca o cartão identificado pelo objeto recebido.
         *  @param cartao Objeto cuja chave é consultada; recebe os dados encontrados.
         *  @return true se o cartão existir.
         */
        bool pesquisar(CartaoAtividade* cartao);
        /** @brief Atualiza os dados de um cartão existente.
         *  @param cartao Dados atualizados.
         *  @return true se o cartão existir.
         */
        bool atualizar(const CartaoAtividade& cartao);
        /** @brief Retorna o quadro que contém um cartão.
         *  @param chave Identificador do cartão.
         *  @return Identificador do quadro ou texto vazio se não houver associação.
         */
        string getQuadro(const string& chave);
        /** @brief Lista os cartões associados a um quadro.
         *  @param quadro Identificador do quadro.
         *  @return Cartões associados ao quadro.
         */
        vector<CartaoAtividade> listar(const string& quadro);
};

#endif // CONTAINERS_HPP_INCLUDED
