#pragma once
#include <iostream>
#include <string>
#include "Produto.h"
#include "Comida.h"
#include "Bebida.h"
#include <vector>
#include "Pedido.h"


using namespace std;




class Admin
{
private:
    string const name = "cauet";
    string const senha = "123";
    vector<Produto*>& produtos;
    bool autorizado = false;
public:
    Admin(vector<Produto*>& _produtos) : produtos(_produtos) {}
    int login();
    int adminPainel(vector<Produto*>& produtos, vector<Pedido*>& pedidos);
     float somarValores(std::vector<Pedido*>& pedidos);
    
    void mostrarComidas(const vector<Produto*>& produtos) {
    cout << "|   ID   |       Nome       |  Preço  |   Estoque   |  Porção  |" << endl;
    cout << "----------------------------------------------------------------" << endl;

    bool hasComida = false;
    for (const auto& produto : produtos) {
        if (dynamic_cast<Comida*>(produto) != nullptr) {
            hasComida = true;
            Comida* comida = dynamic_cast<Comida*>(produto);
            comida->Comida::Mostrar();
        }
    }

    if (!hasComida) {
        cout << "Nenhuma comida cadastrada." << endl;
    }

    cout << "----------------------------------------------------------------" << endl;
}

void mostrarBebidas(const vector<Produto*>& produtos) {
    cout << "|   ID   |       Nome       |  Preço  |   Estoque   |  Volume  |   Tipo   |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    bool hasBebida = false;
    for (const auto& produto : produtos) {
        if (dynamic_cast<Bebida*>(produto) != nullptr) {
            hasBebida = true;
            Bebida* bebida = dynamic_cast<Bebida*>(produto);
            bebida->Bebida::Mostrar();
        }
    }

    if (!hasBebida) {
        cout << "Nenhuma bebida cadastrada." << endl;
    }

    cout << "--------------------------------------------------------------------------" << endl;
}


void mostrarPedidos(vector<Pedido*>& pedidos) {
    cout << "|*******************************|" << endl;
    cout << "|        Lista de Pedidos       |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    if (pedidos.empty()) {
        cout << "Nenhum pedido cadastrado." << endl;
    } else {
        for (const auto& pedido : pedidos) {
            cout << "Pedido -------------------------------------------------- R$ " << pedido->getValorTotal() << endl;
        }
    }

    cout << "--------------------------------------------------------------------------" << endl;
}






};