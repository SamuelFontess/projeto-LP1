#ifndef ITEMPEDIDO_H
#define ITEMPEDIDO_H

#include "Produto.h"

class ItemPedido {
private:
    Produto produto;
    int quantidade;

public:
    ItemPedido(const Produto& produto, int quantidade);

    // Getters
    Produto getProduto() const;
    int getQuantidade() const;

    // Setters
    void setQuantidade(int quantidade);
};

#endif // ITEMPEDIDO_H


