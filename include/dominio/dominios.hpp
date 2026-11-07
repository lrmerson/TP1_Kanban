#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Endereço de e-mail validado pela parte local e pelo domínio.
 *
 * A parte local admite letras minúsculas, dígitos, ponto e hífen, respeitando
 * os limites de tamanho e de posição definidos pela especificação.
 */
class EMAIL {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define o endereço após validar seu formato.
         *  @param valor Endereço a armazenar.
         *  @throws invalid_argument Se o endereço não atender ao formato.
         */
        void setValor(string valor);
        /** @brief Retorna o endereço armazenado.
         *  @return Endereço validado.
         */
        string getValor() const;
};

/** @brief Estado permitido para uma atividade no quadro Kanban. */
class Estado {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define o estado como A FAZER, FAZENDO ou FEITO.
         *  @param valor Estado a armazenar.
         *  @throws invalid_argument Se o estado não for permitido.
         */
        void setValor(string valor);
        /** @brief Retorna o estado armazenado.
         *  @return Estado do fluxo Kanban.
         */
        string getValor() const;
};

/** @brief Identificador composto por três letras e três dígitos. */
class Identificador {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define o identificador após validar seu formato.
         *  @param valor Identificador a armazenar.
         *  @throws invalid_argument Se o valor não tiver seis caracteres no formato esperado.
         */
        void setValor(string valor);
        /** @brief Retorna o identificador armazenado.
         *  @return Identificador validado.
         */
        string getValor() const;
};

/** @brief Limite máximo de atividades simultâneas na coluna FAZENDO. */
class Limite {
    private:
        int valor;
        void validar(const int&) const;

    public:
        /** @brief Define o limite entre 1 e 25.
         *  @param valor Limite a armazenar.
         *  @throws invalid_argument Se o valor estiver fora do intervalo permitido.
         */
        void setValor(int valor);
        /** @brief Retorna o limite armazenado.
         *  @return Quantidade máxima de cartões em andamento.
         */
        int getValor() const;
};

/** @brief Nome de pessoa, projeto, quadro ou atividade. */
class Nome {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define um nome de até 15 letras e espaços válidos.
         *  @param valor Nome a armazenar.
         *  @throws invalid_argument Se o nome não atender ao formato.
         */
        void setValor(string valor);
        /** @brief Retorna o nome armazenado.
         *  @return Nome validado.
         */
        string getValor() const;
};

/** @brief Papel de uma pessoa no sistema Kanban. */
class Papel {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define o papel como GESTOR ou DESENVOLVEDOR.
         *  @param valor Papel a armazenar.
         *  @throws invalid_argument Se o papel não for permitido.
         */
        void setValor(string valor);
        /** @brief Retorna o papel armazenado.
         *  @return Papel da pessoa.
         */
        string getValor() const;
};

/** @brief Prioridade de uma atividade. */
class Prioridade {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define a prioridade como ALTA, MEDIA ou BAIXA.
         *  @param valor Prioridade a armazenar.
         *  @throws invalid_argument Se a prioridade não for permitida.
         */
        void setValor(string valor);
        /** @brief Retorna a prioridade armazenada.
         *  @return Prioridade da atividade.
         */
        string getValor() const;
};

/** @brief Senha de cinco caracteres alfanuméricos. */
class Senha {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define uma senha com ao menos uma letra e um dígito.
         *  @param valor Senha a armazenar.
         *  @throws invalid_argument Se a senha não atender ao formato.
         */
        void setValor(string valor);
        /** @brief Retorna a senha armazenada.
         *  @return Senha validada.
         */
        string getValor() const;
};

/** @brief Classificação de tamanho de uma atividade. */
class Tamanho {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define o tamanho como GRANDE, MEDIO ou PEQUENO.
         *  @param valor Tamanho a armazenar.
         *  @throws invalid_argument Se o tamanho não for permitido.
         */
        void setValor(string valor);
        /** @brief Retorna o tamanho armazenado.
         *  @return Classificação da atividade.
         */
        string getValor() const;
};

/** @brief Descrição textual de um projeto ou de uma atividade. */
class Texto {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define um texto de até 30 caracteres no formato especificado.
         *  @param valor Texto a armazenar.
         *  @throws invalid_argument Se o texto não atender ao formato.
         */
        void setValor(string valor);
        /** @brief Retorna o texto armazenado.
         *  @return Texto validado.
         */
        string getValor() const;
};

/** @brief Data e horário no formato DIA-MES-ANO-HH:MM. */
class Timestamp {
    private:
        string valor;
        void validar(const string&) const;

    public:
        /** @brief Define uma data e horário válidos entre 2000 e 2099.
         *  @param valor Data e horário a armazenar.
         *  @throws invalid_argument Se o formato ou a data não forem válidos.
         */
        void setValor(string valor);
        /** @brief Retorna a data e horário armazenados.
         *  @return Data e horário validados.
         */
        string getValor() const;
};

#endif // DOMINIOS_HPP_INCLUDED
