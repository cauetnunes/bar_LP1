    #include <iostream>
    #include "Menu.h"



    int main()
    {
        vector<Produto*> produtos;
        vector<Pedido*> pedidos;
        Menu menu;
        menu.lerProdutos(produtos);
        menu.lerPedidos(pedidos);


        return menu.abrirmenu(produtos, pedidos);

            
        
    }   

