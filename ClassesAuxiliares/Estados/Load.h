#pragma once
#include"Estados.h"

class Load : public Estado
{
private:
    Botao fase1;
    Botao fase2;
    Botao back;
    //Estado* 
    //Estado*
    //Estado*
public:
    Load ();
    ~Load ();
    void imprimir();
    Estado* eExecutar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma);
    void setFase(int i = 0);
    Fase* getFase();
};
