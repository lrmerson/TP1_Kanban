#include "apresentacao/utilitarios_apresentacao.hpp"

#include <cstdlib>
#include <cctype>
#include <iomanip>

namespace {

int converterNumero(const string& texto) {

    if (texto.size() == 0 || texto.size() > 9) {

        return -1;
    }

    for (size_t i = 0; i < texto.size(); i++) {

        if (!isdigit(texto[i])) {
            return -1;
        }
    }

    return stoi(texto);
}

const string SEPARADOR = "+" + string(58, '-') + "+";

}


string lerLinha(string rotulo) {

    string texto;

    cout << rotulo;

    if (!getline(cin, texto)) {

        cout << endl;

        exit(0);
    }

    if (!texto.empty() && texto[texto.size() - 1] == '\r') {

        texto.erase(texto.size() - 1);
    }

    return texto;
}


int lerNumero(string rotulo) {

    return converterNumero(lerLinha(rotulo));
}


void linha(const string& texto) {

    cout << "| " << left << setw(56) << texto << " |" << endl;
}


void titulo(const string& texto, const string& subtitulo) {

    cout << endl << SEPARADOR << endl;

    linha("  " + texto);

    if (subtitulo != "") {

        linha("  " + subtitulo);
    }

    cout << SEPARADOR << endl;
}


void secao(const string& texto) {

    linha();

    linha( " " + texto + ":");
}


void item(int numero, const string& texto) {

    linha("   [" + to_string(numero) + "]" + (numero < 10 ? "  " : " ") + texto);
}


int lerOpcao() {

    cout << SEPARADOR << endl;

    return lerNumero("Escolha uma opcao: ");
}


void acao(const string& texto,bool pedeDados) {

    cout << endl << ">> " << texto << endl;

    if (pedeDados) {

        cout << "   (Digite 0 ou pressione Enter em branco para voltar)" << endl;
    }
}


void sucesso(const string& mensagem) {

    cout << endl << "[OK] " << mensagem << endl;
}


void erro(const string& mensagem) {

    cout << endl << "[ERRO] " << mensagem << endl;
}


void aviso(const string& mensagem) {

    cout << "  [!] " << mensagem << endl;
}


void cancelado() {

    cout << endl << "[--] Operacao cancelada." << endl;
}


void saida(const string& rotulo, const string& valor) {

    cout << "  " << left << setw(14) << rotulo << ": " << valor << endl;
}


void listaItens(const vector<string>& itens) {

    if (itens.empty()) {

        cout << "  (nenhum registro encontrado)" << endl;

        return;
    }

    for (size_t i = 0; i < itens.size(); i++) {

        cout << "  " << (i + 1) << ". " << itens[i] << endl;
    }

    cout << "  Total: " << itens.size() << endl;
}


bool lerCampo(const string& rotulo, const string& dica, Limite& campo) {

    while (true) {

        string texto = lerLinha("  " + rotulo +" (" + dica + "): ");

        if (texto.empty() || texto == "0") {

            return false;
        }

        try {

            campo.setValor(converterNumero(texto));

            return true;
        }
        catch (invalid_argument& excecao) {

            aviso(string(excecao.what()) + " Formato: " + dica + ".");

            aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
        }
    }
}
