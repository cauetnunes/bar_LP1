#include "bancoDados.h"
#include <iostream>

// Implementação do construtor da classe bancoDados
bancoDados::bancoDados(/* args */) {}

// Implementação do método criarTabelas da classe bancoDados
void bancoDados::criarTabelas(pqxx::connection &conn) {
    if (!conn.is_open()) {
        std::cerr << "Conexão com o banco de dados falhou" << std::endl;
        return;
    }
    try {
        std::cout << "Criando tabelas..." << std::endl;
        pqxx::work txn(conn);
        // Substitua isso com o esquema real da sua tabela
        txn.exec("CREATE TABLE IF NOT EXISTS Cliente ("
                 "id serial PRIMARY KEY,"
                 "nome VARCHAR(100) NOT NULL);");
        txn.commit();
        std::cout << "Tabelas criadas com sucesso!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erro ao criar tabelas: " << e.what() << std::endl;
    }
}

// Implementação do método conectarBancoDados da classe bancoDados
std::unique_ptr<pqxx::connection> bancoDados::conectarBancoDados() {
    const char *conninfo = "dbname=postgres user=postgres password=cauet host=localhost port=5432";
    auto conn = std::make_unique<pqxx::connection>(conninfo);

    if (conn->is_open()) {
        std::cout << "Conexão com o banco de dados bem-sucedida" << std::endl;
    } else {
        std::cerr << "Conexão com o banco de dados falhou" << std::endl;
        throw std::runtime_error("Erro na conexão com o banco de dados");
    }

    return conn;
}
