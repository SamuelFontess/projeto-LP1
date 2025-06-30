#include "Transacao.h"

Transacao::Transacao(int id, const std::string& data, double valorTotal)
    : id(id), data(data), valorTotal(valorTotal) {}

int Transacao::getId() const {
    return id;
}

std::string Transacao::getData() const {
    return data;
}

double Transacao::getValorTotal() const {
    return valorTotal;
}

void Transacao::setData(const std::string& data) {
    this->data = data;
}

void Transacao::setValorTotal(double valorTotal) {
    this->valorTotal = valorTotal;
}

