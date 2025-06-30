#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Gerenciador {
private:
    std::vector<T> colecao;
    int proximoId;

public:
    Gerenciador() : proximoId(1) {}

    void adicionar(T item) {
        item.setId(proximoId++);
        colecao.push_back(item);
    }

    T& buscar(int id) {
        for (auto& item : colecao) {
            if (item.getId() == id) {
                return item;
            }
        }
        throw std::runtime_error("Item nao encontrado.");
    }

    void atualizar(const T& itemAtualizado) {
        for (auto& item : colecao) {
            if (item.getId() == itemAtualizado.getId()) {
                item = itemAtualizado;
                return;
            }
        }
        throw std::runtime_error("Item para atualizar nao encontrado.");
    }

    void remover(int id) {
        auto it = std::remove_if(colecao.begin(), colecao.end(),
                                 [id](const T& item) { return item.getId() == id; });
        if (it == colecao.end()) {
            throw std::runtime_error("Item para remover nao encontrado.");
        }
        colecao.erase(it, colecao.end());
    }

    std::vector<T> listarTodos() const {
        return colecao;
    }
};

#endif // GERENCIADOR_H


