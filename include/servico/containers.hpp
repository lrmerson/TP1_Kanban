#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>

#include "entidades/entidades.hpp"

using namespace std;

class ContainerPessoa {
    private:
        map<string, Pessoa> container;
        static ContainerPessoa *instancia;
        ContainerPessoa() {}

    public:
        static ContainerPessoa* getInstancia();
        bool incluir(const Pessoa&);
        bool remover(const string&);
        bool pesquisar(Pessoa*);
        bool atualizar(const Pessoa&);
        vector<Pessoa> listar();
};

///////////////////////////////////////////////////////////////////////////////

class ContainerProjeto {
    private:
        map<string, Projeto> container;
        map<string, string> gestores;
        static ContainerProjeto *instancia;
        ContainerProjeto() {}

    public:
        static ContainerProjeto* getInstancia();
        bool incluir(const Projeto&, const string&);
        bool remover(const string&);
        bool pesquisar(Projeto*);
        bool atualizar(const Projeto&);
        string getGestor(const string&);
        vector<Projeto> listar();
};

///////////////////////////////////////////////////////////////////////////////

class ContainerQuadro {
    private:
        map<string, Quadro> container;
        map<string, string> projetos;
        static ContainerQuadro *instancia;
        ContainerQuadro() {}

    public:
        static ContainerQuadro* getInstancia();
        bool incluir(const Quadro&, const string&);
        bool remover(const string&);
        bool pesquisar(Quadro*);
        bool atualizar(const Quadro&);
        string getProjeto(const string&);
        vector<Quadro> listar(const string&);
};

///////////////////////////////////////////////////////////////////////////////

class ContainerCartao {
    private:
        map<string, CartaoAtividade> container;
        map<string, string> quadros;
        static ContainerCartao *instancia;
        ContainerCartao() {}

    public:
        static ContainerCartao* getInstancia();
        bool incluir(const CartaoAtividade&, const string&);
        bool remover(const string&);
        bool pesquisar(CartaoAtividade*);
        bool atualizar(const CartaoAtividade&);
        string getQuadro(const string&);
        vector<CartaoAtividade> listar(const string&);
};

#endif // CONTAINERS_HPP_INCLUDED
