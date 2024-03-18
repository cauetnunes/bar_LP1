#include "Comida.h"


void Comida::criar() {
    int _id;
    string _nome;
    float _preco;
    int _qtdEstoque;
    string _porcao;
    system("clear");

    cout << "Digite o ID da comida: ";
    cin >> _id;
    setId(_id);

    cout << "Digite o nome da comida: ";
    cin.ignore();
    getline(cin, _nome);
    setNome(_nome);

    cout << "Digite o preço da comida: ";
    cin >> _preco;
    setPreco(_preco);

    cout << "Digite a quantidade em estoque da comida: ";
    cin >> _qtdEstoque;
    setQtdEstoque(_qtdEstoque);

    cout << "Digite a porção da comida: ";
    cin.ignore();
    getline(cin, _porcao);
    setPorcao(_porcao);

    cout << "Comida criada com sucesso!" << endl;
}


void Comida::ler(ifstream& arquivo) {
    arquivo >> id >> nome >> preco >> qtdEstoque >> porcao;
}

void Comida::escrever(ofstream& arquivo) {
    arquivo << id << " " << nome << " " << preco << " " << qtdEstoque << " " << porcao << endl;
}


void Comida::remover(vector<Produto*>& cardapio, const string& nomeRemover) {
    auto it = find_if(cardapio.begin(), cardapio.end(), [&nomeRemover](Produto* produto) {
        return produto->getNome() == nomeRemover;
    });

    if (it != cardapio.end()) {
        cout << "Comida removida: " << (*it)->getNome() << endl;
        delete *it;
        cardapio.erase(it);
    } else {
        cout << "Comida não encontrada no cardápio." << endl;
    }
}

string Comida::getPorcao() const {
     return porcao; }

void Comida::setPorcao(string _porcao) { 
    porcao = _porcao; }


void Comida::Mostrar() const  {
        cout << "|   " << getId() << "   |   " << getNome() << "   |  R$ " << getPreco() << "  |      " << getQtdEstoque() << "      |   " << getPorcao() << "   |" << endl;
        cout << "----------------------------------------------------------------" << endl;
    };


void Comida::editar(vector<Produto*>& Cardapio) {
    int opcao;
    cout << "O que deseja editar?" << endl;
    cout << "1. Nome" << endl;
    cout << "2. Preço" << endl;
    cout << "3. Quantidade em estoque" << endl;
    cout << "4. Porção" << endl;
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
            cout << "Digite a nova porção: ";
            cin.ignore();
            getline(cin, porcao);
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
    }
}