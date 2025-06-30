#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include "CategoriaProduto.h"
#include "Fornecedor.h"
#include "LocalizacaoEstoque.h"

class Produto {
private:
    int id;
    std::string nome;
    double preco;
    int quantidade;
    CategoriaProduto categoria;
    Fornecedor fornecedor;
    LocalizacaoEstoque localizacao;

public:
    Produto(int id, const std::string& nome, double preco, int quantidade, const CategoriaProduto& categoria, const Fornecedor& fornecedor, const LocalizacaoEstoque& localizacao);

    // Getters
    int getId() const;
    std::string getNome() const;
    double getPreco() const;
    int getQuantidade() const;
    CategoriaProduto getCategoria() const;
    Fornecedor getFornecedor() const;
    LocalizacaoEstoque getLocalizacao() const;

    // Setters
    void setNome(const std::string& nome);
    void setPreco(double preco);
    void setQuantidade(int quantidade);
    void setCategoria(const CategoriaProduto& categoria);
    void setFornecedor(const Fornecedor& fornecedor);
    void setLocalizacao(const LocalizacaoEstoque& localizacao);
    void setId(int id) { this->id = id; }
};

#endif // PRODUTO_H


