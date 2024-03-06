#ifndef MESA_H
#define MESA_H
class Mesa
{
private:
    int mesaNum;
    bool ocupada;

public:
    Mesa();
    Mesa(int mesaNum);

    bool checarMesa();
    void ocuparMesa();
    void desocuparMesa();
    int getNumeroMesa();
    
};

#endif