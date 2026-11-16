#ifndef CNTR_SERVICO_MET_HPP_INCLUDED
#define CNTR_SERVICO_MET_HPP_INCLUDED

#include <stdexcept>
#include <vector>
#include <string>

#include "servico/kanban/container_car.hpp"
#include "servico/kanban/container_qua.hpp"

using namespace std;

/**
 * @brief Implementa os serviços relacionados às métricas Kanban.
 */
class CntrServicoMetricas {
    private:

        /**
         * @brief Converte um timestamp para quantidade de minutos.
         *
         * Utilizado para calcular diferenças entre os momentos
         * registrados nos cartões.
         */
        int converterMinutos(const Timestamp& timestamp);

        /**
         * @brief Conta os cartões que estão na coluna FAZENDO.
         *
         * @param quadro Identificador do quadro.
         * @return Quantidade de cartões em andamento.
         */
        int contarFazendo(const Identificador& quadro);

        /**
         * @brief Verifica se o quadro informado existe.
         */
        void verificarQuadro(const Identificador& quadro);

    public:

        /**
         * @brief Calcula o tempo de ciclo de um cartão concluído.
         *
         * @return Quantidade de minutos entre FAZENDO e FEITO.
         */
        int lerTempoCiclo(const Identificador& identificador);

        /**
         * @brief Calcula o tempo de ciclo médio dos cartões
         * concluídos de um quadro.
         */
        double lerTempoCicloMedio(const Identificador& quadro);

        /**
         * @brief Calcula o lead time de um cartão concluído.
         *
         * @return Quantidade de minutos entre A FAZER e FEITO.
         */
        int lerLeadTime(const Identificador& identificador);

        /**
         * @brief Calcula o lead time médio dos cartões
         * concluídos de um quadro.
         */
        double lerLeadTimeMedio(const Identificador& quadro);

        /**
         * @brief Retorna o WIP atual de um quadro.
         *
         * @return Quantidade de cartões na coluna FAZENDO.
         */
        int lerWIP(const Identificador& quadro);
};

#endif // CNTR_SERVICO_MET_HPP_INCLUDED
