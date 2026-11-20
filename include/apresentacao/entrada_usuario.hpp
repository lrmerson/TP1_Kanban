#ifndef ENTRADA_USUARIO_HPP_INCLUDED
#define ENTRADA_USUARIO_HPP_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

#include "dominio/dominios.hpp"
#include "apresentacao/saida_usuario.hpp"

using namespace std;

/**
 * @brief Fornece funções estáticas para leitura e validação de entradas.
 */
class EntradaUsuario {
    private:
        EntradaUsuario() = delete;

        static int converterNumero(const string& texto);

    public:
        /**
         * @brief Lê uma linha de texto exibindo um rótulo.
         * @param rotulo Texto apresentado antes da entrada.
         * @return Texto informado pelo usuário.
         */
        static string lerLinha(const string& rotulo);

        /**
         * @brief Lê um número inteiro informado pelo usuário.
         * @param rotulo Texto apresentado antes da entrada.
         * @return Número inteiro convertido.
         */
        static int lerNumero(const string& rotulo);

        /**
         * @brief Lê uma opção numérica do menu.
         * @return Opção escolhida pelo usuário.
         */
        static int lerOpcao();

        /**
         * @brief Lê e valida um valor de domínio.
         * @tparam T Classe de domínio que fornece setValor.
         * @param rotulo Texto apresentado antes da entrada.
         * @param dica Formato esperado para o valor.
         * @param campo Objeto que receberá o valor validado.
         * @return true se o valor foi lido; false se a operação foi cancelada.
         */
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

        /**
         * @brief Lê e valida um limite WIP.
         * @param rotulo Texto apresentado antes da entrada.
         * @param dica Formato esperado para o limite.
         * @param campo Objeto que receberá o limite validado.
         * @return true se o valor foi lido; false se a operação foi cancelada.
         */
        static bool lerCampo(const string& rotulo, const string& dica, Limite& campo);
};

#endif // ENTRADA_USUARIO_HPP_INCLUDED
