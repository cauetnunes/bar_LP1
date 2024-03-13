#pragma once
#include <iostream>
#include <string>

using namespace std;

class Admin
{
private:
    string const name = "cauet";
    string const senha = "123";
    
    bool autorizado = false;
public:
    Admin(){};

    int login();
    int adminPainel();



};