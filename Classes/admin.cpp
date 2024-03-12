#include "Admin.h"
#include <iostream>
#include <string>

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


int Admin::adminPainel() {
    system("clear");
    if (!autorizado) {
        cout << "Você não está autorizado a acessar esta função." << endl;
        return 0;
    }

    cout << endl;
    cout << "       >>Admin area<<" << endl;
    cout << "     1. Total ganho hoje" << endl << endl;
    cout << "     2. Listar todos" << endl << endl;
    cout << "     3. Adicionar Bebida" << endl << endl;
    cout << "     4. Adicionar comida" << endl << endl;
    cout << "     5. Deletar item" << endl << endl;
    cout << "     6. Alterar item" << endl << endl;
    cout << "     0. Main Menu" << endl << endl;
    cout << "        Enter Your From 1-0: ";

    int opcao;
    cin >> opcao;


    switch (opcao) {
        case 1:
            cout << "Implemente a lógica para Total ganho hoje" << endl;
            break;
        case 2:
            cout << "Implemente a lógica para Listar todos" << endl;
            break;
        case 3:
            cout << "Implemente a lógica para Adicionar bebida" << endl;
            break;
        case 4:
            cout << "Implemente a lógica para Adicionar comida" << endl;
            break;
        case 5:
            cout << "Implemente a lógica para deletar item" << endl;
            break;
        case 6:
            cout << "Implemente a lógica para Alterar item" << endl;
            break;
        case 0:
            cout << "Retornando ao Menu Principal..." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
    }
    return opcao;
}