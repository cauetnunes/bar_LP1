#include "Pedido.h"
#include <iostream>

Pedido::Pedido(float _valorTotal) : valorTotal(_valorTotal) {}

float Pedido::getValorTotal() const {
    return valorTotal;
}

void Pedido::printPedidos(vector<Pedido*>& pedidos) {
    for (const auto& pedido : pedidos) {
        std::cout << "Pedido -------------------------------------------------- R$ " << pedido->valorTotal << std::endl;
    }
}

