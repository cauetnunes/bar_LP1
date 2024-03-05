#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
#include <iostream>

using namespace std;

// CLASSE ABSTRATA QUE SERVE SÓ PARA IDEALIZAR COMIDA E BEBIDA

class Produto {
protected: // Membros protegidos para que as subclasses possam acessá-los
    int id;
    string nome;
    float preço;
    int qtdEstoque;

public:
    // Construtor com argumentos para inicializar os atributos
    Produto(int _id, string _nome, float _preço, int _qtdEstoque)
        : id(_id), nome(_nome), preço(_preço), qtdEstoque(_qtdEstoque) {}
    
    Produto();

    // Métodos CRUD virtuais puros
    virtual void criar() = 0;
    virtual void ler() const = 0;
    virtual void atualizar() = 0;
    virtual void remover() = 0;

    
    virtual ~Produto() {}
};

#endif


