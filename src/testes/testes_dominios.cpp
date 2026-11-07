#include "testes/testes_dominios.hpp"

const vector<string> TUEMAIL::VALORES_VALIDOS = {"joao.silva@unb.br", "a1-b2@mail-server.com", "x@y"};
const vector<string> TUEMAIL::VALORES_INVALIDOS = {"", "joao", "a@@b.com", ".joao@unb.br", "joao.@unb.br", "joao..s@unb.br", "Joao@unb.br", "joao@-unb.br", "joao@unb..br", "joao@unb-.br"};

void TUEMAIL::setUp() {
    email = new EMAIL();
    estado = SUCESSO;
}

void TUEMAIL::tearDown() {
    delete email;
}

void TUEMAIL::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            email->setValor(valor);
            if (email->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUEMAIL::testarCenarioFalha() {
    email->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            email->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (email->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUEMAIL::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUEstado::VALORES_VALIDOS = {"A FAZER", "FAZENDO", "FEITO"};
const vector<string> TUEstado::VALORES_INVALIDOS = {"", "A_FAZER", "feito", "PRONTO"};

void TUEstado::setUp() {
    estadoDominio = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown() {
    delete estadoDominio;
}

void TUEstado::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            estadoDominio->setValor(valor);
            if (estadoDominio->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUEstado::testarCenarioFalha() {
    estadoDominio->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            estadoDominio->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (estadoDominio->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUEstado::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUIdentificador::VALORES_VALIDOS = {"abc123", "XYZ999", "aBc000"};
const vector<string> TUIdentificador::VALORES_INVALIDOS = {"", "ab1234", "abc12", "abc1234", "1bc123", "abcd23"};

void TUIdentificador::setUp() {
    identificador = new Identificador();
    estado = SUCESSO;
}

void TUIdentificador::tearDown() {
    delete identificador;
}

void TUIdentificador::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            identificador->setValor(valor);
            if (identificador->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUIdentificador::testarCenarioFalha() {
    identificador->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            identificador->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (identificador->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUIdentificador::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<int> TULimite::VALORES_VALIDOS = {1, 10, 25};
const vector<int> TULimite::VALORES_INVALIDOS = {-1, 0, 26, 100};

void TULimite::setUp() {
    limite = new Limite();
    estado = SUCESSO;
}

void TULimite::tearDown() {
    delete limite;
}

void TULimite::testarCenarioSucesso() {
    for (int valor : VALORES_VALIDOS) {
        try {
            limite->setValor(valor);
            if (limite->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TULimite::testarCenarioFalha() {
    limite->setValor(VALORES_VALIDOS[0]);
    for (int valor : VALORES_INVALIDOS) {
        try {
            limite->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (limite->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TULimite::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUNome::VALORES_VALIDOS = {"Joao", "Ana Maria", "A", "Joao da Silva X"};
const vector<string> TUNome::VALORES_INVALIDOS = {"", " Joao", "Joao ", "Ana  Maria", "Joao1", "Nome muito grande"};

void TUNome::setUp() {
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown() {
    delete nome;
}

void TUNome::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            nome->setValor(valor);
            if (nome->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUNome::testarCenarioFalha() {
    nome->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            nome->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (nome->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUNome::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUPapel::VALORES_VALIDOS = {"GESTOR", "DESENVOLVEDOR"};
const vector<string> TUPapel::VALORES_INVALIDOS = {"", "gestor", "ADMIN"};

void TUPapel::setUp() {
    papel = new Papel();
    estado = SUCESSO;
}

void TUPapel::tearDown() {
    delete papel;
}

void TUPapel::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            papel->setValor(valor);
            if (papel->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUPapel::testarCenarioFalha() {
    papel->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            papel->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (papel->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUPapel::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUPrioridade::VALORES_VALIDOS = {"ALTA", "MEDIA", "BAIXA"};
const vector<string> TUPrioridade::VALORES_INVALIDOS = {"", "alta", "MÉDIA", "URGENTE"};

void TUPrioridade::setUp() {
    prioridade = new Prioridade();
    estado = SUCESSO;
}

void TUPrioridade::tearDown() {
    delete prioridade;
}

void TUPrioridade::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            prioridade->setValor(valor);
            if (prioridade->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUPrioridade::testarCenarioFalha() {
    prioridade->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            prioridade->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (prioridade->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUPrioridade::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUSenha::VALORES_VALIDOS = {"abc12", "1a2b3", "A1111"};
const vector<string> TUSenha::VALORES_INVALIDOS = {"", "abcde", "12345", "abc1", "abc123", "ab#12"};

void TUSenha::setUp() {
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete senha;
}

void TUSenha::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            senha->setValor(valor);
            if (senha->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUSenha::testarCenarioFalha() {
    senha->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            senha->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (senha->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUSenha::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUTamanho::VALORES_VALIDOS = {"GRANDE", "MEDIO", "PEQUENO"};
const vector<string> TUTamanho::VALORES_INVALIDOS = {"", "grande", "ENORME"};

void TUTamanho::setUp() {
    tamanho = new Tamanho();
    estado = SUCESSO;
}

void TUTamanho::tearDown() {
    delete tamanho;
}

void TUTamanho::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            tamanho->setValor(valor);
            if (tamanho->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUTamanho::testarCenarioFalha() {
    tamanho->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            tamanho->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (tamanho->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUTamanho::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUTexto::VALORES_VALIDOS = {"Projeto Kanban.", "Teste, com pontuacao.", "A."};
const vector<string> TUTexto::VALORES_INVALIDOS = {"", "projeto.", "Projeto", "Projeto!.", "Texto com mais de trinta caract.", "Projeto @ unb."};

void TUTexto::setUp() {
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown() {
    delete texto;
}

void TUTexto::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            texto->setValor(valor);
            if (texto->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUTexto::testarCenarioFalha() {
    texto->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            texto->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (texto->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUTexto::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

const vector<string> TUTimestamp::VALORES_VALIDOS = {"01-JAN-2000-00:00", "29-FEV-2024-12:30", "31-DEZ-2099-23:59"};
const vector<string> TUTimestamp::VALORES_INVALIDOS = {"", "29-FEV-2023-10:00", "31-ABR-2025-10:00", "32-JAN-2025-10:00", "10-JAN-1999-10:00", "10-ABC-2025-10:00", "10-JAN-2025-24:00", "10-JAN-2025-10:60", "10-JAN-2025", "0-JAN-2025-10:00"};

void TUTimestamp::setUp() {
    timestamp = new Timestamp();
    estado = SUCESSO;
}

void TUTimestamp::tearDown() {
    delete timestamp;
}

void TUTimestamp::testarCenarioSucesso() {
    for (const string &valor : VALORES_VALIDOS) {
        try {
            timestamp->setValor(valor);
            if (timestamp->getValor() != valor)
                estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            estado = FALHA;
        }
    }
}

void TUTimestamp::testarCenarioFalha() {
    timestamp->setValor(VALORES_VALIDOS[0]);
    for (const string &valor : VALORES_INVALIDOS) {
        try {
            timestamp->setValor(valor);
            estado = FALHA;
        }
        catch (invalid_argument &excecao) {
            if (timestamp->getValor() != VALORES_VALIDOS[0])
                estado = FALHA;
        }
    }
}

int TUTimestamp::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
