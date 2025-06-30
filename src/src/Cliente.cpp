#include "Cliente.h"

Cliente::Cliente(int id, const std::string& nome, const std::string& endereco, const std::string& telefone, const std::string& email)
    : Pessoa(id, nome, endereco, telefone), email(email) {}

std::string Cliente::getEmail() const {
    return email;
}

void Cliente::setEmail(const std::string& email) {
    this->email = email;
}


