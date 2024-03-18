#pragma once
#include "Produto.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// FILHO DE PRODUTO

class Bebida : public Produto {
public:

    
    Bebida() : Produto(0, "", 0.0, 0) {}
    Bebida(int _id, string _nome, float _preço, int _qtdEstoque, float _volume, string _tipo)
    : Produto(_id, _nome, _preço, _qtdEstoque), volume(_volume), tipo(_tipo) {}

    void Mostrar() const override;
    void criar()override;
    void ler(ifstream& arquivo)override;
    void escrever(ofstream& arquivo)override;
    void remover(vector<Produto*>& cardapio, const string& nomeRemover) override;   
    void editar(vector<Produto*>& cardapio) override;


    float getVolume() const;
    string getTipo() const;
    
    void setVolume(float _volume);
    void setTipo(string _tipo);


private:

    
    float volume;
    string tipo;
   


};
