#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
#include <string>

class Funcionario : public Pessoa {
private:
    std::string cargo;
    double salario;

public:
    Funcionario(int id, const std::string& nome, const std::string& endereco, const std::string& telefone, const std::string& cargo, double salario);

    // Getters
    std::string getCargo() const;
    double getSalario() const;

    // Setters
    void setCargo(const std::string& cargo);
    void setSalario(double salario);
};

#endif // FUNCIONARIO_H


