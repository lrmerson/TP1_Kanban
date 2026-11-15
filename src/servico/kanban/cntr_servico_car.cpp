#include "servico/kanban/cntr_servico_car.hpp"


void CntrServicoCartao::verificarGestor(const Identificador& quadro, const EMAIL& gestor) {
    Quadro quadroEncontrado;

    quadroEncontrado.setIdentificador(quadro);

    if (!ContainerQuadro::getInstancia()->pesquisar(&quadroEncontrado)) {
        throw runtime_error("Quadro nao encontrado.");
    }

    Projeto projeto;

    projeto.setIdentificador(quadroEncontrado.getProjeto());

    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)) {
        throw runtime_error("Projeto nao encontrado.");
    }

    if (projeto.getGestor().getValor() != gestor.getValor()) {
        throw runtime_error("Apenas o gestor do projeto pode realizar esta operacao.");
    }
}


int CntrServicoCartao::converterMinutos(const Timestamp& timestamp) {
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

    for (int i = 0; i < 12 && meses[i] != partes[1]; i++) {
        dias += diasMes[i];
    }

    dias += dia - 1;

    return dias * 24 * 60 + horas * 60 + minutos;
}


int CntrServicoCartao::contarFazendo(const Identificador& quadro) {
    int total = 0;

    vector<CartaoAtividade> cartoes =
        ContainerCartao::getInstancia()->listar(quadro);

    for (int i = 0; i < cartoes.size(); i++) {

        if (cartoes[i].getEstado().getValor() == "FAZENDO") {
            total++;
        }
    }

    return total;
}


void CntrServicoCartao::criar(const CartaoAtividade& cartao, const Identificador& quadro, const EMAIL& gestor) {
    Quadro quadroEncontrado;

    quadroEncontrado.setIdentificador(quadro);

    if (!ContainerQuadro::getInstancia()->pesquisar(&quadroEncontrado)) {
        throw runtime_error("Quadro nao encontrado.");
    }

    verificarGestor(quadro, gestor);

    CartaoAtividade novo = cartao;

    // FK do quadro.
    novo.setQuadro(quadro);

    /*
     * A FK desenvolvedor deve apontar para uma Pessoa existente.
     */
    Pessoa desenvolvedor;

    desenvolvedor.setEmail(
        novo.getDesenvolvedor()
    );

    if (!ContainerPessoa::getInstancia()->pesquisar(&desenvolvedor)) {
        throw runtime_error("Desenvolvedor nao encontrado.");
    }

    if (desenvolvedor.getPapel().getValor() != "DESENVOLVEDOR") {
        throw runtime_error("Pessoa informada nao possui papel de DESENVOLVEDOR.");
    }
    
    Estado estado;

    estado.setValor("A FAZER");

    novo.setEstado(estado);

    /*
     * O timestamp de entrada deve vir preenchido
     * no cartão criado pela camada de apresentação.
     *
     * Inicio e termino ainda não existem.
     */
    novo.setInicio(Timestamp());
    novo.setTermino(Timestamp());

    if (!ContainerCartao::getInstancia()->incluir(novo)) {
        throw runtime_error("Ja existe cartao com este identificador.");
    }
}


CartaoAtividade CntrServicoCartao::ler(const Identificador& identificador) {
    CartaoAtividade cartao;

    cartao.setIdentificador(identificador);

    if (!ContainerCartao::getInstancia()->pesquisar(&cartao)) {
        throw runtime_error("Cartao nao encontrado.");
    }
    return cartao;
}


void CntrServicoCartao::atualizar(const CartaoAtividade& cartao, const EMAIL& gestor) {
    CartaoAtividade atual = ler(cartao.getIdentificador());

    verificarGestor(atual.getQuadro(), gestor);

    /*
     * Apenas os campos editáveis são alterados.
     *
     * PK, FKs, estado e timestamps são preservados.
     */
    atual.setNome(cartao.getNome());

    atual.setDescricao(cartao.getDescricao());

    atual.setPrioridade(cartao.getPrioridade());

    atual.setTamanho(cartao.getTamanho());

    ContainerCartao::getInstancia()->atualizar(atual);
}


void CntrServicoCartao::excluir(const Identificador& identificador, const EMAIL& gestor) {

    CartaoAtividade cartao = ler(identificador);

    verificarGestor(cartao.getQuadro(),gestor);

    if (!ContainerCartao::getInstancia()->remover(identificador)) {
        throw runtime_error("Cartao nao encontrado.");
    }
}


vector<Identificador> CntrServicoCartao::listar(const Identificador& quadro) {
    Quadro quadroEncontrado;

    quadroEncontrado.setIdentificador(quadro);

    if (!ContainerQuadro::getInstancia()->pesquisar(&quadroEncontrado)) {
        throw runtime_error("Quadro nao encontrado.");
    }

    vector<Identificador> identificadores;

    vector<CartaoAtividade> cartoes =ContainerCartao::getInstancia()->listar(quadro);

    for (int i = 0; i < cartoes.size(); i++) {
        identificadores.push_back(cartoes[i].getIdentificador());
    }

    return identificadores;
}


void CntrServicoCartao::mover(const Identificador& identificador, const Timestamp& momento) {

    CartaoAtividade cartao = ler(identificador);

    string estado = cartao.getEstado().getValor();

    Estado novoEstado;

    if (estado == "A FAZER") {
        Quadro quadro;

        quadro.setIdentificador(cartao.getQuadro());

        if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)) {
            throw runtime_error("Quadro nao encontrado.");
        }

        if (contarFazendo(cartao.getQuadro()) >=quadro.getLimite().getValor()) {
            throw runtime_error("Limite WIP do quadro atingido.");
        }

        if (converterMinutos(momento) < converterMinutos(cartao.getEntrada())) {
            throw runtime_error("Momento anterior a entrada do cartao.");
        }

        novoEstado.setValor("FAZENDO");

        cartao.setInicio(momento);
    }

    else if (estado == "FAZENDO") {
        if (converterMinutos(momento) < converterMinutos(cartao.getInicio())) {
            throw runtime_error("Momento anterior ao inicio do cartao.");
        }

        novoEstado.setValor("FEITO");

        cartao.setTermino(momento);
    }

    else {
        throw runtime_error("Cartao ja esta na coluna FEITO.");
    }

    cartao.setEstado(novoEstado);

    ContainerCartao::getInstancia()->atualizar(cartao);
}
