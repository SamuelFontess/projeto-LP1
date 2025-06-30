#ifndef PEDIDOCOMPRA_H
#define PEDIDOCOMPRA_H

#include "Transacao.h"
#include "ItemPedido.h"
#include "Fornecedor.h"
#include <vector>
#include <iostream>
#include <string>

class PedidoCompra : public Transacao {
private:
    Fornecedor fornecedor;
    std::vector<ItemPedido> itens;

public:
    PedidoCompra(int id, const std::string& data, double valorTotal, const Fornecedor& fornecedor);

    // Getters
    Fornecedor getFornecedor() const;
    std::vector<ItemPedido> getItens() const;

    // Setters
    void setFornecedor(const Fornecedor& fornecedor);
    void adicionarItem(const ItemPedido& item);

    void mostrarResumo() const override; // Polymorphism
    std::string getNome() const { return "Pedido de Compra ID: " + std::to_string(getId()); } // Adicionado para listarItens
};

#endif // PEDIDOCOMPRA_H


