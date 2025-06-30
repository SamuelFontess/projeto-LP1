#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <string>

class Fornecedor {
private:
    int id;
    std::string nome;
    std::string contato;

public:
    Fornecedor(int id, const std::string& nome, const std::string& contato);

    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getContato() const;

    // Setters
    void setNome(const std::string& nome);
    void setContato(const std::string& contato);
    void setId(int id) { this->id = id; }
};

#endif // FORNECEDOR_H


