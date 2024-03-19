    #include "Admin.h"
    #include <iostream>
    #include <string>
    #include <unistd.h>
    #include <limits>
    #include "Cliente.h"
    #include "Pedido.h"

    using namespace std;



    int Admin::login() {
        string n;
        string s;

        do {
            cout << "Digite seu nome de admin: ";
            cin >> n;
            cout << "Digite sua senha: ";
            cin >> s;
    
        } while (n != name || s != senha);

        cout << "Login feito com sucesso!" << endl;
        autorizado = true;
        return autorizado;
    }




    int Admin::adminPainel(vector<Produto*>& produtos, vector<Pedido*>& pedidos) {
        system("clear");
        if (!autorizado) {
            cout << "Você não está autorizado a acessar esta função." << endl;
            return 0;
        }

        int opcao = -1;
        bool sair = false;
        while (!sair) {
            system("clear");
            cout << endl;
            cout << "       >>Admin area<<" << endl;
            cout << "     1. Total ganho" << endl << endl;
            cout << "     2. Listar todos" << endl << endl;
            cout << "     3. Adicionar Bebida" << endl << endl;
            cout << "     4. Adicionar comida" << endl << endl;
            cout << "     5. Deletar item" << endl << endl;
            cout << "     6. Alterar item" << endl << endl;
            cout << "     0. Main Menu" << endl << endl;
            cout << "     Escolha um valor de 0-6 ";

            cin >> opcao;

            Bebida novaBebida;
            Comida novaComida;
            string nomeRemover;
            string nomeEditar;
            float faturamentoTotal = 0.0f;
        

            switch (opcao) {
                case 1:
                    system("clear");
                    cout << "Lista de Pedidos:" << endl;
                    mostrarPedidos(pedidos);

                    
                    faturamentoTotal = somarValores(pedidos);
                    

                    cout << endl << "Faturamento Total: R$ " << faturamentoTotal << endl;
                    cout << "Pressione Enter para retornar ao painel de admin" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                            
                case 2:
                    system("clear");
                    cout << "Lista de todos os produtos:" << endl << endl;
                    mostrarComidas(produtos);
                    mostrarBebidas(produtos);
                    cout << "Pressione Enter para retornar ao painel de admin";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cin.get(); 
                    
                    break;
                case 3:
                    novaBebida.criar();
                    produtos.push_back(new Bebida(novaBebida.getId(), novaBebida.getNome(), novaBebida.getPreco(), novaBebida.getQtdEstoque(), novaBebida.getVolume(), novaBebida.getTipo()));
                    sleep(2);
                    system("clear");
                    break;
                case 4:
                    novaComida.criar();
                    produtos.push_back(new Comida(novaComida.getId(), novaComida.getNome(), novaComida.getPreco(), novaComida.getQtdEstoque(), novaComida.getPorcao()));
                    sleep(2);
                    system("clear");
                    break;
                case 5:
                    system("clear");
                    cout << "Cardápio atual:" << endl << endl;
                    cout << "Bebidas:" << endl;
                    mostrarBebidas(produtos);
                    cout << endl << "Comidas:" << endl;
                    mostrarComidas(produtos);
                    cout << endl;

                    cout << "Digite o nome do produto que deseja remover ou 0 para voltar ao painel de admin: ";
                    cin >> nomeRemover;

                    if (nomeRemover == "0")
                    {
                        break;
                    }
                    
                    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
                        if ((*it)->getNome() == nomeRemover) {
                            if (dynamic_cast<Comida*>(*it) != nullptr) {
                                Comida* comidaRemover = dynamic_cast<Comida*>(*it);
                                comidaRemover->remover(produtos, nomeRemover);
                            } else if (dynamic_cast<Bebida*>(*it) != nullptr) {
                                Bebida* bebidaRemover = dynamic_cast<Bebida*>(*it);
                                bebidaRemover->remover(produtos, nomeRemover);
                            }
                            break;
                        }
                    }
                    break;
                case 6:
                    system("clear");
                    cout << "Cardápio atual:" << endl << endl;
                    cout << "Bebidas:" << endl;
                    mostrarBebidas(produtos);
                    cout << endl << "Comidas:" << endl;
                    mostrarComidas(produtos);
                    cout << endl;

                    cout << "Digite o nome do produto que deseja editar ou 0 para voltar ao painel de admin: ";
                    cin >> nomeEditar;

                    if (nomeEditar == "0") {
                      break; 
                     }

                    for (auto& produto : produtos) {
                        if (produto->getNome() == nomeEditar) {
                            if (dynamic_cast<Comida*>(produto) != nullptr) {
                                Comida* comidaEditar = dynamic_cast<Comida*>(produto);
                                comidaEditar->editar(produtos);
                            } else if (dynamic_cast<Bebida*>(produto) != nullptr) {
                                Bebida* bebidaEditar = dynamic_cast<Bebida*>(produto);
                                bebidaEditar->editar(produtos);
                            }
                            break;
                        }
                    }
                    cout << "Produto editado com sucesso!"<< endl;
                    sleep(2);
                    break;

                case 0:
                    cout << "Retornando ao Menu Principal..." << endl;
                    sair = true;
                    break;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
                    break;
            }
        }
        return opcao;
    }

    
float Admin::somarValores(std::vector<Pedido*>& pedidos) {
    float total = 0.0f;
    for (const auto& pedido : pedidos) {
        total += pedido->getValorTotal();
    }
    return total;
}
