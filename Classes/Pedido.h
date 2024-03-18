#ifndef PEDIDO_H
#define PEDIDO_H
#include <vector>


using namespace std;

class Pedido {
private:
    float valorTotal;
    

public:
    Pedido(float _valorTotal);
    
    void printPedidos(vector<Pedido*>& pedidos);
    float somarValores(vector<Pedido*>& pedidos);
    float getValorTotal() const;
   
    
};

#endif 
