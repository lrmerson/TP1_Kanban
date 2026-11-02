#ifndef CONTROLADORAS_SERVICO_HPP_INCLUDED
#define CONTROLADORAS_SERVICO_HPP_INCLUDED

#include <stdexcept>

#include "interfaces/interfaces.hpp"
#include "servico/containers.hpp"

using namespace std;

class CntrServicoPessoa : public IServicoPessoa {
    public:
        bool autenticar(const EMAIL&, const Senha&);
        void criar(const Pessoa&);
        Pessoa ler(const EMAIL&);
        void atualizar(const Pessoa&);
        void excluir(const EMAIL&);
        vector<EMAIL> listar();
};

///////////////////////////////////////////////////////////////////////////////

class CntrServicoProjeto : public IServicoProjeto {
    private:
        void verificarGestor(const Identificador&, const EMAIL&);

    public:
        void criar(const Projeto&, const EMAIL&);
        Projeto ler(const Identificador&);
        void atualizar(const Projeto&, const EMAIL&);
        void excluir(const Identificador&, const EMAIL&);
        vector<Identificador> listar();
};

///////////////////////////////////////////////////////////////////////////////

class CntrServicoQuadro : public IServicoQuadro {
    private:
        void verificarGestor(const string&, const EMAIL&);

    public:
        void criar(const Quadro&, const Identificador&, const EMAIL&);
        Quadro ler(const Identificador&);
        void atualizar(const Quadro&, const EMAIL&);
        void excluir(const Identificador&, const EMAIL&);
        vector<Identificador> listar(const Identificador&);
};

///////////////////////////////////////////////////////////////////////////////

class CntrServicoCartao : public IServicoCartao {
    private:
        void verificarGestor(const string&, const EMAIL&);
        int converterMinutos(const Timestamp&);
        int contarFazendo(const string&);

    public:
        void criar(const CartaoAtividade&, const Identificador&, const EMAIL&);
        CartaoAtividade ler(const Identificador&);
        void atualizar(const CartaoAtividade&, const EMAIL&);
        void excluir(const Identificador&, const EMAIL&);
        vector<Identificador> listar(const Identificador&);
        void mover(const Identificador&, const Timestamp&);
        int lerTempoCiclo(const Identificador&);
        double lerTempoCicloMedio(const Identificador&);
        int lerLeadTime(const Identificador&);
        double lerLeadTimeMedio(const Identificador&);
        int lerWIP(const Identificador&);
};

#endif // CONTROLADORAS_SERVICO_HPP_INCLUDED
