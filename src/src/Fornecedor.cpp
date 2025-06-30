#include "Fornecedor.h"

Fornecedor::Fornecedor(int id, const std::string& nome, const std::string& contato) : id(id), nome(nome), contato(contato) {}

int Fornecedor::getId() const {
    return id;
}

std::string Fornecedor::getNome() const {
    return nome;
}

std::string Fornecedor::getContato() const {
    return contato;
}

void Fornecedor::setNome(const std::string& nome) {
    this->nome = nome;
}

void Fornecedor::setContato(const std::string& contato) {
    this->contato = contato;
}


