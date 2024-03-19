    #include "Menu.h"
    #include <iostream>
    #include <limits>
    #include <unistd.h>
    #include "Admin.h"
    #include "Cliente.h"



    using namespace std;

    void Menu::salvarProdutos(const vector<Produto*>& produtos) {
        ofstream arquivo("produtos.txt");
        if (!arquivo.is_open()) {
            cout << "Erro ao criar o arquivo produtos.txt" << endl;
            return;
        }

        for (const auto& produto : produtos) {
            if (dynamic_cast<Comida*>(produto) != nullptr) {
                arquivo << "0 ";
                produto->escrever(arquivo);
            } else if (dynamic_cast<Bebida*>(produto) != nullptr) {
                arquivo << "1 ";
                produto->escrever(arquivo);
            }
        }

        arquivo.close();
    }


void Menu::lerPedidos(vector<Pedido*>& pedidos) {
    ifstream arquivo("pedidos.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo pedidos.txt" << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        size_t pos = linha.find("R$ ");
        if (pos != string::npos) {
            try {
                float total = stof(linha.substr(pos + 3)); 
                pedidos.push_back(new Pedido(total)); 
            } catch (const std::invalid_argument& e) {
                cout << "Erro ao converter valor: " << e.what() << endl;
            } catch (const std::out_of_range& e) {
                cout << "Erro ao converter valor: " << e.what() << endl;
            }
        }
    }

    arquivo.close();
}




    void Menu::lerProdutos(vector<Produto*>& produtos) {
        ifstream arquivo("produtos.txt");
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo produtos.txt" << endl;
            return;
        }

        int tipo;
        while (arquivo >> tipo) {
            if (tipo == 0) {
                int id;
                string nome;
                float preco;
                int qtdEstoque;
                string porcao;

                arquivo >> id >> nome >> preco >> qtdEstoque >> porcao;
                produtos.push_back(new Comida(id, nome, preco, qtdEstoque, porcao));
            } else if (tipo == 1) {
                int id;
                string nome;
                float preco;
                int qtdEstoque;
                float volume;
                string tipo;

                arquivo >> id >> nome >> preco >> qtdEstoque >> volume >> tipo;
                produtos.push_back(new Bebida(id, nome, preco, qtdEstoque, volume, tipo));
            }
        }

        arquivo.close();
    }




    void Menu::telaErro(int x) {
        
        cout << "Insira um valor válido." << x << endl;
    }


    int Menu::abrirmenu(vector<Produto*>& produtos, vector<Pedido*>& pedidos) {
        int opcao = 0;
        Admin adm(produtos);

        do {
            system("clear");
            cout << "Bem-vindo ao BAR DO CI!" << endl;
            sleep(0.5);

            cout << "Escolha uma opção:" << endl;
            sleep(0.5);
            cout << " >> 1 - Entrar no Bar e fazer Pedido" << endl;
            sleep(0.5);
            cout << " >> 2 - Entrar como admin" << endl;
            sleep(0.5);
            cout << " >> 3 - Sair" << endl;
            sleep(0.5);

            cout << "Digite sua opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    interagirCliente(produtos, adm);
                    break;
                case 2:
                    if (adm.login()) {
                        adm.adminPainel(produtos, pedidos);
                    } else {
                        cout << "Login inválido. Tente novamente." << endl;
                        sleep(2);
                    }
                    break;
                case 3:
                    salvarProdutos(produtos);
                    return 0;
                    break;
                default:
                    cout << "Insira um valor válido!" << endl;
                    sleep(2);
                    break;
            }
        } while (true);

        return opcao;
    }


    void Menu::interagirCliente(vector<Produto*>& produtos, Admin& adm) {
    Cliente cliente;
    int opcao;
   

    do {
        system("clear");
        cout << "Bem-vindo ao BAR DO CI!" << endl;
        

        cout << "Cardápio:" << endl;
        adm.mostrarComidas(produtos);
        adm.mostrarBebidas(produtos);

        cout << "Digite o ID do produto que deseja pedir (ou 0 para fechar a conta): ";
        cin >> opcao;

        if (opcao != 0) {
            Produto* produto = nullptr;
            for (const auto& p : produtos) {
                if (p->getId() == opcao) {
                    produto = p;
                    break;
                }
            }

            if (produto != nullptr) {
                cliente.adicionarPedido(produto);
                cout << "Produto adicionado ao pedido." << endl;
                
            } else {
                cout << "ID de produto inválido. Tente novamente." << endl;
                
            }   
        }
    } while (opcao != 0);

   
    system("clear");    
    cout << "Produtos consumidos:" << endl;
    for (const auto& pedido : cliente.getPedidos()) {
        if (auto comida = dynamic_cast<Comida*>(pedido)) {
            comida->Mostrar();
        } else if (auto bebida = dynamic_cast<Bebida*>(pedido)) {
            bebida->Mostrar();
        }
    }

    
    cout << "Total da conta: R$ " << cliente.calcularTotal() << endl;
    cout << "Pressione Enter para pagar e sair." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
    if (!cliente.getPedidos().empty()) {
    float totalConta = cliente.calcularTotal();
    cliente.salvarPedidos(totalConta);
}
    cout << "Obrigado por visitar o BAR DO CI! Volte sempre." << endl;
    sleep(2);   
}   