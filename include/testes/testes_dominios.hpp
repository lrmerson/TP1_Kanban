#ifndef TESTES_DOMINIOS_HPP_INCLUDED
#define TESTES_DOMINIOS_HPP_INCLUDED

#include <string>
#include <vector>

#include "dominio/dominios.hpp"

using namespace std;

class TUEMAIL {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        EMAIL *email;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUEstado {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Estado *estadoDominio;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUIdentificador {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Identificador *identificador;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TULimite {
    private:
        const static vector<int> VALORES_VALIDOS;
        const static vector<int> VALORES_INVALIDOS;
        Limite *limite;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUNome {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Nome *nome;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUPapel {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Papel *papel;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUPrioridade {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Prioridade *prioridade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUSenha {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Senha *senha;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUTamanho {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Tamanho *tamanho;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUTexto {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Texto *texto;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

///////////////////////////////////////////////////////////////////////////////

class TUTimestamp {
    private:
        const static vector<string> VALORES_VALIDOS;
        const static vector<string> VALORES_INVALIDOS;
        Timestamp *timestamp;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TESTES_DOMINIOS_HPP_INCLUDED
