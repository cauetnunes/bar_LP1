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

void Cliente::salvarPedidos(float valorTotal) {
    ofstream arquivo("pedidos.txt", ios_base::app); // Abre o arquivo em modo de adição

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo pedidos.txt" << endl;
        return;
    }

    arquivo << "Pedido -------------------------------------------------- R$ " << valorTotal << endl;

    arquivo.close();
}
