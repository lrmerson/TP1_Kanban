# TP1 Kanban

Sistema de apoio à gestão de projetos que utilizam o método Kanban,
desenvolvido para a disciplina Técnicas de Programação 1. O sistema é escrito
em C++17 e possui interface de terminal com `cin` e `cout`.

## Arquitetura

O projeto adota arquitetura em camadas:

```text
Camada de apresentação
  Inicialização | Autenticação | Pessoas | Projetos | Kanban
                         │
             interfaces de apresentação/serviço
                         │
Camada de serviço
  Autenticação | Pessoas | Projetos | Kanban
                         │
      contêineres e entidades mantidos em memória
```

A camada de apresentação interage com o usuário e valida os dados de entrada.
A camada de serviço executa as regras de negócio, verifica autorizações e
mantém os dados. Os módulos se comunicam por interfaces declaradas como
classes abstratas com métodos virtuais puros.

### Módulos

| Módulo | Responsabilidade |
| --- | --- |
| Apresentação de inicialização e controle | Inicia o sistema, cria contas, autentica usuários e controla a sessão. |
| Apresentação de autenticação | Recebe credenciais e solicita sua verificação. |
| Serviço de autenticação | Confere e-mail e senha de uma pessoa cadastrada. |
| Apresentação de pessoas | Oferece criação, leitura, atualização, exclusão e listagem de pessoas. |
| Serviço de pessoas | Gerencia pessoas e preserva as relações com projetos e cartões. |
| Apresentação de projetos | Oferece criação, leitura, atualização, exclusão e listagem de projetos. |
| Serviço de projetos | Gerencia projetos e verifica o gestor responsável. |
| Apresentação de Kanban | Reúne os menus de quadros, cartões e métricas. |
| Serviço de Kanban | Gerencia quadros, cartões, movimentações e métricas Kanban. |

O módulo de serviço Kanban é uma fachada que delega operações às
controladoras de quadros, cartões e métricas. Os contêineres
`ContainerPessoa`, `ContainerProjeto`, `ContainerQuadro` e `ContainerCartao`
armazenam os objetos em memória.

## Funcionalidades

O acesso aos serviços, exceto a criação de conta, exige autenticação. Os
papéis disponíveis são `GESTOR` e `DESENVOLVEDOR`.

- **Pessoas:** criar, ler, atualizar, excluir e listar.
- **Projetos:** criar, ler, atualizar, excluir e listar.
- **Quadros:** criar, ler, atualizar, excluir e listar.
- **Cartões de atividade:** criar, ler, atualizar, excluir, listar e mover.
- **Métricas:** tempo de ciclo, tempo de ciclo médio, lead time, lead time
  médio e WIP.

Cada quadro possui as colunas `A FAZER`, `FAZENDO` e `FEITO`. A movimentação
permitida é `A FAZER -> FAZENDO -> FEITO`. O tempo de ciclo mede o intervalo
entre `FAZENDO` e `FEITO`; o lead time mede o intervalo entre `A FAZER` e
`FEITO`; WIP é a quantidade de cartões em `FAZENDO`.

As chaves das entidades não podem ser alteradas. A exclusão de uma pessoa,
projeto ou quadro é recusada quando causaria inconsistência com entidades
relacionadas. O limite WIP restringe a quantidade de cartões simultaneamente
em `FAZENDO`.

## Estrutura

```text
include/
  dominio/       Classes de domínio e validações
  entidades/     Classes Pessoa, Projeto, Quadro e CartaoAtividade
  interfaces/    Interfaces abstratas entre os módulos
  apresentacao/  Controladoras e utilitários de interação com o usuário
  servico/       Controladoras e contêineres da camada de serviço
src/
  dominio/
  entidades/
  apresentacao/
  servico/
  main.cpp       Montagem do sistema e injeção de dependências
smoke_test.txt   Entradas do teste fumaça
```

As classes de domínio (`EMAIL`, `Senha`, `Nome`, `Texto`, `Identificador`,
`Estado`, `Limite`, `Papel`, `Prioridade`, `Tamanho` e `Timestamp`) encapsulam
valores e rejeitam formatos inválidos por meio de exceções. As entidades usam
esses tipos em seus atributos, em vez de expor diretamente tipos primitivos.

## Compilação

### Code::Blocks

Abra `TP1_Kanban.cbp` no Code::Blocks, selecione o alvo `Debug` ou `Release` e
use **Build and run** (F9). O projeto configura `include/` e exige um
compilador GCC/MinGW com suporte a C++17. Os arquivos intermediários e o
executável são gerados em `obj/` e `bin/`.

### Linha de comando

Em um ambiente com `g++`, execute na raiz do projeto:

```sh
g++ -std=c++17 -Iinclude \
  $(find src -name '*.cpp') \
  -o kanban
```

No Windows, a forma recomendada de compilação é abrir o projeto no
Code::Blocks. O comando acima requer um ambiente que disponibilize `find` e
suporte à continuação de linhas com `\`.

## Uso

Nos menus, digite `0` e pressione Enter para voltar. Durante o preenchimento
de uma operação, digite `0` ou pressione Enter em branco para cancelá-la.
Quando um valor for inválido, o sistema informa o formato esperado e permite
uma nova tentativa.

Os dados são mantidos somente em memória e são perdidos ao encerrar o
programa.

## Teste fumaça

O arquivo `smoke_test.txt` contém entradas para um cenário de sucesso de cada
funcionalidade integrada do sistema. Ele deve ser utilizado durante a
execução do programa para demonstrar o funcionamento das operações previstas.

## Documentação com Doxygen

O arquivo [Doxyfile](Doxyfile) configura a documentação HTML dos cabeçalhos,
implementações e classes documentadas do projeto. Na raiz do projeto, execute:

```sh
doxygen Doxyfile
```

Os arquivos HTML serão gerados em `doxygen/html/`. Abra
`doxygen/html/index.html` no navegador.
