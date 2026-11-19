#include "apresentacao/entrada_usuario.hpp"

#include <cstdlib>
#include <cctype>


int EntradaUsuario::converterNumero(const string& texto) {
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


string EntradaUsuario::lerLinha(const string& rotulo) {
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


int EntradaUsuario::lerNumero(const string& rotulo) {
    return converterNumero(lerLinha(rotulo));
}


int EntradaUsuario::lerOpcao() {
    return lerNumero("Escolha uma opcao: ");
}


bool EntradaUsuario::lerCampo(const string& rotulo, const string& dica, Limite& campo) {
    while (true) {
        string texto = lerLinha("  " + rotulo + " (" + dica + "): ");

        if (texto.empty() || texto == "0") {
            return false;
        }

        try {
            campo.setValor(converterNumero(texto));
            return true;
        }
        catch (invalid_argument& excecao) {
            SaidaUsuario::aviso(string(excecao.what()) + " Formato: " + dica + ".");
            SaidaUsuario::aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
        }
    }
}
