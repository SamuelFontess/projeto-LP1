#include "ItemPedido.h"

ItemPedido::ItemPedido(const Produto& produto, int quantidade)
    : produto(produto), quantidade(quantidade) {}

Produto ItemPedido::getProduto() const {
    return produto;
}

int ItemPedido::getQuantidade() const {
    return quantidade;
}

void ItemPedido::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}


