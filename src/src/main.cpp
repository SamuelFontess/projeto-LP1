#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "Gerenciador.h"
#include "Produto.h"
#include "Fornecedor.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "PedidoCompra.h"
#include "CategoriaProduto.h"
#include "LocalizacaoEstoque.h"

// Função genérica para listar itens
template <typename T>
void listarItens(const std::vector<T>& itens) {
    if (itens.empty()) {
        std::cout << "Nenhum item para listar." << std::endl;
        return;
    }
    for (const auto& item : itens) {
        std::cout << "ID: " << item.getId() << ", Nome: " << item.getNome() << std::endl;
    }
}

int main() {
    // Gerenciadores para as entidades
    Gerenciador<Produto> gerenciadorProdutos;
    Gerenciador<Fornecedor> gerenciadorFornecedores;
    Gerenciador<Funcionario> gerenciadorFuncionarios;
    Gerenciador<Cliente> gerenciadorClientes;
    Gerenciador<PedidoCompra> gerenciadorPedidosCompra;

    // --- Testando CRUD para Fornecedor ---
    std::cout << "\n--- CRUD Fornecedor ---" << std::endl;
    Fornecedor f1(0, "Fornecedor A", "contatoA@gmail.com");
    Fornecedor f2(0, "Fornecedor B", "contatoB@gmail.com");

    gerenciadorFornecedores.adicionar(f1);
    gerenciadorFornecedores.adicionar(f2);
    std::cout << "Fornecedores adicionados." << std::endl;

    std::cout << "Listando Fornecedores:" << std::endl;
    listarItens(gerenciadorFornecedores.listarTodos());

    try {
        Fornecedor f_busca = gerenciadorFornecedores.buscar(1);
        std::cout << "Fornecedor encontrado (ID 1): " << f_busca.getNome()
              << ", Contato: " << f_busca.getContato() << std::endl;

        f_busca.setNome("Fornecedor A Atualizado");
        f_busca.setContato("novoemail@exemplo.com");
        gerenciadorFornecedores.atualizar(f_busca);
        std::cout << "Fornecedor atualizado (ID 1): "
              << f_busca.getNome() << ", Contato: "
              << f_busca.getContato() << std::endl;

        listarItens(gerenciadorFornecedores.listarTodos());

        gerenciadorFornecedores.remover(2);
        std::cout << "Fornecedor removido (ID 2)." << std::endl;
        listarItens(gerenciadorFornecedores.listarTodos());

        // Teste de exceção: buscar item inexistente
        gerenciadorFornecedores.buscar(99);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // --- Testando CRUD para CategoriaProduto (não é uma das 5 entidades principais, mas é dependência) ---
    std::cout << "\n--- CategoriaProduto (Dependência) ---" << std::endl;
    CategoriaProduto cat1(1, "Eletronicos");
    CategoriaProduto cat2(2, "Papelaria");

    // --- Testando CRUD para LocalizacaoEstoque (não é uma das 5 entidades principais, mas é dependência) ---
    std::cout << "\n--- LocalizacaoEstoque (Dependência) ---" << std::endl;
    LocalizacaoEstoque loc1(1, "A", "1");
    LocalizacaoEstoque loc2(2, "B", "2");

    // --- Testando CRUD para Produto ---
    std::cout << "\n--- CRUD Produto ---" << std::endl;
    Produto p1(0, "Mouse", 50.0, 100, cat1, f1, loc1);
    Produto p2(0, "Caneta", 2.5, 500, cat2, f2, loc2);

    gerenciadorProdutos.adicionar(p1);
    gerenciadorProdutos.adicionar(p2);
    std::cout << "Produtos adicionados." << std::endl;
    
    std::cout << "Listando Produtos:" << std::endl;
    for (const auto& p : gerenciadorProdutos.listarTodos()) {
        std::cout << "ID: " << p.getId() << ", Nome: " << p.getNome()
              << ", Preço: R$" << p.getPreco()
              << ", Quantidade: " << p.getQuantidade()
              << ", Categoria: " << p.getCategoria().getNome()
              << ", Fornecedor: " << p.getFornecedor().getNome()
              << ", Localização: Corredor " << p.getLocalizacao().getCorredor()
              << ", Prateleira " << p.getLocalizacao().getPrateleira()
              << std::endl;
    }

    try {
        Produto p_busca = gerenciadorProdutos.buscar(1);
        std::cout << "Produto encontrado (ID 1): " << p_busca.getNome()
              << ", Preço: R$" << p_busca.getPreco() << std::endl;

        p_busca.setPreco(55.0);
        gerenciadorProdutos.atualizar(p_busca);
        std::cout << "Produto atualizado (ID " << p_busca.getId() << "): "
              << p_busca.getNome() << ", Novo Preço: R$" << p_busca.getPreco() << std::endl;

        std::cout << "Listando Produtos após atualização:" << std::endl;
    for (const auto& p : gerenciadorProdutos.listarTodos()) {
        std::cout << "ID: " << p.getId() << ", Nome: " << p.getNome()
                  << ", Preço: R$" << p.getPreco() << std::endl;
    }

        gerenciadorProdutos.remover(2);
        std::cout << "Produto removido (ID 2)." << std::endl;
        
        std::cout << "Listando Produtos após remoção:" << std::endl;
    for (const auto& p : gerenciadorProdutos.listarTodos()) {
        std::cout << "ID: " << p.getId() << ", Nome: " << p.getNome() << std::endl;
    }

        gerenciadorProdutos.buscar(99);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // --- Testando CRUD para Funcionario ---
    std::cout << "\n--- CRUD Funcionario ---" << std::endl;
    Funcionario func1(0, "Joao Silva", "Rua A, 123", "91111-1111", "Gerente", 5000.0);
    Funcionario func2(0, "Maria Souza", "Rua B, 456", "92222-2222", "Vendedor", 2500.0);

    gerenciadorFuncionarios.adicionar(func1);
    gerenciadorFuncionarios.adicionar(func2);
    std::cout << "Funcionarios adicionados." << std::endl;
    
    std::cout << "Listando Funcionarios:" << std::endl;
    for (const auto& f : gerenciadorFuncionarios.listarTodos()) {
        std::cout << "ID: " << f.getId()
              << ", Nome: " << f.getNome()
              << ", Cargo: " << f.getCargo()
              << ", Salário: R$" << f.getSalario() << std::endl;
    }

    try {
        Funcionario func_busca = gerenciadorFuncionarios.buscar(1);
        std::cout << "Funcionario encontrado (ID 1): " << func_busca.getNome()
              << ", Cargo: " << func_busca.getCargo()
              << ", Salário: R$" << func_busca.getSalario() << std::endl;

        func_busca.setSalario(5500.0);
        gerenciadorFuncionarios.atualizar(func_busca);

        std::cout << "Funcionario atualizado (ID " << func_busca.getId() << "): "
              << func_busca.getNome()
              << ", Novo Salário: R$" << func_busca.getSalario() << std::endl;

        std::cout << "Listando Funcionarios após atualização:" << std::endl;
    for (const auto& f : gerenciadorFuncionarios.listarTodos()) {
        std::cout << "ID: " << f.getId()
                  << ", Nome: " << f.getNome()
                  << ", Cargo: " << f.getCargo()
                  << ", Salário: R$" << f.getSalario() << std::endl;
    }

        gerenciadorFuncionarios.remover(2);
        std::cout << "Funcionario removido (ID 2)." << std::endl;

        std::cout << "Listando Funcionarios após remoção:" << std::endl;
    for (const auto& f : gerenciadorFuncionarios.listarTodos()) {
        std::cout << "ID: " << f.getId()
                  << ", Nome: " << f.getNome()
                  << ", Cargo: " << f.getCargo()
                  << ", Salário: R$" << f.getSalario() << std::endl;
    }

        gerenciadorFuncionarios.buscar(99);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // --- Testando CRUD para Cliente ---
    std::cout << "\n--- CRUD Cliente ---" << std::endl;
    Cliente cli1(0, "Carlos Lima", "Av C, 789", "3333-3333", "carlos@gmail.com");
    Cliente cli2(0, "Ana Paula", "Av D, 101", "4444-4444", "ana@gmail.com");

    gerenciadorClientes.adicionar(cli1);
    gerenciadorClientes.adicionar(cli2);
    std::cout << "Clientes adicionados." << std::endl;

    std::cout << "Listando Clientes:" << std::endl;
    for (const auto& c : gerenciadorClientes.listarTodos()) {
        std::cout << "ID: " << c.getId()
              << ", Nome: " << c.getNome()
              << ", Email: " << c.getEmail()
              << ", Telefone: " << c.getTelefone() << std::endl;
    }

    try {
        Cliente cli_busca = gerenciadorClientes.buscar(1);
        std::cout << "Cliente encontrado (ID 1): " << cli_busca.getNome()
                  << ", Email: " << cli_busca.getEmail() << std::endl;

        cli_busca.setEmail("carlos.lima@gmail.com");
        gerenciadorClientes.atualizar(cli_busca);

        std::cout << "Cliente atualizado (ID " << cli_busca.getId() << "): "
              << cli_busca.getNome()
              << ", Novo Email: " << cli_busca.getEmail() << std::endl;

        std::cout << "Listando Clientes após atualização:" << std::endl;
        for (const auto& c : gerenciadorClientes.listarTodos()) {
            std::cout << "ID: " << c.getId()
                  << ", Nome: " << c.getNome()
                  << ", Email: " << c.getEmail() << std::endl;
        }

        gerenciadorClientes.remover(2);
        std::cout << "Cliente removido (ID 2)." << std::endl;

        std::cout << "Listando Clientes após remoção:" << std::endl;
        for (const auto& c : gerenciadorClientes.listarTodos()) {
            std::cout << "ID: " << c.getId()
                  << ", Nome: " << c.getNome()
                  << ", Email: " << c.getEmail() << std::endl;
        }

        gerenciadorClientes.buscar(99);
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    // --- Testando CRUD para PedidoCompra ---
    std::cout << "\n--- CRUD PedidoCompra ---" << std::endl;
    // Re-adicionar fornecedor e produto para o pedido de compra
    Fornecedor f_pedido(0, "Fornecedor Pedido", "contato_pedido@gmail.com");
    gerenciadorFornecedores.adicionar(f_pedido);

    Produto p_pedido(0, "Teclado", 150.0, 50, cat1, f_pedido, loc1);
    gerenciadorProdutos.adicionar(p_pedido);

    PedidoCompra pc1(0, "2025-06-26", 200.0, f_pedido);
    pc1.adicionarItem(ItemPedido(p_pedido, 1));
    gerenciadorPedidosCompra.adicionar(pc1);
    std::cout << "Pedido de Compra adicionado." << std::endl;

    // Demonstrando polimorfismo
    std::cout << "Demonstrando polimorfismo com mostrarResumo():" << std::endl;
    Transacao* t_pc1 = &gerenciadorPedidosCompra.buscar(1);
    t_pc1->mostrarResumo();

    try {
    PedidoCompra pc_busca = gerenciadorPedidosCompra.buscar(1);
    std::cout << "Pedido de Compra encontrado (ID " << pc_busca.getId() << ")." << std::endl;

    pc_busca.setValorTotal(250.0);
    gerenciadorPedidosCompra.atualizar(pc_busca);

    std::cout << "Pedido de Compra atualizado (ID " << pc_busca.getId() << "): "
              << "Novo valor total: R$" << pc_busca.getValorTotal() << std::endl;

    std::cout << "Listando Pedidos de Compra após atualização:" << std::endl;
    for (const auto& p : gerenciadorPedidosCompra.listarTodos()) {
        p.mostrarResumo();
    }

    gerenciadorPedidosCompra.remover(1);
    std::cout << "Pedido de Compra removido (ID 1)." << std::endl;

    std::cout << "Listando Pedidos de Compra após remoção:" << std::endl;
    if (gerenciadorPedidosCompra.listarTodos().empty()) {
        std::cout << "Nenhum pedido para listar." << std::endl;
    }

    gerenciadorPedidosCompra.buscar(99); // teste de erro
    } catch (const std::runtime_error& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
