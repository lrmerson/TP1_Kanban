#include "apresentacao/saida_usuario.hpp"

const string SaidaUsuario::SEPARADOR = "+" + string(58, '-') + "+";


void SaidaUsuario::linha(const string& texto) {
    cout << "| " << left << setw(56) << texto << " |" << endl;
}


void SaidaUsuario::titulo(const string& texto, const string& subtitulo) {
    cout << endl << SEPARADOR << endl;

    linha("  " + texto);

    if (subtitulo != "") {
        linha("  " + subtitulo);
    }

    cout << SEPARADOR << endl;
}


void SaidaUsuario::secao(const string& texto) {
    linha();
    linha(" " + texto + ":");
}


void SaidaUsuario::item(int numero, const string& texto) {
    linha("   [" + to_string(numero) + "]" + (numero < 10 ? "  " : " ") + texto);
}


void SaidaUsuario::separador() {
    cout << SEPARADOR << endl;
}


void SaidaUsuario::acao(const string& texto, bool pedeDados) {
    cout << endl << ">> " << texto << endl;

    if (pedeDados) {
        cout << "   (Digite 0 ou pressione Enter em branco para voltar)" << endl;
    }
}


void SaidaUsuario::sucesso(const string& mensagem) {
    cout << endl << "[OK] " << mensagem << endl;
}


void SaidaUsuario::erro(const string& mensagem) {
    cout << endl << "[ERRO] " << mensagem << endl;
}


void SaidaUsuario::aviso(const string& mensagem) {
    cout << "  [!] " << mensagem << endl;
}


void SaidaUsuario::cancelado() {
    cout << endl << "[--] Operacao cancelada." << endl;
}


void SaidaUsuario::saida(const string& rotulo, const string& valor) {
    cout << "  " << left << setw(14) << rotulo << ": " << valor << endl;
}


void SaidaUsuario::listaItens(const vector<string>& itens) {
    if (itens.empty()) {
        cout << "  (nenhum registro encontrado)" << endl;
        return;
    }

    for (size_t i = 0; i < itens.size(); i++) {
        cout << "  " << (i + 1) << ". " << itens[i] << endl;
    }

    cout << "  Total: " << itens.size() << endl;
}
