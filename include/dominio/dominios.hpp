#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

class EMAIL {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Estado {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Identificador {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Limite {
    private:
        int valor;
        void validar(const int&) const;

    public:
        void setValor(int);
        int getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Nome {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Papel {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Prioridade {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Senha {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Tamanho {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Texto {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Timestamp {
    private:
        string valor;
        void validar(const string&) const;

    public:
        void setValor(string);
        string getValor() const;
};

#endif // DOMINIOS_HPP_INCLUDED
