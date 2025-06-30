#ifndef CATEGORIAPRODUTO_H
#define CATEGORIAPRODUTO_H

#include <string>

class CategoriaProduto {
private:
    int id;
    std::string nome;

public:
    CategoriaProduto(int id, const std::string& nome);

    // Getters
    int getId() const;
    std::string getNome() const;

    // Setters
    void setNome(const std::string& nome);
    void setId(int id) { this->id = id; }
};

#endif // CATEGORIAPRODUTO_H
