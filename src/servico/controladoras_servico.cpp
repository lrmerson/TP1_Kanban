#include "servico/controladoras_servico.hpp"

bool CntrServicoPessoa::autenticar(const EMAIL& email, const Senha& senha) {
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)) {
        return false;
    }
    if (pessoa.getSenha().getValor() != senha.getValor()) {
        return false;
    }
    return true;
}

void CntrServicoPessoa::criar(const Pessoa& pessoa) {
    if (!ContainerPessoa::getInstancia()->incluir(pessoa)) {
        throw runtime_error("Ja existe pessoa com este email.");
    }
}

Pessoa CntrServicoPessoa::ler(const EMAIL& email) {
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa)) {
        throw runtime_error("Pessoa nao encontrada.");
    }
    return pessoa;
}

void CntrServicoPessoa::atualizar(const Pessoa& pessoa) {
    Pessoa antiga;
    antiga.setEmail(pessoa.getEmail());
    if (!ContainerPessoa::getInstancia()->pesquisar(&antiga)) {
        throw runtime_error("Pessoa nao encontrada.");
    }
    if (antiga.getPapel().getValor() == "GESTOR" && pessoa.getPapel().getValor() != "GESTOR") {
        vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
        for (int i = 0; i < projetos.size(); i++) {
            string id = projetos[i].getIdentificador().getValor();
            if (ContainerProjeto::getInstancia()->getGestor(id) == pessoa.getEmail().getValor()) {
                throw runtime_error("Pessoa e gestora de projeto e nao pode deixar de ser GESTOR.");
            }
        }
    }
    ContainerPessoa::getInstancia()->atualizar(pessoa);
}

void CntrServicoPessoa::excluir(const EMAIL& email) {
    vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
    for (int i = 0; i < projetos.size(); i++) {
        string id = projetos[i].getIdentificador().getValor();
        if (ContainerProjeto::getInstancia()->getGestor(id) == email.getValor()) {
            throw runtime_error("Pessoa e gestora de projeto e nao pode ser excluida.");
        }
    }
    if (!ContainerPessoa::getInstancia()->remover(email.getValor())) {
        throw runtime_error("Pessoa nao encontrada.");
    }
}

vector<EMAIL> CntrServicoPessoa::listar() {
    vector<EMAIL> emails;
    vector<Pessoa> pessoas = ContainerPessoa::getInstancia()->listar();
    for (int i = 0; i < pessoas.size(); i++) {
        emails.push_back(pessoas[i].getEmail());
    }
    return emails;
}

void CntrServicoProjeto::verificarGestor(const Identificador& identificador, const EMAIL& usuario) {
    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)) {
        throw runtime_error("Projeto nao encontrado.");
    }
    if (ContainerProjeto::getInstancia()->getGestor(identificador.getValor()) != usuario.getValor()) {
        throw runtime_error("Apenas o gestor do projeto pode realizar esta operacao.");
    }
}

void CntrServicoProjeto::criar(const Projeto& projeto, const EMAIL& usuario) {
    Pessoa pessoa;
    pessoa.setEmail(usuario);
    if (!ContainerPessoa::getInstancia()->pesquisar(&pessoa) || pessoa.getPapel().getValor() != "GESTOR") {
        throw runtime_error("Apenas GESTOR pode criar projeto.");
    }
    if (!ContainerProjeto::getInstancia()->incluir(projeto, usuario.getValor())) {
        throw runtime_error("Ja existe projeto com este identificador.");
    }
}

Projeto CntrServicoProjeto::ler(const Identificador& identificador) {
    Projeto projeto;
    projeto.setIdentificador(identificador);
    if (!ContainerProjeto::getInstancia()->pesquisar(&projeto)) {
        throw runtime_error("Projeto nao encontrado.");
    }
    return projeto;
}

void CntrServicoProjeto::atualizar(const Projeto& projeto, const EMAIL& usuario) {
    verificarGestor(projeto.getIdentificador(), usuario);
    ContainerProjeto::getInstancia()->atualizar(projeto);
}

void CntrServicoProjeto::excluir(const Identificador& identificador, const EMAIL& usuario) {
    verificarGestor(identificador, usuario);
    if (ContainerQuadro::getInstancia()->listar(identificador.getValor()).size() > 0) {
        throw runtime_error("Projeto possui quadros e nao pode ser excluido.");
    }
    ContainerProjeto::getInstancia()->remover(identificador.getValor());
}

vector<Identificador> CntrServicoProjeto::listar() {
    vector<Identificador> identificadores;
    vector<Projeto> projetos = ContainerProjeto::getInstancia()->listar();
    for (int i = 0; i < projetos.size(); i++) {
        identificadores.push_back(projetos[i].getIdentificador());
    }
    return identificadores;
}

void CntrServicoQuadro::verificarGestor(const string& projeto, const EMAIL& usuario) {
    if (ContainerProjeto::getInstancia()->getGestor(projeto) != usuario.getValor()) {
        throw runtime_error("Apenas o gestor do projeto pode realizar esta operacao.");
    }
}

void CntrServicoQuadro::criar(const Quadro& quadro, const Identificador& projeto, const EMAIL& usuario) {
    Projeto auxiliar;
    auxiliar.setIdentificador(projeto);
    if (!ContainerProjeto::getInstancia()->pesquisar(&auxiliar)) {
        throw runtime_error("Projeto nao encontrado.");
    }
    verificarGestor(projeto.getValor(), usuario);
    if (!ContainerQuadro::getInstancia()->incluir(quadro, projeto.getValor())) {
        throw runtime_error("Ja existe quadro com este identificador.");
    }
}

Quadro CntrServicoQuadro::ler(const Identificador& identificador) {
    Quadro quadro;
    quadro.setIdentificador(identificador);
    if (!ContainerQuadro::getInstancia()->pesquisar(&quadro)) {
        throw runtime_error("Quadro nao encontrado.");
    }
    return quadro;
}

void CntrServicoQuadro::atualizar(const Quadro& quadro, const EMAIL& usuario) {
    string id = quadro.getIdentificador().getValor();
    ler(quadro.getIdentificador());
    verificarGestor(ContainerQuadro::getInstancia()->getProjeto(id), usuario);
    int wip = 0;
    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar(id);
    for (int i = 0; i < cartoes.size(); i++) {
        if (cartoes[i].getEstado().getValor() == "FAZENDO") {
            wip = wip + 1;
        }
    }
    if (quadro.getLimite().getValor() < wip) {
        throw runtime_error("Limite menor que o numero de cartoes em FAZENDO.");
    }
    ContainerQuadro::getInstancia()->atualizar(quadro);
}

void CntrServicoQuadro::excluir(const Identificador& identificador, const EMAIL& usuario) {
    string id = identificador.getValor();
    ler(identificador);
    verificarGestor(ContainerQuadro::getInstancia()->getProjeto(id), usuario);
    if (ContainerCartao::getInstancia()->listar(id).size() > 0) {
        throw runtime_error("Quadro possui cartoes e nao pode ser excluido.");
    }
    ContainerQuadro::getInstancia()->remover(id);
}

vector<Identificador> CntrServicoQuadro::listar(const Identificador& projeto) {
    Projeto auxiliar;
    auxiliar.setIdentificador(projeto);
    if (!ContainerProjeto::getInstancia()->pesquisar(&auxiliar)) {
        throw runtime_error("Projeto nao encontrado.");
    }
    vector<Identificador> identificadores;
    vector<Quadro> quadros = ContainerQuadro::getInstancia()->listar(projeto.getValor());
    for (int i = 0; i < quadros.size(); i++) {
        identificadores.push_back(quadros[i].getIdentificador());
    }
    return identificadores;
}

void CntrServicoCartao::verificarGestor(const string& quadro, const EMAIL& usuario) {
    string projeto = ContainerQuadro::getInstancia()->getProjeto(quadro);
    if (ContainerProjeto::getInstancia()->getGestor(projeto) != usuario.getValor()) {
        throw runtime_error("Apenas o gestor do projeto pode realizar esta operacao.");
    }
}

int CntrServicoCartao::converterMinutos(const Timestamp& timestamp) {
    string valor = timestamp.getValor();
    string partes[4];
    int parte = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (valor[i] == '-') {
            parte = parte + 1;
        } else {
            partes[parte] = partes[parte] + valor[i];
        }
    }
    string meses[12] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dia = stoi(partes[0]);
    int ano = stoi(partes[2]);
    int horas = stoi(partes[3].substr(0, 2));
    int minutos = stoi(partes[3].substr(3, 2));
    if (ano % 4 == 0) {
        diasMes[1] = 29;
    }
    int dias = 0;
    for (int i = 2000; i < ano; i++) {
        if (i % 4 == 0) {
            dias = dias + 366;
        } else {
            dias = dias + 365;
        }
    }
    for (int i = 0; i < 12 && meses[i] != partes[1]; i++) {
        dias = dias + diasMes[i];
    }
    dias = dias + dia - 1;
    return dias * 24 * 60 + horas * 60 + minutos;
}

int CntrServicoCartao::contarFazendo(const string& quadro) {
    int total = 0;
    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar(quadro);
    for (int i = 0; i < cartoes.size(); i++) {
        if (cartoes[i].getEstado().getValor() == "FAZENDO") {
            total = total + 1;
        }
    }
    return total;
}

void CntrServicoCartao::criar(const CartaoAtividade& cartao, const Identificador& quadro, const EMAIL& usuario) {
    Quadro auxiliar;
    auxiliar.setIdentificador(quadro);
    if (!ContainerQuadro::getInstancia()->pesquisar(&auxiliar)) {
        throw runtime_error("Quadro nao encontrado.");
    }
    verificarGestor(quadro.getValor(), usuario);
    CartaoAtividade novo = cartao;
    Estado estado;
    estado.setValor("A FAZER");
    novo.setEstado(estado);
    novo.setInicio(Timestamp());
    novo.setTermino(Timestamp());
    if (!ContainerCartao::getInstancia()->incluir(novo, quadro.getValor())) {
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

void CntrServicoCartao::atualizar(const CartaoAtividade& cartao, const EMAIL& usuario) {
    CartaoAtividade atual = ler(cartao.getIdentificador());
    verificarGestor(ContainerCartao::getInstancia()->getQuadro(cartao.getIdentificador().getValor()), usuario);
    atual.setNome(cartao.getNome());
    atual.setDescricao(cartao.getDescricao());
    atual.setPrioridade(cartao.getPrioridade());
    atual.setTamanho(cartao.getTamanho());
    ContainerCartao::getInstancia()->atualizar(atual);
}

void CntrServicoCartao::excluir(const Identificador& identificador, const EMAIL& usuario) {
    ler(identificador);
    verificarGestor(ContainerCartao::getInstancia()->getQuadro(identificador.getValor()), usuario);
    ContainerCartao::getInstancia()->remover(identificador.getValor());
}

vector<Identificador> CntrServicoCartao::listar(const Identificador& quadro) {
    Quadro auxiliar;
    auxiliar.setIdentificador(quadro);
    if (!ContainerQuadro::getInstancia()->pesquisar(&auxiliar)) {
        throw runtime_error("Quadro nao encontrado.");
    }
    vector<Identificador> identificadores;
    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar(quadro.getValor());
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
        Identificador idQuadro;
        idQuadro.setValor(ContainerCartao::getInstancia()->getQuadro(identificador.getValor()));
        quadro.setIdentificador(idQuadro);
        ContainerQuadro::getInstancia()->pesquisar(&quadro);
        if (contarFazendo(idQuadro.getValor()) >= quadro.getLimite().getValor()) {
            throw runtime_error("Limite WIP do quadro atingido.");
        }
        if (converterMinutos(momento) < converterMinutos(cartao.getEntrada())) {
            throw runtime_error("Momento anterior a entrada do cartao.");
        }
        novoEstado.setValor("FAZENDO");
        cartao.setInicio(momento);
    } else if (estado == "FAZENDO") {
        if (converterMinutos(momento) < converterMinutos(cartao.getInicio())) {
            throw runtime_error("Momento anterior ao inicio do cartao.");
        }
        novoEstado.setValor("FEITO");
        cartao.setTermino(momento);
    } else {
        throw runtime_error("Cartao ja esta na coluna FEITO.");
    }
    cartao.setEstado(novoEstado);
    ContainerCartao::getInstancia()->atualizar(cartao);
}

int CntrServicoCartao::lerTempoCiclo(const Identificador& identificador) {
    CartaoAtividade cartao = ler(identificador);
    if (cartao.getEstado().getValor() != "FEITO") {
        throw runtime_error("Cartao ainda nao foi concluido.");
    }
    return converterMinutos(cartao.getTermino()) - converterMinutos(cartao.getInicio());
}

double CntrServicoCartao::lerTempoCicloMedio(const Identificador& quadro) {
    listar(quadro);
    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar(quadro.getValor());
    int soma = 0;
    int total = 0;
    for (int i = 0; i < cartoes.size(); i++) {
        if (cartoes[i].getEstado().getValor() == "FEITO") {
            soma = soma + converterMinutos(cartoes[i].getTermino()) - converterMinutos(cartoes[i].getInicio());
            total = total + 1;
        }
    }
    if (total == 0) {
        throw runtime_error("Nao ha cartoes concluidos no quadro.");
    }
    return (double) soma / total;
}

int CntrServicoCartao::lerLeadTime(const Identificador& identificador) {
    CartaoAtividade cartao = ler(identificador);
    if (cartao.getEstado().getValor() != "FEITO") {
        throw runtime_error("Cartao ainda nao foi concluido.");
    }
    return converterMinutos(cartao.getTermino()) - converterMinutos(cartao.getEntrada());
}

double CntrServicoCartao::lerLeadTimeMedio(const Identificador& quadro) {
    listar(quadro);
    vector<CartaoAtividade> cartoes = ContainerCartao::getInstancia()->listar(quadro.getValor());
    int soma = 0;
    int total = 0;
    for (int i = 0; i < cartoes.size(); i++) {
        if (cartoes[i].getEstado().getValor() == "FEITO") {
            soma = soma + converterMinutos(cartoes[i].getTermino()) - converterMinutos(cartoes[i].getEntrada());
            total = total + 1;
        }
    }
    if (total == 0) {
        throw runtime_error("Nao ha cartoes concluidos no quadro.");
    }
    return (double) soma / total;
}

int CntrServicoCartao::lerWIP(const Identificador& quadro) {
    listar(quadro);
    return contarFazendo(quadro.getValor());
}
