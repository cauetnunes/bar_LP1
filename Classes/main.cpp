// #include <iostream>
// #include "Menu.h"

// int main()
// {
//    Menu menu;
//     return menu.abrirmenu();

    
// } 

#include <pqxx/pqxx>
#include <iostream>
#include "bancoDados.h"

int main() {
    
    bancoDados db; // Cria um objeto bancoDados

    try {
        auto conn = db.conectarBancoDados(); // Chama o método conectarBancoDados para obter uma conexão

        if (!conn->is_open()) {
            std::cerr << "Conexão com o banco de dados falhou" << std::endl;
            return 1;
        }

        // Chamar a função para criar tabelas
        db.criarTabelas(*conn);  // Chama o método criarTabelas passando a conexão desreferenciada

        // A conexão será fechada automaticamente ao sair do escopo
    } catch (const std::exception &e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
