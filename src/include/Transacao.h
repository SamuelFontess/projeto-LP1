#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <vector>
#include <ctime>

class Transacao {
protected:
    int id;
    std::string data;
    double valorTotal;

public:
    Transacao(int id, const std::string& data, double valorTotal);
    virtual ~Transacao() = default; // Virtual destructor for polymorphism

    // Getters
    int getId() const;
    std::string getData() const;
    double getValorTotal() const;

    // Setters
    void setData(const std::string& data);
    void setValorTotal(double valorTotal);
    void setId(int id) { this->id = id; }

    virtual void mostrarResumo() const = 0; // Pure virtual function for polymorphism
};

#endif // TRANSACAO_H


