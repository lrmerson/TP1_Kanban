#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

class Pessoa {
    private:
        EMAIL email;
        Nome nome;
        Senha senha;
        Papel papel;

    public:
        void setEmail(const EMAIL&);
        EMAIL getEmail() const;

        void setNome(const Nome&);
        Nome getNome() const;

        void setSenha(const Senha&);
        Senha getSenha() const;

        void setPapel(const Papel&);
        Papel getPapel() const;
};

///////////////////////////////////////////////////////////////////////////////

class Projeto {
    private:
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;

    public:
        void setIdentificador(const Identificador&);
        Identificador getIdentificador() const;

        void setNome(const Nome&);
        Nome getNome() const;

        void setDescricao(const Texto&);
        Texto getDescricao() const;

        void setInicio(const Timestamp&);
        Timestamp getInicio() const;

        void setTermino(const Timestamp&);
        Timestamp getTermino() const;
};

///////////////////////////////////////////////////////////////////////////////

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
        void setIdentificador(const Identificador&);
        Identificador getIdentificador() const;

        void setNome(const Nome&);
        Nome getNome() const;

        void setDescricao(const Texto&);
        Texto getDescricao() const;

        void setPrioridade(const Prioridade&);
        Prioridade getPrioridade() const;

        void setEstado(const Estado&);
        Estado getEstado() const;

        void setTamanho(const Tamanho&);
        Tamanho getTamanho() const;

        void setEntrada(const Timestamp&);
        Timestamp getEntrada() const;

        void setInicio(const Timestamp&);
        Timestamp getInicio() const;

        void setTermino(const Timestamp&);
        Timestamp getTermino() const;
};

///////////////////////////////////////////////////////////////////////////////

class Quadro {
    private:
        Identificador identificador;
        Nome nome;
        Limite limite;

    public:
        void setIdentificador(const Identificador&);
        Identificador getIdentificador() const;

        void setNome(const Nome&);
        Nome getNome() const;

        void setLimite(const Limite&);
        Limite getLimite() const;
};




#endif // ENTIDADES_HPP_INCLUDED
