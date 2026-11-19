#ifndef ENTRADA_USUARIO_HPP_INCLUDED
#define ENTRADA_USUARIO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "dominio/dominios.hpp"
#include "apresentacao/saida_usuario.hpp"

using namespace std;

class EntradaUsuario {
    private:
        EntradaUsuario() = delete;

        static int converterNumero(const string& texto);

    public:
        static string lerLinha(const string& rotulo);
        static int lerNumero(const string& rotulo);
        static int lerOpcao();

        template <typename T>
        static bool lerCampo(const string& rotulo, const string& dica, T& campo) {
            while (true) {
                string texto = lerLinha("  " + rotulo + " (" + dica + "): ");

                if (texto.empty() || texto == "0") {
                    return false;
                }

                try {
                    campo.setValor(texto);
                    return true;
                }
                catch (invalid_argument& excecao) {
                    SaidaUsuario::aviso(string(excecao.what()) + " Formato: " + dica + ".");
                    SaidaUsuario::aviso("Tente novamente, digite 0 ou pressione Enter para voltar.");
                }
            }
        }

        static bool lerCampo(const string& rotulo, const string& dica, Limite& campo);
};

#endif // ENTRADA_USUARIO_HPP_INCLUDED
