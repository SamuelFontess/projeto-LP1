#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
protected:
    int id;
    std::string nome;
    std::string endereco;
    std::string telefone;

public:
    Pessoa(int id, const std::string& nome, const std::string& endereco, const std::string& telefone);
    virtual ~Pessoa() = default; // Virtual destructor for polymorphism

    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getEndereco() const;
    std::string getTelefone() const;

    // Setters
    void setNome(const std::string& nome);
    void setEndereco(const std::string& endereco);
    void setTelefone(const std::string& telefone);
    void setId(int id) { this->id = id; }
};

#endif // PESSOA_H


