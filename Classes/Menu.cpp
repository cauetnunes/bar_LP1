// Menu.cpp
#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;


void Menu::telaErro(int x) {
    
    cout << "Insira um valor válido." << x << endl;
}

// Abre o menu principal e retorna a opção escolhida pelo usuário
int Menu::abrirmenu() {
    int opcao = 0;

    cout << "Bem-vindo ao BAR DO CI!" << endl;

    cout << "Escolha uma opção:" << endl;
    cout << " >> 1 - Escolher uma mesa para sentar" << endl;
    cout << " >> 2 - Entrar como admin" << endl;
    cout << " >> 3 - Sair" << endl;
    
    
    cout << "Digite sua opção: ";
    cin >> opcao;
    



    // Valida a entrada do usuário
    if(cin.fail() || opcao < 1 || opcao > 3) {
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta o buffer de entrada
        telaErro(1); 
        return 0; 
    }

    return opcao; 
}