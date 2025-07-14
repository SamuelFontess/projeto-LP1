classDiagram
    class Pessoa {
        #int id
        #string nome
        #string endereco
        #string telefone
        +Pessoa(int, string, string, string)
        +getId() int
        +getNome() string
        +getEndereco() string
        +getTelefone() string
        +setNome(string)
        +setEndereco(string)
        +setTelefone(string)
        +setId(int)
    }

    class Funcionario {
        -string cargo
        -double salario
        +Funcionario(int, string, string, string, string, double)
        +getCargo() string
        +getSalario() double
        +setCargo(string)
        +setSalario(double)
    }

    class Cliente {
        -string email
        +Cliente(int, string, string, string, string)
        +getEmail() string
        +setEmail(string)
    }

    class Transacao {
        #int id
        #string data
        #double valorTotal
        +Transacao(int, string, double)
        +getId() int
        +getData() string
        +getValorTotal() double
        +setData(string)
        +setValorTotal(double)
        +mostrarResumo() void
        +setId(int)
    }

    class PedidoCompra {
        -Fornecedor fornecedor
        -vector~ItemPedido~ itens
        +PedidoCompra(int, string, double, Fornecedor)
        +getFornecedor() Fornecedor
        +getItens() vector~ItemPedido~
        +setFornecedor(Fornecedor)
        +adicionarItem(ItemPedido)
        +mostrarResumo() void
    }

    class Produto {
        -int id
        -string nome
        -double preco
        -int quantidade
        -CategoriaProduto categoria
        -Fornecedor fornecedor
        -LocalizacaoEstoque localizacao
        +Produto(int, string, double, int, CategoriaProduto, Fornecedor, LocalizacaoEstoque)
        +getId() int
        +getNome() string
        +getPreco() double
        +getQuantidade() int
        +getCategoria() CategoriaProduto
        +getFornecedor() Fornecedor
        +getLocalizacao() LocalizacaoEstoque
        +setNome(string)
        +setPreco(double)
        +setQuantidade(int)
        +setCategoria(CategoriaProduto)
        +setFornecedor(Fornecedor)
        +setLocalizacao(LocalizacaoEstoque)
        +setId(int)
    }

    class Fornecedor {
        -int id
        -string nome
        -string contato
        +Fornecedor(int, string, string)
        +getId() int
        +getNome() string
        +getContato() string
        +setNome(string)
        +setContato(string)
        +setId(int)
    }

    class CategoriaProduto {
        -int id
        -string nome
        +CategoriaProduto(int, string)
        +getId() int
        +getNome() string
        +setNome(string)
        +setId(int)
    }

    class ItemPedido {
        -Produto produto
        -int quantidade
        +ItemPedido(Produto, int)
        +getProduto() Produto
        +getQuantidade() int
        +setQuantidade(int)
    }

    class LocalizacaoEstoque {
        -int id
        -string corredor
        -string prateleira
        +LocalizacaoEstoque(int, string, string)
        +getId() int
        +getCorredor() string
        +getPrateleira() string
        +setCorredor(string)
        +setPrateleira(string)
        +setId(int)
    }

    Pessoa <|-- Funcionario
    Pessoa <|-- Cliente
    Transacao <|-- PedidoCompra
    Fornecedor "1" -- "n" Produto : fornece
    PedidoCompra "n" -- "m" ItemPedido : contém
    ItemPedido "1" -- "1" Produto : refere-se
    Produto "1" -- "1" LocalizacaoEstoque : localizado em
    Produto "1" -- "1" CategoriaProduto : pertence a
    PedidoCompra "1" -- "1" Fornecedor : feito para

    class Gerenciador~T~ {
        -vector~T~ colecao
        -int proximoId
        +Gerenciador()
        +adicionar(T)
        +buscar(int) T&
        +atualizar(T)
        +remover(int)
        +listarTodos() vector~T~
    }



