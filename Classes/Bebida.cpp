#include "Bebida.h"
#include <unistd.h>


void Bebida::criar() {
    int _id;
    string _nome;
    float _preco;
    int _qtdEstoque;
    float _volume;
    string _tipo;
    system("clear");
    cout << "Digite o ID da bebida: ";
    cin >> _id;
    setId(_id);

    cout << "Digite o nome da bebida: ";
    cin.ignore();
    getline(cin, _nome);
    setNome(_nome);

    cout << "Digite o preço da bebida: ";
    cin >> _preco;
    setPreco(_preco);

    cout << "Digite a quantidade em estoque da bebida: ";
    cin >> _qtdEstoque;
    setQtdEstoque(_qtdEstoque);

    cout << "Digite o volume da bebida: ";
    cin >> _volume;
    setVolume(_volume);

    cout << "Digite o tipo da bebida: ";
    cin.ignore();
    getline(cin, _tipo);
    setTipo(_tipo);

    cout << "Bebida criada com sucesso!" << endl;
    sleep(2);
}

void Bebida::ler(ifstream& arquivo) {
    arquivo >> id >> nome >> preco >> qtdEstoque >> volume >> tipo;
}

void Bebida::escrever(ofstream& arquivo) {
    arquivo << id << " " << nome << " " << preco << " " << qtdEstoque << " " << volume << " " << tipo << endl;
}

void Bebida::remover(vector<Produto*>& cardapio, const string& nomeRemover) {
    auto it = find_if(cardapio.begin(), cardapio.end(), [&nomeRemover](Produto* produto) {
        return produto->getNome() == nomeRemover;
    });

    if (it != cardapio.end()) {
        cout << "Bebida removida: " << (*it)->getNome() << endl;
        delete *it;
        cardapio.erase(it);
    } else {
        cout << "Bebida não encontrada no cardápio." << endl;
    }
}

float Bebida::getVolume() const {
    return this->volume;
}

string Bebida::getTipo() const {
    return this->tipo;
}

void Bebida::setVolume(float _volume) {
    this->volume = _volume;
}

void Bebida::setTipo(string _tipo) {
    this->tipo = _tipo;
}


void Bebida::Mostrar() const  {
        cout << "|   " << getId() << "   |   " << getNome() << "   |  R$ " << getPreco() << "  |      " << getQtdEstoque() << "      |   " << getVolume() << "ml   |   " << getTipo() << "   |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
    }


void Bebida::editar(vector<Produto*>& cardapio) {
    int opcao;
    cout << "O que deseja editar?" << endl;
    cout << "1. Nome" << endl;
    cout << "2. Preço" << endl;
    cout << "3. Quantidade em estoque" << endl;
    cout << "4. Volume" << endl;
    cout << "5. Tipo" << endl;
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Digite o novo nome: ";
            cin.ignore();
            getline(cin, nome);
            break;
        case 2:
            cout << "Digite o novo preço: ";
            cin >> preco;
            break;
        case 3:
            cout << "Digite a nova quantidade em estoque: ";
            cin >> qtdEstoque;
            break;
        case 4:
            cout << "Digite o novo volume: ";
            cin >> volume;
            break;
        case 5:
            cout << "Digite o novo tipo: ";
            cin.ignore();
            getline(cin, tipo);
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }
}