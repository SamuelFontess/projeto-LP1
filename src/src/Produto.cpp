#include "Produto.h"

Produto::Produto(int id, const std::string& nome, double preco, int quantidade, const CategoriaProduto& categoria, const Fornecedor& fornecedor, const LocalizacaoEstoque& localizacao)
    : id(id), nome(nome), preco(preco), quantidade(quantidade), categoria(categoria), fornecedor(fornecedor), localizacao(localizacao) {}

int Produto::getId() const {
    return id;
}

std::string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getQuantidade() const {
    return quantidade;
}

CategoriaProduto Produto::getCategoria() const {
    return categoria;
}

Fornecedor Produto::getFornecedor() const {
    return fornecedor;
}

LocalizacaoEstoque Produto::getLocalizacao() const {
    return localizacao;
}

void Produto::setNome(const std::string& nome) {
    this->nome = nome;
}

void Produto::setPreco(double preco) {
    this->preco = preco;
}

void Produto::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

void Produto::setCategoria(const CategoriaProduto& categoria) {
    this->categoria = categoria;
}

void Produto::setFornecedor(const Fornecedor& fornecedor) {
    this->fornecedor = fornecedor;
}

void Produto::setLocalizacao(const LocalizacaoEstoque& localizacao) {
    this->localizacao = localizacao;
}


