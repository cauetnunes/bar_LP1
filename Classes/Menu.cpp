#include "Menu.h"
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "Admin.h"



using namespace std;


void Menu::telaErro(int x) {
    
    cout << "Insira um valor válido." << x << endl;
}

// Abre o menu principal e retorna a opção escolhida pelo usuário
int Menu::abrirmenu() {
    int opcao = 0;
    Admin adm;

    do {
        system("clear");
        cout << "Bem-vindo ao BAR DO CI!" << endl;
        sleep(2);

        cout << "Escolha uma opção:" << endl;
        sleep(1);
        cout << " >> 1 - Escolher uma mesa para sentar" << endl;
        sleep(1);
        cout << " >> 2 - Entrar como admin" << endl;
        sleep(1);
        cout << " >> 3 - Sair" << endl;
        sleep(1);

        cout << "Digite sua opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // Implemente a lógica para escolher uma mesa
                break;
            case 2:
                if (adm.login()) {
                    adm.adminPainel();
                } else {
                    cout << "Login inválido. Tente novamente." << endl;
                    sleep(2);
                }
                break;
            case 3:
                return 0;
            default:
                cout << "Insira um valor válido!" << endl;
                sleep(2);
                break;
        }
    } while (true);

    return opcao;
}