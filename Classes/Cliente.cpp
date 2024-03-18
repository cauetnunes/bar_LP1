#include "Cliente.h"

float Cliente::calcularTotal() {
    float total = 0.0f;
    for (const auto& pedido : pedidos) {
        total += pedido->getPreco();
    }
    return total;
}

void Cliente::adicionarPedido(Produto* produto) {
    pedidos.push_back(produto);
}

void Cliente::encerrarSessao() {
    pedidos.clear(); 
}


vector<Produto*> Cliente::getPedidos() {
    return pedidos;
}

void Cliente::salvarPedidos() {
    ofstream arquivo("pedidos.txt", ios_base::app); 

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo pedidos.txt" << endl;
        return;
    }

   
    Produto* ultimoPedido = pedidos.back();
    if (ultimoPedido != nullptr) {
         arquivo << "Pedido -------------------------------------------------- R$ " << ultimoPedido->getPreco() << endl;
    }

    arquivo.close();
}
