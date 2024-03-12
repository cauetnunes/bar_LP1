#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produto {
protected: 
    int id;
    string nome;
    float preco;
    int qtdEstoque;

public:
    Produto(int _id, string _nome, float _preco, int _qtdEstoque)
        : id(_id), nome(_nome), preco(_preco), qtdEstoque(_qtdEstoque) {}

    virtual ~Produto() {}

    virtual void criar() = 0;
    virtual void ler()  = 0;
    virtual void atualizar() = 0;
    virtual void remover() = 0;
};


