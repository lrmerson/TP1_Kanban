#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <vector>

#include "dominio/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

class IServicoPessoa {
    public:
        virtual bool autenticar(const EMAIL&, const Senha&) = 0;
        virtual void criar(const Pessoa&) = 0;
        virtual Pessoa ler(const EMAIL&) = 0;
        virtual void atualizar(const Pessoa&) = 0;
        virtual void excluir(const EMAIL&) = 0;
        virtual vector<EMAIL> listar() = 0;
        virtual ~IServicoPessoa() {}
};

///////////////////////////////////////////////////////////////////////////////

class IServicoProjeto {
    public:
        virtual void criar(const Projeto&, const EMAIL&) = 0;
        virtual Projeto ler(const Identificador&) = 0;
        virtual void atualizar(const Projeto&, const EMAIL&) = 0;
        virtual void excluir(const Identificador&, const EMAIL&) = 0;
        virtual vector<Identificador> listar() = 0;
        virtual ~IServicoProjeto() {}
};

///////////////////////////////////////////////////////////////////////////////

class IServicoQuadro {
    public:
        virtual void criar(const Quadro&, const Identificador&, const EMAIL&) = 0;
        virtual Quadro ler(const Identificador&) = 0;
        virtual void atualizar(const Quadro&, const EMAIL&) = 0;
        virtual void excluir(const Identificador&, const EMAIL&) = 0;
        virtual vector<Identificador> listar(const Identificador&) = 0;
        virtual ~IServicoQuadro() {}
};

///////////////////////////////////////////////////////////////////////////////

class IServicoCartao {
    public:
        virtual void criar(const CartaoAtividade&, const Identificador&, const EMAIL&) = 0;
        virtual CartaoAtividade ler(const Identificador&) = 0;
        virtual void atualizar(const CartaoAtividade&, const EMAIL&) = 0;
        virtual void excluir(const Identificador&, const EMAIL&) = 0;
        virtual vector<Identificador> listar(const Identificador&) = 0;
        virtual void mover(const Identificador&, const Timestamp&) = 0;
        virtual int lerTempoCiclo(const Identificador&) = 0;
        virtual double lerTempoCicloMedio(const Identificador&) = 0;
        virtual int lerLeadTime(const Identificador&) = 0;
        virtual double lerLeadTimeMedio(const Identificador&) = 0;
        virtual int lerWIP(const Identificador&) = 0;
        virtual ~IServicoCartao() {}
};

///////////////////////////////////////////////////////////////////////////////

class IApresentacaoPessoa {
    public:
        virtual bool autenticar(EMAIL*) = 0;
        virtual void cadastrar() = 0;
        virtual bool executar(const EMAIL&) = 0;
        virtual void setCntrServicoPessoa(IServicoPessoa*) = 0;
        virtual ~IApresentacaoPessoa() {}
};

///////////////////////////////////////////////////////////////////////////////

class IApresentacaoProjeto {
    public:
        virtual void executar(const EMAIL&) = 0;
        virtual void setCntrServicoProjeto(IServicoProjeto*) = 0;
        virtual ~IApresentacaoProjeto() {}
};

///////////////////////////////////////////////////////////////////////////////

class IApresentacaoQuadro {
    public:
        virtual void executar(const EMAIL&) = 0;
        virtual void setCntrServicoQuadro(IServicoQuadro*) = 0;
        virtual ~IApresentacaoQuadro() {}
};

///////////////////////////////////////////////////////////////////////////////

class IApresentacaoCartao {
    public:
        virtual void executar(const EMAIL&) = 0;
        virtual void setCntrServicoCartao(IServicoCartao*) = 0;
        virtual ~IApresentacaoCartao() {}
};

#endif // INTERFACES_HPP_INCLUDED
