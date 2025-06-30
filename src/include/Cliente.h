#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include <string>

class Cliente : public Pessoa {
private:
    std::string email;

public:
    Cliente(int id, const std::string& nome, const std::string& endereco, const std::string& telefone, const std::string& email);

    // Getters
    std::string getEmail() const;

    // Setters
    void setEmail(const std::string& email);
};

#endif // CLIENTE_H


