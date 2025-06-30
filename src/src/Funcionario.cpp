#include "Funcionario.h"

Funcionario::Funcionario(int id, const std::string& nome, const std::string& endereco, const std::string& telefone, const std::string& cargo, double salario)
    : Pessoa(id, nome, endereco, telefone), cargo(cargo), salario(salario) {}

std::string Funcionario::getCargo() const {
    return cargo;
}

double Funcionario::getSalario() const {
    return salario;
}

void Funcionario::setCargo(const std::string& cargo) {
    this->cargo = cargo;
}

void Funcionario::setSalario(double salario) {
    this->salario = salario;
}


