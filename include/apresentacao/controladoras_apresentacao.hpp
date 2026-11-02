#ifndef CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
#define CONTROLADORAS_APRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "interfaces/interfaces.hpp"

using namespace std;

string lerLinha(string);
int lerNumero(string);

class CntrApresentacaoControle {
    private:
        IApresentacaoPessoa *cntrApresentacaoPessoa;
        IApresentacaoProjeto *cntrApresentacaoProjeto;
        IApresentacaoQuadro *cntrApresentacaoQuadro;
        IApresentacaoCartao *cntrApresentacaoCartao;
        void menuServicos(const EMAIL&);

    public:
        void executar();
        void setCntrApresentacaoPessoa(IApresentacaoPessoa*);
        void setCntrApresentacaoProjeto(IApresentacaoProjeto*);
        void setCntrApresentacaoQuadro(IApresentacaoQuadro*);
        void setCntrApresentacaoCartao(IApresentacaoCartao*);
};

///////////////////////////////////////////////////////////////////////////////

class CntrApresentacaoPessoa : public IApresentacaoPessoa {
    private:
        IServicoPessoa *cntrServicoPessoa;
        void ler();
        void atualizar(const EMAIL&);
        bool excluir(const EMAIL&);
        void listar();

    public:
        bool autenticar(EMAIL*);
        void cadastrar();
        bool executar(const EMAIL&);
        void setCntrServicoPessoa(IServicoPessoa*);
};

///////////////////////////////////////////////////////////////////////////////

class CntrApresentacaoProjeto : public IApresentacaoProjeto {
    private:
        IServicoProjeto *cntrServicoProjeto;
        void criar(const EMAIL&);
        void ler();
        void atualizar(const EMAIL&);
        void excluir(const EMAIL&);
        void listar();

    public:
        void executar(const EMAIL&);
        void setCntrServicoProjeto(IServicoProjeto*);
};

///////////////////////////////////////////////////////////////////////////////

class CntrApresentacaoQuadro : public IApresentacaoQuadro {
    private:
        IServicoQuadro *cntrServicoQuadro;
        void criar(const EMAIL&);
        void ler();
        void atualizar(const EMAIL&);
        void excluir(const EMAIL&);
        void listar();

    public:
        void executar(const EMAIL&);
        void setCntrServicoQuadro(IServicoQuadro*);
};

///////////////////////////////////////////////////////////////////////////////

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
        void executar(const EMAIL&);
        void setCntrServicoCartao(IServicoCartao*);
};

#endif // CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
