# TP1 Kanban

Projeto final da disciplina Técnicas de Programação 1.

## Estrutura

```text
include/
  dominio/       Classes de domínio e validações
  entidades/     Entidades do sistema
  controladoras/ Regras de aplicação e coordenação dos casos de uso
  apresentacao/  Interface com o usuário
src/
  dominio/
  entidades/
  controladoras/
  apresentacao/
  main.cpp
```

Os arquivos de entidade, controladoras e apresentação são esqueletos iniciais:
seus atributos e operações devem ser implementados conforme os requisitos
funcionais do enunciado.

## Compilar

### Code::Blocks

Abra `TP1_Kanban.cbp` no Code::Blocks. O projeto inclui os arquivos-fonte
atuais, configura `include/` para localizar os cabeçalhos e seleciona C++17.
Escolha o alvo `Debug` ou `Release` e use **Build and run** (F9). O executável
e os arquivos intermediários são criados nas pastas `bin/` e `obj/`.

O projeto usa o compilador GCC/MinGW. Caso o Code::Blocks não encontre o
compilador, configure a instalação do MinGW em **Settings > Compiler**.

O projeto exige um compilador com suporte a C++17.

## Documentação com Doxygen

O arquivo [Doxyfile](Doxyfile) configura a geração da documentação a partir
dos comentários das classes e métodos. Instale o Doxygen e execute na raiz do
projeto:

```sh
doxygen Doxyfile
```

Os arquivos HTML serão gerados em `build/doxygen/html/`; abra
`build/doxygen/html/index.html` no navegador.
