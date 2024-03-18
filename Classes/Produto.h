    #pragma once
   
    #include <string>
    #include <iostream>
    #include <vector>

    using namespace std;

    class Produto {
    protected: 
        int id;
        string nome;
        float preco;
        int qtdEstoque;

    public:
        Produto(int _id, string _nome, float _preco, int _qtdEstoque)
            : id(_id), nome(_nome), preco(_preco), qtdEstoque(_qtdEstoque) {}

        virtual ~Produto() {}

        virtual void Mostrar() const = 0;
        virtual void criar() = 0;
        virtual void ler(ifstream& arquivo) = 0;
        virtual void escrever(ofstream& arquivo) = 0;
        virtual void remover(vector<Produto*>& cardapio, const string& nomeRemover) = 0;
        virtual void editar(vector<Produto*>& cardapio) = 0;


        int getId() const;
        string getNome() const;
        float getPreco() const;
        int getQtdEstoque() const;

   
        void setId(int _id);
        void setNome(string _nome);
        void setPreco(float _preco);
        void setQtdEstoque(int _qtdEstoque);
    
    };




