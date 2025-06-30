#include "LocalizacaoEstoque.h"

LocalizacaoEstoque::LocalizacaoEstoque(int id, const std::string& corredor, const std::string& prateleira)
    : id(id), corredor(corredor), prateleira(prateleira) {}

int LocalizacaoEstoque::getId() const {
    return id;
}

std::string LocalizacaoEstoque::getCorredor() const {
    return corredor;
}

std::string LocalizacaoEstoque::getPrateleira() const {
    return prateleira;
}

void LocalizacaoEstoque::setCorredor(const std::string& corredor) {
    this->corredor = corredor;
}

void LocalizacaoEstoque::setPrateleira(const std::string& prateleira) {
    this->prateleira = prateleira;
}


