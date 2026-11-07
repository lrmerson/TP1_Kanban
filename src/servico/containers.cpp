#include "servico/containers.hpp"

ContainerPessoa *ContainerPessoa::instancia = nullptr;

ContainerPessoa* ContainerPessoa::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerPessoa();
    }
    return instancia;
}

bool ContainerPessoa::incluir(const Pessoa& pessoa) {
    string chave = pessoa.getEmail().getValor();
    if (container.count(chave) > 0) {
        return false;
    }
    container[chave] = pessoa;
    return true;
}

bool ContainerPessoa::remover(const string& chave) {
    if (container.count(chave) == 0) {
        return false;
    }
    container.erase(chave);
    return true;
}

bool ContainerPessoa::pesquisar(Pessoa* pessoa) {
    string chave = pessoa->getEmail().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    *pessoa = container[chave];
    return true;
}

bool ContainerPessoa::atualizar(const Pessoa& pessoa) {
    string chave = pessoa.getEmail().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    container[chave] = pessoa;
    return true;
}

vector<Pessoa> ContainerPessoa::listar() {
    vector<Pessoa> lista;
    for (auto item : container) {
        lista.push_back(item.second);
    }
    return lista;
}

ContainerProjeto *ContainerProjeto::instancia = nullptr;

ContainerProjeto* ContainerProjeto::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerProjeto();
    }
    return instancia;
}

bool ContainerProjeto::incluir(const Projeto& projeto, const string& gestor) {
    string chave = projeto.getIdentificador().getValor();
    if (container.count(chave) > 0) {
        return false;
    }
    container[chave] = projeto;
    gestores[chave] = gestor;
    return true;
}

bool ContainerProjeto::remover(const string& chave) {
    if (container.count(chave) == 0) {
        return false;
    }
    container.erase(chave);
    gestores.erase(chave);
    return true;
}

bool ContainerProjeto::pesquisar(Projeto* projeto) {
    string chave = projeto->getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    *projeto = container[chave];
    return true;
}

bool ContainerProjeto::atualizar(const Projeto& projeto) {
    string chave = projeto.getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    container[chave] = projeto;
    return true;
}

string ContainerProjeto::getGestor(const string& chave) {
    if (gestores.count(chave) == 0) {
        return "";
    }
    return gestores[chave];
}

vector<Projeto> ContainerProjeto::listar() {
    vector<Projeto> lista;
    for (auto item : container) {
        lista.push_back(item.second);
    }
    return lista;
}

ContainerQuadro *ContainerQuadro::instancia = nullptr;

ContainerQuadro* ContainerQuadro::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerQuadro();
    }
    return instancia;
}

bool ContainerQuadro::incluir(const Quadro& quadro, const string& projeto) {
    string chave = quadro.getIdentificador().getValor();
    if (container.count(chave) > 0) {
        return false;
    }
    container[chave] = quadro;
    projetos[chave] = projeto;
    return true;
}

bool ContainerQuadro::remover(const string& chave) {
    if (container.count(chave) == 0) {
        return false;
    }
    container.erase(chave);
    projetos.erase(chave);
    return true;
}

bool ContainerQuadro::pesquisar(Quadro* quadro) {
    string chave = quadro->getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    *quadro = container[chave];
    return true;
}

bool ContainerQuadro::atualizar(const Quadro& quadro) {
    string chave = quadro.getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    container[chave] = quadro;
    return true;
}

string ContainerQuadro::getProjeto(const string& chave) {
    if (projetos.count(chave) == 0) {
        return "";
    }
    return projetos[chave];
}

vector<Quadro> ContainerQuadro::listar(const string& projeto) {
    vector<Quadro> lista;
    for (auto item : container) {
        if (projetos[item.first] == projeto) {
            lista.push_back(item.second);
        }
    }
    return lista;
}

ContainerCartao *ContainerCartao::instancia = nullptr;

ContainerCartao* ContainerCartao::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ContainerCartao();
    }
    return instancia;
}

bool ContainerCartao::incluir(const CartaoAtividade& cartao, const string& quadro) {
    string chave = cartao.getIdentificador().getValor();
    if (container.count(chave) > 0) {
        return false;
    }
    container[chave] = cartao;
    quadros[chave] = quadro;
    return true;
}

bool ContainerCartao::remover(const string& chave) {
    if (container.count(chave) == 0) {
        return false;
    }
    container.erase(chave);
    quadros.erase(chave);
    return true;
}

bool ContainerCartao::pesquisar(CartaoAtividade* cartao) {
    string chave = cartao->getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    *cartao = container[chave];
    return true;
}

bool ContainerCartao::atualizar(const CartaoAtividade& cartao) {
    string chave = cartao.getIdentificador().getValor();
    if (container.count(chave) == 0) {
        return false;
    }
    container[chave] = cartao;
    return true;
}

string ContainerCartao::getQuadro(const string& chave) {
    if (quadros.count(chave) == 0) {
        return "";
    }
    return quadros[chave];
}

vector<CartaoAtividade> ContainerCartao::listar(const string& quadro) {
    vector<CartaoAtividade> lista;
    for (auto item : container) {
        if (quadros[item.first] == quadro) {
            lista.push_back(item.second);
        }
    }
    return lista;
}
