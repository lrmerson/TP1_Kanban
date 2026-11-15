#include "servico/kanban/cntr_servico_met.hpp"


int CntrServicoMetricas::converterMinutos(
    const Timestamp& timestamp
) {

    string valor = timestamp.getValor();

    string partes[4];

    int parte = 0;

    for (int i = 0; i < valor.size(); i++) {

        if (valor[i] == '-') {
            parte++;
        }
        else {
            partes[parte] += valor[i];
        }
    }

    string meses[12] = {
        "JAN", "FEV", "MAR", "ABR",
        "MAI", "JUN", "JUL", "AGO",
        "SET", "OUT", "NOV", "DEZ"
    };

    int diasMes[12] = {
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    int dia = stoi(partes[0]);
    int ano = stoi(partes[2]);

    int horas =
        stoi(partes[3].substr(0, 2));

    int minutos =
        stoi(partes[3].substr(3, 2));

    if (ano % 4 == 0) {
        diasMes[1] = 29;
    }

    int dias = 0;

    for (int i = 2000; i < ano; i++) {

        if (i % 4 == 0) {
            dias += 366;
        }
        else {
            dias += 365;
        }
    }

    for (int i = 0;
         i < 12 && meses[i] != partes[1];
         i++) {

        dias += diasMes[i];
    }

    dias += dia - 1;

    return dias * 24 * 60 +
           horas * 60 +
           minutos;
}


void CntrServicoMetricas::verificarQuadro(
    const Identificador& quadro
) {

    Quadro quadroEncontrado;

    quadroEncontrado.setIdentificador(
        quadro
    );

    if (!ContainerQuadro::getInstancia()->pesquisar(
            &quadroEncontrado)) {

        throw runtime_error(
            "Quadro nao encontrado."
        );
    }
}


int CntrServicoMetricas::contarFazendo(
    const Identificador& quadro
) {

    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(
            quadro
        );

    int total = 0;

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getEstado().getValor() ==
            "FAZENDO") {

            total++;
        }
    }

    return total;
}


int CntrServicoMetricas::lerTempoCiclo(
    const Identificador& identificador
) {

    CartaoAtividade cartao;

    cartao.setIdentificador(
        identificador
    );

    if (!ContainerCartao::getInstancia()->pesquisar(
            &cartao)) {

        throw runtime_error(
            "Cartao nao encontrado."
        );
    }

    if (cartao.getEstado().getValor() != "FEITO") {

        throw runtime_error(
            "Cartao ainda nao foi concluido."
        );
    }

    return converterMinutos(
               cartao.getTermino()
           )
           -
           converterMinutos(
               cartao.getInicio()
           );
}


double CntrServicoMetricas::lerTempoCicloMedio(
    const Identificador& quadro
) {

    verificarQuadro(
        quadro
    );

    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(
            quadro
        );

    int soma = 0;
    int total = 0;

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getEstado().getValor() ==
            "FEITO") {

            soma +=
                converterMinutos(
                    cartoes[i].getTermino()
                )
                -
                converterMinutos(
                    cartoes[i].getInicio()
                );

            total++;
        }
    }

    if (total == 0) {

        throw runtime_error(
            "Nao ha cartoes concluidos no quadro."
        );
    }

    return (double) soma / total;
}


int CntrServicoMetricas::lerLeadTime(
    const Identificador& identificador
) {

    CartaoAtividade cartao;

    cartao.setIdentificador(
        identificador
    );

    if (!ContainerCartao::getInstancia()->pesquisar(
            &cartao)) {

        throw runtime_error(
            "Cartao nao encontrado."
        );
    }

    if (cartao.getEstado().getValor() != "FEITO") {

        throw runtime_error(
            "Cartao ainda nao foi concluido."
        );
    }

    return converterMinutos(
               cartao.getTermino()
           )
           -
           converterMinutos(
               cartao.getEntrada()
           );
}


double CntrServicoMetricas::lerLeadTimeMedio(
    const Identificador& quadro
) {

    verificarQuadro(
        quadro
    );

    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(
            quadro
        );

    int soma = 0;
    int total = 0;

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getEstado().getValor() ==
            "FEITO") {

            soma +=
                converterMinutos(
                    cartoes[i].getTermino()
                )
                -
                converterMinutos(
                    cartoes[i].getEntrada()
                );

            total++;
        }
    }

    if (total == 0) {

        throw runtime_error(
            "Nao ha cartoes concluidos no quadro."
        );
    }

    return (double) soma / total;
}


int CntrServicoMetricas::lerWIP(
    const Identificador& quadro
) {

    verificarQuadro(
        quadro
    );

    return contarFazendo(
        quadro
    );
}
