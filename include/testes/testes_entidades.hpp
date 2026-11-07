#ifndef TESTES_ENTIDADES_HPP_INCLUDED
#define TESTES_ENTIDADES_HPP_INCLUDED

#include <string>

#include "entidades/entidades.hpp"

using namespace std;

class TUPessoa {
    private:
        const static string EMAIL_VALIDO;
        const static string NOME_VALIDO;
        const static string SENHA_VALIDA;
        const static string PAPEL_VALIDO;
        Pessoa *pessoa;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUProjeto {
    private:
        const static string IDENTIFICADOR_VALIDO;
        const static string NOME_VALIDO;
        const static string DESCRICAO_VALIDA;
        const static string INICIO_VALIDO;
        const static string TERMINO_VALIDO;
        Projeto *projeto;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUCartaoAtividade {
    private:
        const static string IDENTIFICADOR_VALIDO;
        const static string NOME_VALIDO;
        const static string DESCRICAO_VALIDA;
        const static string PRIORIDADE_VALIDA;
        const static string ESTADO_VALIDO;
        const static string TAMANHO_VALIDO;
        const static string ENTRADA_VALIDA;
        const static string INICIO_VALIDO;
        const static string TERMINO_VALIDO;
        CartaoAtividade *cartao;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

class TUQuadro {
    private:
        const static string IDENTIFICADOR_VALIDO;
        const static string NOME_VALIDO;
        const static int LIMITE_VALIDO = 5;
        Quadro *quadro;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TESTES_ENTIDADES_HPP_INCLUDED
