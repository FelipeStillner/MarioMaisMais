#pragma once

#include"Estados.h"
class Play : public Estado
{
private:
    Botao fase1;
    Botao fase2;
    Botao load;
    Botao back;
    //Estado* 
    //Estado*
    //Estado*
public:
    Play ();
    ~Play ();
    void imprimir();
    Estado* executar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma);
    Fase* getFase();
    void setFase(int i = 0);
};
