# Sistema de Controle de Estoque Simples

Este projeto implementa um sistema de controle de estoque simples utilizando C++ e os princípios de Programação Orientada a Objetos (POO), atendendo aos requisitos mínimos especificados na atividade.

## Requisitos Atendidos:

- **8 Classes:**
    - `Produto`
    - `Fornecedor`
    - `CategoriaProduto`
    - `PedidoCompra`
    - `Funcionario`
    - `Cliente`
    - `ItemPedido`
    - `LocalizacaoEstoque`
    - `Pessoa` (classe base para `Funcionario` e `Cliente`)
    - `Transacao` (classe base para `PedidoCompra`)
    - `Gerenciador` (classe template para CRUD)

- **Relacionamentos (1:1, 1:n, n:m):**
    - **1:n:** Um `Fornecedor` fornece vários `Produtos`.
    - **n:m:** Um `PedidoCompra` tem vários `Produtos` (através de `ItemPedido`), e cada `Produto` pode aparecer em vários pedidos.
    - **1:1:** Cada `Produto` tem um `LocalizacaoEstoque` fixo.

- **Encapsulamento:** Todos os atributos das classes são `private` ou `protected`, com métodos `get` e `set` públicos para acesso controlado.

- **Herança:**
    - `Funcionario` e `Cliente` herdam de `Pessoa`.
    - `PedidoCompra` herda de `Transacao`.

- **Polimorfismo:** O método `mostrarResumo()` é virtual puro na classe `Transacao` e sobrescrito em `PedidoCompra`.

- **Templates:** A classe `Gerenciador<T>` é um template que permite operações CRUD genéricas para qualquer tipo de entidade que possua um método `getId()` e `setId()`.

- **CRUD de 5 entidades + exceções:** Implementado CRUD completo (Criar, Ler, Atualizar, Remover) para as entidades `Produto`, `Fornecedor`, `Funcionario`, `Cliente` e `PedidoCompra`. O tratamento de exceções é realizado para casos de itens não encontrados durante as operações de busca, atualização e remoção.

- **Diagrama de Classes – UML:** Gerado utilizando Mermaid, disponível no arquivo `diagrama.md` e `diagrama.png`.

## Estrutura do Projeto:

- `src/`: Contém todos os arquivos `.h` (cabeçalho) e `.cpp` (implementação) das classes.
- `main.cpp`: Contém a lógica principal do programa, demonstrando o uso das classes e as operações CRUD.
- `diagrama.md`: Código Mermaid do diagrama UML.
- `diagrama.png`: Imagem do diagrama UML.
- `documentacao.md`: Este arquivo de documentação.

## Como Compilar e Executar:

1. Navegue até o diretório raiz do projeto.
2. Compile o código usando um compilador C++ (ex: g++):
   ```bash
   g++ -std=c++11 src/*.cpp -o estoque_app
   ```
3. Execute o programa:
   ```bash
   ./estoque_app
   ```

## Observações:

- A classe `Gerenciador` assume que a classe `T` possui um construtor de cópia e um operador de atribuição, além dos métodos `getId()` e `setId()`.
- Os IDs são gerados automaticamente pela classe `Gerenciador` ao adicionar um novo item.