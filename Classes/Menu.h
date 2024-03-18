#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <vector>
#include "Produto.h"
#include "Bebida.h"
#include "Comida.h"
#include "Admin.h"
#include "Cliente.h"
#include <iostream>
#include <string>
#include "Pedido.h"

using namespace std;

class Menu
{
public:
    void telaErro(int x);
    int abrirmenu(vector<Produto*>& produtos, vector<Pedido*>& pedidos);
    void lerProdutos(vector<Produto*>& produtos);
    void salvarProdutos(const vector<Produto*>& produtos);
    void interagirCliente(vector<Produto*>& produtos, Admin& adm);
    void lerPedidos(vector<Pedido*>& pedidos);


private:
    
};

#endif  