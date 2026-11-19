#ifndef SAIDA_USUARIO_HPP_INCLUDED
#define SAIDA_USUARIO_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class SaidaUsuario {
    private:
        SaidaUsuario() = delete;

        static const string SEPARADOR;

        static void linha(const string& texto = "");

    public:
        static void titulo(const string& texto, const string& subtitulo = "");
        static void secao(const string& texto);
        static void item(int numero, const string& texto);
        static void separador();

        static void acao(const string& texto, bool pedeDados = true);
        static void sucesso(const string& mensagem);
        static void erro(const string& mensagem);
        static void aviso(const string& mensagem);
        static void cancelado();

        static void saida(const string& rotulo, const string& valor);
        static void listaItens(const vector<string>& itens);
};

#endif // SAIDA_USUARIO_HPP_INCLUDED
