#include "Pessoa.h"

Pessoa::Pessoa(int id, const std::string& nome, const std::string& endereco, const std::string& telefone)
    : id(id), nome(nome), endereco(endereco), telefone(telefone) {}

int Pessoa::getId() const {
    return id;
}

std::string Pessoa::getNome() const {
    return nome;
}

std::string Pessoa::getEndereco() const {
    return endereco;
}

std::string Pessoa::getTelefone() const {
    return telefone;
}

void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

void Pessoa::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

void Pessoa::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}


