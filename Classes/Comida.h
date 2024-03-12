#pragma once
#include "Produto.h"
#include <iostream>


using namespace std;


// FILHO DE PRODUTO

class Comida : public Produto {
public:
    Comida(int _id, string _nome, float _preço, int _qtdEstoque)
        : Produto(_id, _nome, _preço, _qtdEstoque) {}

    void criar() override; 

    void ler()override;

    void atualizar()override;

    void remover()override;


private:

    string porcao;
    


};
