# TP1 Kanban

Projeto final da disciplina Técnicas de Programação 1.

## Estrutura

```text
include/
  dominio/       Classes de domínio e validações
  entidades/     Entidades do sistema
  interfaces/    Interfaces (classes abstratas) entre os módulos
  apresentacao/  Controladoras da camada de apresentação (cin/cout)
  servico/       Controladoras e contêineres da camada de serviço
  testes/        Testes de unidade
src/
  dominio/
  entidades/
  apresentacao/
  servico/
  testes/
  main.cpp       Montagem do sistema (injeção de dependências)
smoke_test.txt   Entradas do teste fumaça (um caso por funcionalidade)
```

Pelo terminal, a aplicação pode ser compilada com:

```sh
g++ -std=c++17 -Iinclude src/main.cpp src/dominio/*.cpp src/entidades/*.cpp src/servico/*.cpp src/apresentacao/*.cpp -o kanban
./kanban < smoke_test.txt
```

## Compilar

### Code::Blocks

Abra `TP1_Kanban.cbp` no Code::Blocks. O projeto inclui os arquivos-fonte
atuais, configura `include/` para localizar os cabeçalhos e seleciona C++17.
Escolha o alvo `Debug` ou `Release` e use **Build and run** (F9). O executável
e os arquivos intermediários são criados nas pastas `bin/` e `obj/`.

O projeto usa o compilador GCC/MinGW. Caso o Code::Blocks não encontre o
compilador, configure a instalação do MinGW em **Settings > Compiler**.

O projeto exige um compilador com suporte a C++17.

Nos menus, digite `0` e pressione Enter para voltar. Ao preencher os campos
de uma operação, digite `0` ou pressione Enter em branco para cancelá-la e
voltar ao menu. Um dado inválido pode ser digitado novamente no mesmo campo.

## Testes de unidade

Os testes ficam em `include/testes/` e `src/testes/`, com um executável
próprio (`src/testes/main_testes.cpp`) separado do `main.cpp` da aplicação.
Cada classe `TU<Dominio>` verifica o cenário de sucesso (valores válidos são
aceitos) e o de falha (valores inválidos lançam `invalid_argument` sem alterar
o valor armazenado).

No Code::Blocks, selecione o alvo `Testes` e use **Build and run** (F9).
Pelo terminal:

```sh
g++ -std=c++17 -Iinclude src/dominio/*.cpp src/entidades/*.cpp src/testes/*.cpp -o testes
./testes
```

Cada teste imprime `SUCESSO` ou `FALHA`; o programa retorna 0 somente se
todos passarem.

## Documentação com Doxygen

O arquivo [Doxyfile](Doxyfile) configura a geração da documentação a partir
dos comentários das classes e métodos. Instale o Doxygen e execute na raiz do
projeto:

```sh
doxygen Doxyfile
```

Os arquivos HTML serão gerados em `build/doxygen/html/`; abra
`build/doxygen/html/index.html` no navegador.
