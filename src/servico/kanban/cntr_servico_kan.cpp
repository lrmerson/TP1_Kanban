#include "servico/kanban/cntr_servico_kan.hpp"

void CntrServicoKanban::criarQuadro(const Quadro& quadro, const Identificador& projeto, const EMAIL& gestor) {
    cntrQuadro.criar(quadro, projeto, gestor);
}

Quadro CntrServicoKanban::lerQuadro(const Identificador& identificador) {
    return cntrQuadro.ler(identificador);
}

void CntrServicoKanban::atualizarQuadro(const Quadro& quadro, const EMAIL& gestor) {
    cntrQuadro.atualizar(quadro, gestor);
}

void CntrServicoKanban::excluirQuadro(const Identificador& identificador, const EMAIL& gestor) {
    cntrQuadro.excluir(identificador, gestor);
}

vector<Identificador> CntrServicoKanban::listarQuadros(const Identificador& projeto) {
    return cntrQuadro.listar(projeto);
}

void CntrServicoKanban::criarCartao(const CartaoAtividade& cartao, const Identificador& quadro, const EMAIL& gestor) {
    cntrCartao.criar(cartao, quadro, gestor);
}

CartaoAtividade CntrServicoKanban::lerCartao(const Identificador& identificador) {
    return cntrCartao.ler(identificador);
}

void CntrServicoKanban::atualizarCartao(const CartaoAtividade& cartao, const EMAIL& gestor) {
    cntrCartao.atualizar(cartao, gestor);
}

void CntrServicoKanban::excluirCartao(const Identificador& identificador, const EMAIL& gestor) {
    cntrCartao.excluir(identificador, gestor);
}

vector<Identificador> CntrServicoKanban::listarCartoes(const Identificador& quadro) {
    return cntrCartao.listar(quadro);
}

void CntrServicoKanban::moverCartao(const Identificador& identificador, const Timestamp& momento) {
    cntrCartao.mover(identificador, momento);
}

int CntrServicoKanban::lerTempoCiclo(const Identificador& identificador) {
    return cntrMetricas.lerTempoCiclo(identificador);
}

double CntrServicoKanban::lerTempoCicloMedio(const Identificador& quadro) {
    return cntrMetricas.lerTempoCicloMedio(quadro);
}

int CntrServicoKanban::lerLeadTime(const Identificador& identificador) {
    return cntrMetricas.lerLeadTime(identificador);
}

double CntrServicoKanban::lerLeadTimeMedio(const Identificador& quadro) {
    return cntrMetricas.lerLeadTimeMedio(quadro);
}

int CntrServicoKanban::lerWIP(const Identificador& quadro) {
    return cntrMetricas.lerWIP(quadro);
}
