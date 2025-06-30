#include "PedidoCompra.h"

PedidoCompra::PedidoCompra(int id, const std::string& data, double valorTotal, const Fornecedor& fornecedor)
    : Transacao(id, data, valorTotal), fornecedor(fornecedor) {}

Fornecedor PedidoCompra::getFornecedor() const {
    return fornecedor;
}

std::vector<ItemPedido> PedidoCompra::getItens() const {
    return itens;
}

void PedidoCompra::setFornecedor(const Fornecedor& fornecedor) {
    this->fornecedor = fornecedor;
}

void PedidoCompra::adicionarItem(const ItemPedido& item) {
    itens.push_back(item);
}

void PedidoCompra::mostrarResumo() const {
    std::cout << "\n--- Resumo do Pedido de Compra ---" << std::endl;
    std::cout << "ID do Pedido: " << getId() << std::endl;
    std::cout << "Data: " << getData() << std::endl;
    std::cout << "Fornecedor: " << fornecedor.getNome() << std::endl;
    std::cout << "Valor Total: R$" << getValorTotal() << std::endl;
    std::cout << "Itens do Pedido:" << std::endl;
    for (const auto& item : itens) {
        std::cout << "  - " << item.getProduto().getNome() << " (Quantidade: " << item.getQuantidade() << ")" << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
}


