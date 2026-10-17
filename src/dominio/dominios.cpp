#include "dominios.hpp"
#include <cctype>


void EMAIL::validar(const string& valor) const {
    //verifica se há exatamente 1 @ no valor inserido
    int divisor = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '@') {
            divisor = divisor + 1;
        }
    }
    if (divisor != 1) {
        throw invalid_argument("Email invalido.");
    }
    //separa o valor inserido nas duas partes: local e dominio
    string partes[2];
    int parte = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '@') {
            parte = parte + 1;
        } else {
            partes[parte] = partes[parte] + valor[i];
        }
    }
    string local = partes[0];
    string dominio = partes[1];
    //valida formato da parte local
    if (local.size() == 0 || local.size() > 64 || local[0] == '-' || local[local.size() - 1] == '-' || local[0] == '.' || local[local.size() - 1] == '.') {
        throw invalid_argument("Email invalido.");
    }
    for (int i = 0; i < local.size(); i++) {
        if (!islower(local[i]) && !isdigit(local[i]) && local[i] != '.' && local[i] != '-') {
            throw invalid_argument("Email invalido.");
        }
        if (local[i] == '.' || local[i] == '-') {
            if (!islower(local[i + 1]) && !isdigit(local[i + 1])) {
                throw invalid_argument("Email invalido.");
            }
        }
    }
    //valida formato da parte dominio
    if (dominio.size() == 0 || dominio.size() > 255 || dominio[0] == '-' || dominio[dominio.size() - 1] == '-' || dominio[0] == '.' || dominio[dominio.size() - 1] == '.') {
        throw invalid_argument("Email invalido.");
    }

    for (int i = 0; i < dominio.size(); i++) {
        if (!islower(dominio[i]) && !isdigit(dominio[i]) && dominio[i] != '.' && dominio[i] != '-') {
            throw invalid_argument("Email invalido.");
        }
        if (dominio[i] == '.') {
            if (dominio[i - 1] == '-' || dominio[i - 1] == '.' || dominio[i + 1] == '-' || dominio[i + 1] == '.') {
                throw invalid_argument("Email invalido.");
            }
        }
    }

}

void EMAIL::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string EMAIL::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Estado::validar(const string& valor) const {
    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO") {
        throw invalid_argument("Estado invalido.");
    }

    this->valor = valor;
}

void Estado::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Estado::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Identificador::validar(const string& valor) const {
    if (valor.size() != 6) {
        throw invalid_argument("Identificador invalido.");
    }
    for (int i = 0; i < 3; i++) {
        if (!isalpha(valor[i])) {
            throw invalid_argument("Identificador invalido.");
        }
    }
    for (int i = 3; i < 6; i++) {
        if (!isdigit(valor[i])) {
            throw invalid_argument("Identificador invalido.");
        }
    }
    this->valor= valor;
}

void Identificador::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Identificador::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Limite::validar(const int& valor) const {
    if (valor < 1 || valor > 25) {
        throw invalid_argument("Limite invalido.");
    }

    this->valor = valor;
}

void Limite::setValor(int valor) {
    validar(valor);
    this->valor = valor;

int Limite::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Nome::validar(const string& valor) const {
    if (valor.size() == 0 || valor.size() > 15) {
        throw invalid_argument("Nome invalido.");
    }
    if (!isalpha(valor[0]) || !isalpha(valor[valor.size() - 1])) {
        throw invalid_argument("Nome invalido.");
    }
    for (int i = 1; i < valor.size() - 1; i++) {
        if (!isalpha(valor[i]) && valor[i] != ' ') {
            throw invalid_argument("Nome invalido.");
        }
        if (valor[i] == ' ') {
            if (!isalpha(valor[i + 1])) {
                throw invalid_argument("Nome invalido.");
            }
        }
    }
    this->valor = valor;
}

void Nome::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Nome::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Papel::validar(const string& valor) const {
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR") {
        throw invalid_argument("Papel invalido.");
    }

    this->valor = valor;
}

void Papel::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Papel::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Prioridade::validar(const string& valor) const {
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw invalid_argument("Prioridade invalida.");
    }

    this->valor = valor;
}

void Prioridade::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Prioridade::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Senha::validar(const string& valor) const {
    if (valor.size() != 5) {
        throw invalid_argument("Senha invalida.");
    }
    int temletra = 0;
    int temdigito = 0;
    for (int i = 0; i < 5; i++) {
        if (!isalpha(valor[i]) && !isdigit(valor[i])) {
            throw invalid_argument("Senha invalida.");
        }
        if (isalpha(valor[i])) {
            temletra = 1;
        }
        if (isdigit(valor[i])) {
            temdigito = 1;
        }
    }
    if (temletra == 0 || temdigito == 0) {
        throw invalid_argument("Senha invalida.");
    }
    this->valor = valor;
}

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Senha::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Tamanho::validar(const string& valor) const {
    if (valor != "GRANDE" && valor != "MÉDIO" && valor != "PEQUENO") {
        throw invalid_argument("Tamanho invalido.");
    }

    this->valor = valor;
}

void Tamanho::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Tamanho::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Texto::validar(const string& valor) const {
    if (valor.size() == 0 || valor.size() > 30) {
        throw invalid_argument("Texto invalido.");
    }
    if (!isupper(valor[0]) || valor[valor.size() - 1] != '.') {
        throw invalid_argument("Texto invalido.");
    }
    string pontuacao = ",;.:?!";
    for (int i = 0; i < valor.size() - 1; i++) {
        if (!isalpha(valor[i]) && !isdigit(valor[i]) && valor[i] != ' ' && pontuacao.find(valor[i]) == string::npos) {
            throw invalid_argument("Texto invalido.");
        }
        if (pontuacao.find(valor[i]) != string::npos) {
            if (pontuacao.find(valor[i + 1]) != string::npos) {
                throw invalid_argument("Texto invalido.");
            }
        }
    }
    this->valor = valor;
}

void Texto::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Texto::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////

void Timestamp::validar(const string& valor) const {
    //verifica se tem exatamente 3 hifens no valor inserido
    int divisor = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '-') {
            divisor = divisor + 1;
        }
    }
    if (divisor != 3) {
        throw invalid_argument("Timestamp invalida.");
    }
    //separa o conteudo nas 4 partes: dia, mes, ano, horario
    string partes[4];
    int parte = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '-') {
            parte = parte + 1;
        } else {
            partes[parte] = partes[parte] + valor[i];
        }
    }

    string diatexto = partes[0];
    string mes = partes[1];
    string anotexto = partes[2];
    string horario = partes[3];
    //verifica se os valores de dia e ano sao de fato digitos
    if (diatexto.size() == 0 || diatexto.size() > 2) {
        throw invalid_argument("Timestamp invalida.");
    }
    for (int i = 0; i < diatexto.size(); i++) {
        if (!isdigit(diatexto[i])) {
            throw invalid_argument("Timestamp invalida.");
        }
    }
    if (anotexto.size() != 4) {
        throw invalid_argument("Timestamp invalida.");
    }
    for (int i = 0; i < anotexto.size(); i++) {
        if (!isdigit(anotexto[i])) {
            throw invalid_argument("Timestamp invalida.");
        }
    }
    //se sao digitos, transforma em int
    int dia = stoi(diatexto);
    int ano = stoi(anotexto);

    if (dia < 1 || dia > 31) {
        throw invalid_argument("Timestamp invalida.");
    }
    if (mes != "JAN" && mes != "FEV" && mes != "MAR" && mes != "ABR" && mes != "MAI" && mes != "JUN" && mes != "JUL" && mes != "AGO" && mes != "SET" && mes != "OUT" && mes != "NOV" && mes != "DEZ") {
        throw invalid_argument("Timestamp invalida.");
    }
    if (ano < 2000 || ano > 2099) {
        throw invalid_argument("Timestamp invalida.");
    }
    //verifica horario valido entre 00:00 e 23:59
    if (horario.size() != 5 || horario[2] != ':') {
        throw invalid_argument("Timestamp invalida.");
    }
    if (!isdigit(horario[0]) || !isdigit(horario[1]) || !isdigit(horario[3]) || !isdigit(horario[4])) {
        throw invalid_argument("Timestamp invalida.");
    }
    int horas = stoi(horario.substr(0,2));
    int minutos = stoi(horario.substr(3,2));

    if (horas > 23) {
        throw invalid_argument("Timestamp invalida.");
    }
    if (minutos > 59) {
        throw invalid_argument("Timestamp invalida.");
    }
    //verifica datas de meses com 30 dias
    if ((mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV") && dia == 31) {
        throw invalid_argument("Timestamp invalida.");
    }
    //verifica datas de fevereiro em anos bissextos e não bissextos
    if (mes == "FEV" && (ano % 4 == 0) && dia > 29) {
        throw invalid_argument("Timestamp invalida.");
    } else if (mes == "FEV" && (ano % 4 != 0) && dia > 28) {
        throw invalid_argument("Timestamp invalida.");
    }
    this->valor = valor;
}

void Timestamp::setValor(string valor) {
    validar(valor);
    this->valor = valor;

string Timestamp::getValor() const {
    return valor;
}

///////////////////////////////////////////////////////////////////////////////
