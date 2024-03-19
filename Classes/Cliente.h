#pragma once
#include "Pedido.h"
#include <vector>
#include "Produto.h"
#include <fstream>
using namespace std;

class Cliente
{
private:
    vector<Produto*> pedidos;

public:
    float calcularTotal();
    void adicionarPedido(Produto* produto);
    void encerrarSessao();
    void salvarPedidos(float valorTotal);
    void carregarPedidos();
    vector<Produto*> getPedidos();

    
};
