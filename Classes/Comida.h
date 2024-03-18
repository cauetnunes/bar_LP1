#pragma once
#include "Produto.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


// FILHO DE PRODUTO

class Comida : public Produto {
public:
    Comida() : Produto(0, "", 0.0, 0) {}
    Comida(int _id, string _nome, float _preço, int _qtdEstoque, string _porcao)
    : Produto(_id, _nome, _preço, _qtdEstoque), porcao(_porcao) {}

    void Mostrar() const override;
    void criar() override; 
    void ler(ifstream& arquivo)override;
    void escrever(ofstream& arquivo)override;
    void remover(vector<Produto*>& cardapio, const string& nomeRemover) override;
    void editar(vector<Produto*>& cardapio) override;

    string getPorcao() const;
    
    void setPorcao(string _porcao);

private:

    string porcao;
    


};
