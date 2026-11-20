#ifndef SAIDA_USUARIO_HPP_INCLUDED
#define SAIDA_USUARIO_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Padroniza a exibição de mensagens e resultados no terminal.
 */
class SaidaUsuario {
    private:
        SaidaUsuario() = delete;

        static const string SEPARADOR;

        static void linha(const string& texto = "");

    public:
        /**
         * @brief Exibe o título de uma tela.
         * @param texto Título principal.
         * @param subtitulo Texto complementar opcional.
         */
        static void titulo(const string& texto, const string& subtitulo = "");

        /**
         * @brief Exibe o título de uma seção.
         * @param texto Nome da seção.
         */
        static void secao(const string& texto);

        /**
         * @brief Exibe um item numerado de menu.
         * @param numero Número do item.
         * @param texto Descrição do item.
         */
        static void item(int numero, const string& texto);

        /**
         * @brief Exibe um separador visual.
         */
        static void separador();

        /**
         * @brief Exibe uma ação em andamento.
         * @param texto Descrição da ação.
         * @param pedeDados Indica se a ação solicita dados ao usuário.
         */
        static void acao(const string& texto, bool pedeDados = true);

        /**
         * @brief Exibe uma mensagem de sucesso.
         * @param mensagem Texto da mensagem.
         */
        static void sucesso(const string& mensagem);

        /**
         * @brief Exibe uma mensagem de erro.
         * @param mensagem Texto da mensagem.
         */
        static void erro(const string& mensagem);

        /**
         * @brief Exibe uma mensagem de aviso.
         * @param mensagem Texto da mensagem.
         */
        static void aviso(const string& mensagem);

        /**
         * @brief Informa que uma operação foi cancelada.
         */
        static void cancelado();

        /**
         * @brief Exibe um valor identificado por um rótulo.
         * @param rotulo Nome do valor.
         * @param valor Conteúdo do valor.
         */
        static void saida(const string& rotulo, const string& valor);

        /**
         * @brief Exibe uma lista de itens.
         * @param itens Valores que serão apresentados.
         */
        static void listaItens(const vector<string>& itens);
};

#endif // SAIDA_USUARIO_HPP_INCLUDED
