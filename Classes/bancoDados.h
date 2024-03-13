
#pragma once

#include <pqxx/pqxx>
class bancoDados
{
private:
    /* data */
public:
    bancoDados(/* args */);
    std::unique_ptr<pqxx::connection> conectarBancoDados();
void criarTabelas(pqxx::connection &conn);
};


