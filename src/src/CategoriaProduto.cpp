#include "CategoriaProduto.h"

CategoriaProduto::CategoriaProduto(int id, const std::string& nome) : id(id), nome(nome) {}

int CategoriaProduto::getId() const {
    return id;
}

std::string CategoriaProduto::getNome() const {
    return nome;
}

void CategoriaProduto::setNome(const std::string& nome) {
    this->nome = nome;
}


