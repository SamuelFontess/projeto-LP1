#ifndef LOCALIZACAOESTOQUE_H
#define LOCALIZACAOESTOQUE_H

#include <string>

class LocalizacaoEstoque {
private:
    int id;
    std::string corredor;
    std::string prateleira;

public:
    LocalizacaoEstoque(int id, const std::string& corredor, const std::string& prateleira);

    // Getters
    int getId() const;
    std::string getCorredor() const;
    std::string getPrateleira() const;

    // Setters
    void setCorredor(const std::string& corredor);
    void setPrateleira(const std::string& prateleira);
    void setId(int id) { this->id = id; }
};

#endif // LOCALIZACAOESTOQUE_H


