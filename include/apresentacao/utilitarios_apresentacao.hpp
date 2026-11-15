#ifndef UTILITARIOS_APRESENTACAO_HPP_INCLUDED
#define UTILITARIOS_APRESENTACAO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "dominio/dominios.hpp"

using namespace std;

string lerLinha(string rotulo);

int lerNumero(string rotulo);

void linha(const string& texto = "");

void titulo(const string& texto,const string& subtitulo = "");

void secao(const string& texto);

void item(int numero,const string& texto);

int lerOpcao();

void acao(const string& texto,bool pedeDados = true);

void sucesso(const string& mensagem);

void erro(const string& mensagem);

void aviso(const string& mensagem);

void cancelado();

void saida(const string& rotulo, const string& valor);

void listaItens(const vector<string>& itens);

template <typename T>
bool lerCampo(const string& rotulo, const string& dica, T& campo) {
    while (true) {

        string texto = lerLinha("  " + rotulo +" (" + dica + "): ");

        if (texto.empty() || texto == "0") {
            return false;
        }

        try {

            campo.setValor(texto);

            return true;
        }
        catch (invalid_argument& excecao) {
          
            aviso(tring(excecao.what()) +" Formato: " +dica + ".");

            aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
        }
    }
}

bool lerCampo(const string& rotulo, const string& dica, Limite& campo);

#endif // UTILITARIOS_APRESENTACAO_HPP_INCLUDED
