#include "Produto.h"



int Produto::getId() const {
    return id;
}

string Produto::getNome() const {
    return nome;
}

float Produto::getPreco() const {
    return preco;
}

int Produto::getQtdEstoque() const {
    return qtdEstoque;
}




void Produto::setId(int _id) {
    id = _id;
}

void Produto::setNome(string _nome) {
    nome = _nome;
}

void Produto::setPreco(float _preco) {
    preco = _preco;
}

void Produto::setQtdEstoque(int _qtdEstoque) {
    qtdEstoque = _qtdEstoque;
}

