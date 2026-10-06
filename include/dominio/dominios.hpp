#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

class Limite {
    private:
        int valor;

    public:
        void setValor(int);
        int getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Prioridade {
    private:
        string valor;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Estado {
    private:
        string valor;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Papel {
    private:
        string valor;

    public:
        void setValor(string);
        string getValor() const;
};

///////////////////////////////////////////////////////////////////////////////

class Tamanho {
    private:
        string valor;

    public:
        void setValor(string);
        string getValor() const;
};




#endif // DOMINIOS_HPP_INCLUDED